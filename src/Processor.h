//=================================================================================//
// Matt Rundle & Matt Mahan                                                        //
// CSE 30151                                                                       //
//                                                                                 //
// This is the header file for the Processor class, which is used to simulate     //
// a Turing machine. Using information passed into it, as well as tapes of user    //
// input, the Processor class processes the input against the Turing machine,      //
// outputting intermediate steps, and ultimately reporting whether or not the      //
// user input was accepted or rejected. The Processor class is purely functional,  // 
// and exists in order to aid in hiding complexity from the main program. All data //
// is passed in by reference from the caller, there is no local memory.            //
//=================================================================================//

#ifndef PROCESSOR_H
	#define PROCESSOR_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Machine.h"
using namespace std;

class Processor {
	public:
		Processor();
		void print_vec(vector<string>);
		bool vec_is_empty(vector<string> &);
		void print_trace(vector<string> &, int, string);
		bool strvec_contains(vector<string> strvec,string target);
		bool check_determinism(Machine & machine);
		void run_machine(Machine & machine, vector< vector<string> > & tapes);
};

#endif
