#include <iostream>
#include "Reader.h"
#include "Processor.h"
#include "Machine.h"
#include <vector>
#include <string>
using namespace std;

// We can get rid of this once we're satisfied that
// we're correctly capturing the machine file and user input correctly.
// Note: I think we are, just didn't want to delete yet.
void debug(Reader & reader, Machine & machine, vector< vector<string> > & tapes){
	// DEBUG: test to make sure we read the file correctly
	cout << "States read: ";
	reader.print_vec(machine.states);
	cout << endl;	
	cout << "Input alphabet read: ";
	reader.print_vec(machine.inputAlphabet);
	cout << endl;
	cout << "Tape alphabet read: ";	
	reader.print_vec(machine.tapeAlphabet);	
	cout << endl;	
	cout << "Transitions read: " << endl;
	vector< vector<string> >::iterator it;
	for(it = machine.transitions.begin();
		it != machine.transitions.end();
		it++){	
			reader.print_vec(*it);
			cout << endl;
		}
	cout << "Start state read: ";
	cout << machine.startState << endl;
	cout << "Accept state read: ";
	cout << machine.acceptState << endl;
	cout << "Reject state read: ";

	// DEBUG: test to make sure we read user input correctly
	cout <<  endl;
	cout << "Tape inputs were: " << endl;
	for(it = tapes.begin(); it != tapes.end(); it++){
		reader.print_vec(*it);
		cout << endl;
	}
}

int main(int argc, char* argv[])
{

	if(argc != 2) cout << "tm: error, wrong number of arguments\nusage: ./tm <tm1.txt>" << endl;
	else{

		Reader reader;								// Instantiate the Reader
		Processor processor;						// Instantiate the Processor
		Machine machine;							// Instantiate the Machine (simply holds data structs)
		vector< vector<string> > tapes;				// Create a 2D string vector to hold the input tapes

		reader.read_machine(argv[1],machine);		// Read information from machine file, store in machine

		if(!processor.check_determinism(machine)){ 	// TODO: check_determinism(machine) function is currently incomplete

			cout << "tm: the provided machine description provides transitions that lead to a nondeterministic machine." << endl;
			cout << "tm: this program is meant to simulate deterministic Turing machines." << endl;
			cout << "tm: exiting..." << endl;

		}
		else{

			reader.read_user(tapes);				// Read tape input from the user
			debug(reader,machine,tapes); 			// see if we got the right information
			processor.run_machine(machine,tapes);	// TODO: run_machine(machine,tapes) function is currently incomplete
		}

	}

	return 0;

}
