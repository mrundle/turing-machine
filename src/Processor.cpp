//=================================================================================//
// Matt Rundle & Matt Mahan                                                        //
// CSE 30151                                                                       //
//                                                                                 //
// This is the implementation of the Processor class, which is used to simulate    //
// a Turing machine. Using information passed into it, as well as tapes of user    //
// input, the Processor class processes the input against the Turing machine,      //
// outputting intermediate steps, and ultimately reporting whether or not the      //
// user input was accepted or rejected. The Processor class is purely functional,  // 
// and exists in order to aid in hiding complexity from the main program. All data //
// is passed in by reference from the caller, there is no local memory.            //
//=================================================================================//

#include "Processor.h"

Processor::Processor(){}

//============================================================================//
// Function -----: print_vec
// Input --------: vector<string>
// Output -------: Prints the contents of a vector separated by commas
//============================================================================//
void Processor::print_vec(vector<string> vec){
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++){
		if(it != (vec.end()-1)) cout << *it << ",";
		else cout << *it;
	}
}

//============================================================================//
// Function -----: print_trace
// Input --------: vector<string>, string, vector<string>
// Output -------: Prints the current state of the machine
//============================================================================//
void Processor::print_trace(vector<string> & leftOfHead, 
							string & currentState, vector<string> & rightOfHead){
		cout << "(";
		print_vec(leftOfHead);
		cout << ")" << currentState << "(";
		print_vec(rightOfHead);
		cout << ")";
}

//============================================================================//
// Function -----: strvec_contains
// Input --------: vector<string>, string
// Output -------: Checks to see whether or not any states in the vector of current states
//                 matches up with any states in the vector of accepting states. Returns
//                 TRUE if so, FALSE if not.
//============================================================================//
bool Processor::strvec_contains(vector<string> strvec,string target){
	for(vector<string>::iterator el = strvec.begin(); el != strvec.end(); el++){
			if(*el == target) return true;
	}
	return false;
}

//============================================================================//
// Function -----: check_determinism
// Input --------: Machine & machine
// Output -------: Checks for determinism of a Turing machine by examining
//                 each of its state transitions. Outputs TRUE or FALSE bool
// Specification-: No two transition rules can have the same starting state
//                 and the same current tape symbol.
//============================================================================//
bool Processor::check_determinism(Machine & machine){
	vector< vector<string> >::iterator t1, t2;
	for(t1 = machine.transitions.begin(); t1 != machine.transitions.end(); t1++){
		for(t2 = machine.transitions.begin(); t2 != machine.transitions.end(); t2++){
			if(t1 == t2) continue;
			else if( ((*t1)[0] == (*t2)[0]) && ((*t1)[1] == (*t2)[1]) ) return false;
		}
	}
	return true;
}

//============================================================================//
// Function -----: check_determinism
// Input --------: Machine & machine
// Output -------: Runs Turing machine on given input, outputting steps
//                 and final state (including whether or not the machine
//                 completed after 1000 steps)
//============================================================================//
void Processor::run_machine(Machine & machine, vector< vector<string> > & tapes){
	vector< vector<string> >::iterator tape;
	for(tape = tapes.begin(); tape != tapes.end(); tape++){	
		int limit = 1000;
		bool made_transition;
		vector<string> leftOfHead;
		vector<string> rightOfHead(*tape);
		string currentState = machine.startState;
		// Print initial tracing information
		print_trace(leftOfHead,currentState,rightOfHead);
		while(limit-- > 0){
			// get input str
			string input = rightOfHead[0];

			// verify that input str is in alphabet
			if(!strvec_contains(machine.inputAlphabet,input)){
				// TODO: Handle invalid input (exit with message)
			}

			// loop through transitions to find a matching rule
			made_transition = false;
			vector< vector<string> >::iterator transition;
			for(transition = machine.transitions.begin(); transition != machine.transitions.end(); transition++){				
				if( ((*transition)[0] == currentState) && ((*transition)[1] == input)){
					made_transition = true;
					// extract further data from transition
					string resultingState = (*transition)[2];
					string symbolToWrite = (*transition)[3];
					string direction = (*transition)[4];
					// update current state
					currentState = resultingState;
					// update the tape
					if(direction == "R") leftOfHead.push_back(symbolToWrite);
					else if(direction == "L") rightOfHead.insert(rightOfHead.begin(),symbolToWrite);
					else cout << "error";
				}	
			}
			// transition to the reject state if no transition was made
			if(!made_transition) currentState = machine.rejectState;
			// break out of the processing loop if we're at a terminating state
			if((currentState == machine.acceptState) || (currentState == machine.rejectState)) break;
			
			// print tracing information
			print_trace(leftOfHead,currentState,rightOfHead);
		}

		// report results to user
		if     (currentState == machine.acceptState) cout << "ACCEPT" << endl;
		else if(currentState == machine.rejectState) cout << "REJECT" << endl;
		else cout << "DID NOT HALT" << endl;
	}
}
