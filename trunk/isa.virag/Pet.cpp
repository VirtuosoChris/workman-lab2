#include "Pet.h"
#include <string>
#include <iostream>

Pet::Pet() 
{
	name = "Apet";
	dna = "Pet";
	sex = "male";	
}

Pet::Pet(string Name, string Dna, string Sex)
{
		name = Name;
		dna = Dna;
		sex = Sex;
}

Pet::~Pet() {}
	
void Pet::Perform( string cmd, ostream& fout ) throw (AppError)
{
	//if (true) throw AppError("apperror message");

}

void Pet::Extract(ifstream&) throw (TokenError)
{
	//
}

void Pet::Insert(ostream&)
{
	//
}

ifstream& operator>>( ifstream& fin, Pet& Obj) throw(TokenError)
{
      Obj.Extract( fin );
      return fin;
}

ostream& operator<<( ostream& fout, Pet& Obj)
{
     Obj.Insert(fout);
     return fout;
}

void Pet::Get(ifstream& fin ) throw (TokenError)
{
	//	
}

void Pet::Put(ostream& fout)
{
	//
}
