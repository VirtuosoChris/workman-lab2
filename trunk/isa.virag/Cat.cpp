#include "Cat.h"

Cat::Cat(){}

Cat::Cat(string Name, string Dna, string Sex, string Color) :Pet(Name,Dna = "Cat",Sex), color(Color){}

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

void Cat::Extract(ifstream& fin) throw (AppError)
{
	//
}

void Cat::Insert(ostream& fout)
{
	//
}
	
void Cat::Get(ifstream& fin) throw (AppError)
{
	//	
}

void Cat::Put(ostream& fout)
{
	//
}
