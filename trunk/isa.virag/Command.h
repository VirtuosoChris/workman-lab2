#ifndef _CMD
#define _CMD

#include <iostream>
#include <fstream>
#include "IOMgmt.h"


using namespace IOMgmt;

class Command
{
	public:
		Command();
		Command(ifstream&);	
		void Execute (ostream& fout) throw (AppError);
		void Extract (ifstream& fin) throw (TokenError);
		void Insert (ostream& fout);
		friend  ifstream& operator>>( ifstream& fin, Command& obj) throw(TokenError);
        friend  ostream& operator<<( ostream& fout, Command& obj);
        
    protected:
		void Get (ifstream& fin) throw (TokenError);
		void Put (ostream& fout);
	
};
#endif
