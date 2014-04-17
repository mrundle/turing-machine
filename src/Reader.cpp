//===============================================================================//
// Matt Rundle & Matt Mahan                                                      //
// CSE 30151                                                                     //
//                                                                               //
// This is the implementation of the Reader class, which is used to read in both //
// Turing machine descriptions (from a file) as well as user input (from stdin). //
// It stores all information in data structures that are passed into its         //
// functions by reference via the Machine class; there is no local memory in     //
// this class. It is purely a functional helper class.                           //
//===============================================================================//

#include "Reader.h"

// set typedef for tokenizer, used later to split strings (input) by commas
typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
boost::char_separator<char> sep(",");

Reader::Reader(){}

//============================================================================//
// Function -----: print_vec
// Input --------: vector<string>
// Output -------: Prints the contents of a vector separated by commas
//============================================================================//
void Reader::print_vec(vector<string> vec){
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++){
		if(it != (vec.end()-1)) cout << *it << ",";
		else cout << *it;
	}
}

//============================================================================//
// Function -----: read_machine
// Input
// Ouput -------: reads the machine description from file
//============================================================================//
void Reader::read_machine(char * filename, Machine & machine)
{

	// open readfile
	ifstream readfile;
	readfile.open(filename);

	// declare string to store input
	string line;

	// if the file is open, read line by line	
	if(readfile.is_open()){

		while(!readfile.eof()){
			
			getline(readfile,line);

			// this will determine what we're doing with the following data
			char part = line[0];

			// actually get the data by deleting the first two char's ("A:", for example)
			line.erase(0,2);

			// split the lines into tokens separated by commas
			tokenizer tokens(line,sep);
			tokenizer::iterator tok_iter;
			
			// declare a vector to store each transition (lines beginning with "T:")
			// this will later be pushed into the 2D "transitions" vector
			vector<string> transition;

			int numProvided; 	// this will be used to make sure thate we read 1 accept and 1 reject
								// state, no more and no less

			switch(part){
				case 'A': // lists the input alphabet; ex: A:0,1,2,3
					for (tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
						machine.inputAlphabet.push_back(*tok_iter);
					}
					break;
				case 'Q': // lists the set of states; ex: Q:q1,q2,q3
					for (tok_iter  = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
						machine.states.push_back(*tok_iter);
					}
					break;
				case 'Z': // lists the set of states; ex: Q:q1,q2,q3
					for (tok_iter  = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
						machine.tapeAlphabet.push_back(*tok_iter);
					}
					break;
				case 'T': // provides a single transition rule; ex: T:q1,0,q2									
					for(tok_iter  = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
						transition.push_back(*tok_iter);
					} 
					machine.transitions.push_back(transition);
					break;
				case 'S': // specifies the start state; ex: S:q1
					machine.startState = line;
					break;
				case 'F': // specifies the list of accept states; ex: F:q1,q2
					numProvided = 0;
					for (tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
						numProvided++;
						if(numProvided == 1) machine.acceptState = *tok_iter;
						if(numProvided == 2) machine.rejectState = *tok_iter;
					}
					if(numProvided < 2 || numProvided > 2) {
						cout << "tm: Incorrect formatting of accept and reject states (F:)" << endl;
						cout << "tm: Exiting" << endl; 
						exit(EXIT_FAILURE);
					}
					break;
				default:
					break;
			}
		}

	}
	else{
		cout << "tm: there was an error opening the input file.\nexiting.\n";
		exit(EXIT_FAILURE);
	}
	readfile.close();
}

//============================================================================//
// Function -----: read_user
// Input
// Ouput -------: reads tape input from the user (via stdin)
// Specification: * The first line will contain a single integer by itself
//                indicating how many tape inputs follow.
//                * If the first line contained a number 'n', then the next 'n'
//                lines will contain tape inputs, one sequence per line.
//                Each line will consist of a list of alphabe symbols possibly
//                with blank characters (but no trailing blank characters),
//                each separated by a comma. For example, if the input alphabet
//                is {0,1}, then one input line could be 0,0,1,1,0 or 1,0,1, ,1.
//                * This input should be interpreted as a beginning of an
//                infinite tape, where all characters after the last specified
//                symbol are blank, and the head should be able to move beyond
//                the last (i.e., rightmost) character of the input string.
//============================================================================//
void Reader::read_user(vector< vector<string> > & tapes)
{
	string line;   // line of input
	int num_tapes; // number of lines user will enter

	// Get the first line, tells us how many lines to read
	char num_input;
	getline(cin,line);
	num_tapes = atoi(line.c_str()); // convert to int
	
	// based on num_tapes, read next lines
	for(int i = 0; i < num_tapes; i++){
		// get user input
		getline(cin,line);
		// initialize vector to store input
		vector<string> tape;
		if(line.empty()){
			// do nothing
		}
		else{
			// split input line by commas
			tokenizer tokens(line,sep);
			// loop through these tokens and push into vector
			for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
				tape.push_back(*tok_iter);
			}
		}
		// if tape is empty, insert blank space
		if(tape.size() == 0) tape.push_back(" ");
		// finally, push the vector into the larger 2D vector
		tapes.push_back(tape);
	}
}

// Removes faulty input from tape and notifies user
void Reader::check_tapes(vector< vector<string> > & tapes, vector<string> inputAlphabet){
	for(int i = 0; i < tapes.size(); i++){
		for(int j = 0; j < tapes[i].size(); j++){
			vector<string>::iterator alphabet_el;
			bool isValid = false;
			for(alphabet_el = inputAlphabet.begin(); alphabet_el != inputAlphabet.end(); alphabet_el++){
				if(tapes[i][j] == *alphabet_el){
					isValid = true;
					break;
				}
			}
			if(!isValid){
				cout << "tm: error: invalid input \"" << tapes[i][j] << "\" on tape input." << endl;
				cout << "tm: removing from tape (and closing gap) and continuing with simulation." << endl;
				cout << "tm: original input: ";				
				print_vec(tapes[i]);
				cout << endl;
				tapes[i].erase(tapes[i].begin() + j);	// actually erase the offending element
				j--;
				cout << "tm: modified input: ";
				print_vec(tapes[i]);
				cout << endl << endl;			
			}
		}
	}
}
