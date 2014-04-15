//=================================================================================//
// Matt Rundle & Matt Mahan                                                        //
// CSE 30151                                                                       //
//                                                                                 //
// This is the main file for the "tm" Turing Machine program. The purpose of this  //
// main function is to instantiate the various different classes (Machine,         //
// Reader, and Processor) and to call their respective functions.                  //
//=================================================================================//

#include <iostream>
#include "Reader.h"
#include "Processor.h"
#include "Machine.h"
#include <vector>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2) cout << "tm: error, wrong number of arguments\nusage: ./tm <tm1.txt>" << endl;
	else{
		Reader reader;								// Instantiate the Reader
		Processor processor;						// Instantiate the Processor
		Machine machine;							// Instantiate the Machine (simply holds data structs)
		vector< vector<string> > tapes;				// Create a 2D string vector to hold the input tapes
		reader.read_machine(argv[1],machine);		// Read information from machine file, store in machine
		if(!processor.check_determinism(machine)){ 	// Check to ensure that the machine is deterministic
			cout << "tm: the provided machine description provides transitions that lead to a nondeterministic machine." << endl;
			cout << "tm: this program is meant to simulate deterministic Turing machines." << endl;
			cout << "tm: exiting..." << endl;
		}
		else{
			reader.read_user(tapes);				// Read tape input from the user
			reader.check_tapes(tapes,machine.inputAlphabet);	// Check to make sure tapes consist of elements of inputAlphabet
			processor.run_machine(machine,tapes);	// Process the machine on each of the tapes
		}
	}
	return 0;
}
