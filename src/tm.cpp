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

		Reader reader;			// Instantiate the Reader
		Processor processor;	// Instantiate the Processor
		Machine machine;		// Instantiate the Machine (simply holds data structs)

		reader.read_machine(argv[1],machine);	// Read information from machine file, store in machine

		vector< vector<string> > tapes;			// Create a 2D string vector to hold the input tapes

		// DEBUG: test to make sure we read the file correctly
		//        We can get rid of this once we're satisfied that
		//        we're correctly capturing the machine file.
		//		  Note: I think we are, just didn't want to delete yet.
		/* debug */ cout << "States read: ";
		/* debug */ reader.print_vec(machine.states);
		/* debug */ cout << endl;	
		/* debug */ cout << "Input alphabet read: ";
		/* debug */ reader.print_vec(machine.inputAlphabet);
		/* debug */ cout << endl;
		/* debug */ cout << "Tape alphabet read: ";	
		/* debug */ reader.print_vec(machine.tapeAlphabet);	
		/* debug */ cout << endl;	
		/* debug */ cout << "Transitions read: " << endl;
		/* debug */ vector< vector<string> >::iterator it;
		/* debug */ for(it = machine.transitions.begin();
		/* debug */ 	it != machine.transitions.end();
		/* debug */ 	it++){	
		/* debug */ 		reader.print_vec(*it);
		/* debug */ 		cout << endl;
		/* debug */ }
		/* debug */ cout << "Start state read: ";
		/* debug */ cout << machine.startState << endl;
		/* debug */ cout << "Accept state read: ";
		/* debug */ cout << machine.acceptState << endl;
		/* debug */ cout << "Reject state read: ";
		/* debug */ cout << machine.rejectState << endl;

		// Read tape input from the user
		reader.read_user(tapes);

		// DEBUG: test to make sure we read user input correctly
		//        We can get rid of this once we're satisfied that
		//        we're correctly capturing the machine file.
		//		  Note: I think we are, just didn't want to delete yet.
		/* debug */ cout <<  endl;
		/* debug */ cout << "Tape inputs were: " << endl;
		/* debug */ for(it = tapes.begin(); it != tapes.end(); it++){
		/* debug */ 	reader.print_vec(*it);
		/* debug */ 	cout << endl;
		/* debug */ }

	}
	return 0;
}
