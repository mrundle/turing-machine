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
