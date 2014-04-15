//===============================================================================//
// Matt Rundle & Matt Mahan                                                      //
// CSE 30151                                                                     //
//                                                                               //
// This is the header file for the Reader class, which is used to read in both   //
// Turing machine descriptions (from a file) as well as user input (from stdin). //
// It stores all information in data structures that are passed into its         //
// functions by reference via the Machine class; there is no local memory in     //
// this class. It is purely a functional helper class.                           //
//===============================================================================//
#ifndef READER_H
	#define READER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <boost/tokenizer.hpp>
#include "Machine.h"
using namespace std;

class Reader {
	public:
		Reader();
		void print_vec(vector<string>);
		void read_machine(char * filename, Machine &);
		void read_user(vector< vector<string> > &);
		void check_tapes(vector< vector<string> > &, vector<string>);
};

#endif
