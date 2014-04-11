*Turing Machine Simulator*
==============
**Matt Rundle & Matt Mahan**

 (Project 3, CSE30151 Spring 2014, University of Notre Dame)

**Header File Information:**

Machine.h:
  public:
		Machine();
		vector<string> 				states;
		vector<string> 				inputAlphabet;
		vector<string> 				tapeAlphabet;
		vector< vector<string> > 	transitions;
		string 						startState;
		string						acceptState;
		string						rejectState;
		
Reader.h:
  public:
		Reader();
		void print_vec(vector<string> vec);
		void read_machine(char * filename, Machine & machine);
		void read_user(vector< vector<string> > & tapes);
		
Processor.h:
  public:
		Processor();
		bool check_determinism(Machine & machine);
		void run_machine(Machine & machine, vector< vector<string> > & tapes);
