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
using namespace std;

class Processor {
	public:
		Processor();
};

#endif
