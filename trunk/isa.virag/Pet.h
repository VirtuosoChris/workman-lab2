#ifndef _PET
#define _PET
#include <string>
#include <iostream>
#include <fstream>
#include "IOMgmt.h"

using namespace IOMgmt;

class Pet
{

	public:	
		Pet();
		Pet(string pname, string pdna, string psex);
		~Pet();	
		void Perform( string cmd, ostream& fout ) throw (AppError);
		string MyNameIs() const { return name; };
		string MySpeciesIs() const { return dna; };
		string MySexIs() const { return sex; };
		void Extract (ifstream&) throw (TokenError);
		void Insert (ostream&);
		friend  ifstream& operator>>( ifstream& fin, Pet& obj) throw(TokenError);
        friend  ostream& operator<<( ostream& fout, Pet& obj);
        
        string name;
		string dna;
		string sex;
        
	protected:
		void Get (ifstream&) throw (TokenError);
		void Put (ostream&);
		
		
	
};
#endif
