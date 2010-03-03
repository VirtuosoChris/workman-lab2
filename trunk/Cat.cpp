#include "Cat.h"

Cat::Cat() : Pet()
{
	color = "black";
}

Cat::Cat(string name, string dna, string sex, string color)
	: Pet(name, dna, sex), color(color)
{
}

string Cat::Cry()
{
	return "Meow";
}

bool Cat::IsCommandSpeak(string command)
{
	if(command == "speak!")
		return true;
	return false;
}

bool Cat::IsCommandColor(string command)
{
	if(command == "color?")
		return true;
	return false;
}

string Cat::MyColorIs()
{
	return this->color;
}

void Cat::Perform(string command, ostream& fout) throw(AppError)
{
	if(IsCommandSpeak(command))
	{
		fout << "My cry is: " << Cry() << endl;
	}
	else if(IsCommandColor(command))
	{
		fout << "My color is: " << MyColorIs() << endl;
	}
	else
	{
		Pet::Perform(command, fout);
	}
}

void Cat::Extract(ifstream& fin) throw(TokenError)
{
	string opentkn, closetkn;
	fin >> opentkn;
	if( opentkn != "Cat{" )
		throw TokenError("Invalid Open Token!", "Cat::Extract(fin)");
	Get( fin ); 
	fin >> closetkn;
	if( closetkn != "}Cat" )
		throw TokenError("Invalid Close Token!", "Cat::Extract(fin)");
}

void Cat::Insert(ostream& fout)
{
	fout << "Cat{ ";
    Put( fout );
    fout << " }Cat";
}

void Cat::Get( ifstream& fin)  throw(TokenError)
{
	Pet::Get(fin);
	string label;
	fin >> label;
	if(label != "color:")
	{
		throw TokenError("Invalid field label, color: expected", "Cat::Get(1)");
	}
	
	fin >> this->color;
}

void Cat::Put ( ostream& fout)
{
	Pet::Put(fout);
}