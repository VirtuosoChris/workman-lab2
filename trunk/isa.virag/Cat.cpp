#include "Cat.h"

Cat::Cat(){}

Cat::Cat(string Name, string Dna, string Sex, string Color) :Pet(Name,Dna,Sex), color(Color){}

void Cat::Perform(string cdm, ostream& fout)
{
	//
}

string Cat::Cry()
{
	string cry= "Meow";
	return cry;
}

string Cat::MyColorIs()
{
	return color;
}

void Cat::Extract(ifstream&) throw (AppError)
{
	//
}

void Cat::Insert(ostream&)
{
	//
}
	
void Cat::Get(ifstream&) throw (AppError)
{
	//	
}

void Cat::Put(ostream&)
{
	//
}
