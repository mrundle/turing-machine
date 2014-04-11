//=================================================================================//
// Matt Rundle & Matt Mahan                                                        //
// CSE 30151                                                                       //
//                                                                                 //
// This is the header file for the Machine class. Currently, the class consists    //
// only of various string data structures, and does not have any public or         //
// private functions.
//=================================================================================//

#ifndef MACHINE_H
	#define MACHINE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Machine {
	public:
		// Constructor
		Machine();
		vector<string> 				states;
		vector<string> 				inputAlphabet;
		vector<string> 				tapeAlphabet;
		vector< vector<string> > 	transitions;
		string 						startState;
		string						acceptState;
		string						rejectState;
};

#endif
