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
// Function -----: check_determinism
// Input --------: Machine & machine
// Output -------: Checks for determinism of a Turing machine by examining
//                 each of its state transitions
//============================================================================//
bool Processor::check_determinism(Machine & machine){
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
	cout << "running machine..." << endl;
}
