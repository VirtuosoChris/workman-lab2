#include "Dog.h"

Dog::Dog()
{
	//
}

Dog::Dog(string Name, string Dna, string Sex) :Pet(Name,Dna = "dog",Sex){}

void Dog::Perform(string cdm, ostream& fout) throw (AppError)
{
	//
}

void Dog::Perform(string cdm, ostream& fout, Dog& dog) throw (AppError)
{
	//
}

string Dog::Bark()
{
	string bark;
	
	if (sex == "male")
		bark = "Woof";
	else
		bark = "Woof Woof";
		
	return bark;
}

Dog Dog::mate(Dog dog)
{
	//	
}

void Dog::Extract(ifstream& fin) throw (TokenError)
{
	//
}

void Dog::Insert(ostream& fout)
{
	//
}
	
void Dog::Get(ifstream& fout)
{
	//	
}

void Dog::Put(ostream& fout)
{
	//
}
