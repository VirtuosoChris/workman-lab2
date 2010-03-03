#include "Command.h"

Command::Command()
{
}

Command::~Command()
{
}

Command::Command(InMgr& inMgr)
{
	Extract(inMgr);
}

string Command::GetCommand()
{
	return this->command;
}

void Command::Execute(OutMgr& outMgr)
{
}

void Command::Extract(InMgr& inMgr) throw(TokenError)
{
	string opentkn, closetkn;
	ifstream& fin = inMgr.getStream();
	fin >> opentkn;
	if( opentkn != "Command{" )
		throw TokenError("Invalid Open Token!", "Command::Extract(fin)");
	Get( inMgr ); 
	fin >> closetkn;
	if( closetkn != "}Command" )
		throw TokenError("Invalid Close Token!", "Command::Extract(fin)");
}

void Command::Insert(OutMgr& outMgr)
{
	ostream& fout = outMgr.getStream();
	fout << "Command{ ";
    Put( outMgr );
    fout << " }Command";
}

void Command::Get(InMgr& inMgr) throw(TokenError)
{
	ifstream& fin = inMgr.getStream();

	string label;
    fin  >> label;
	if( label != "action:" )
		throw TokenError("Invalid field label, action: expected", "Command::Get(inMgr)");

	fin >> this->command;
}

void  Command::Put(OutMgr& outMgr)
{
	ostream& fout = outMgr.getStream();
	fout << "action: " << this->command;
}

//FRIENDS
InMgr& operator>>(InMgr& inMgr, Command& obj) throw(TokenError)
{
	obj.Extract(inMgr);
	return inMgr;
}

OutMgr& operator<<(OutMgr& outMgr, Command& obj)
{
	obj.Insert(outMgr);
	return outMgr;
}


/* 
BEGIN Unary Class 
*/
UnaryCommand::UnaryCommand() : Command()
{
	this->pet = NULL;
}

UnaryCommand::UnaryCommand(InMgr& inMgr) : Command(inMgr)
{
	this->pet = NULL;
}

UnaryCommand::~UnaryCommand()
{
	delete this->pet;
}

Pet* UnaryCommand::GetPet()
{
	return this->pet;
}

void UnaryCommand::Execute(OutMgr& outMgr) throw(AppError)
{
	this->pet->Perform(this->GetCommand(), outMgr.getStream());
}

void UnaryCommand::Extract(InMgr& inMgr) throw(TokenError)
{
	Command::Extract(inMgr);
}

void UnaryCommand::Insert(OutMgr& outMgr)
{
	Command::Insert(outMgr);
}

void UnaryCommand::Get( InMgr& inMgr) throw(TokenError)
{
	//read in action command
	Command::Get(inMgr);

	ifstream& fin = inMgr.getStream();
	string token;
	fin  >> token;	   
	if(token != "pet1:")
	{
		throw TokenError("Invalid field label, pet1: expected", "UnaryCommand:Get(inMgr)");
	}

	inMgr.setFilePos();
	fin >> token;
	inMgr.resetFilePos();
	if(token == "Pet{")
	{
		this->pet = new Pet();
		this->pet->Extract(fin);
	}
	else if(token == "Dog{")
	{
		 Dog  *dog = new Dog();
		 dog->Extract(fin);
		 this->pet = dog;
	}		 
	else if(token == "Cat{")
	{
		 Cat *cat = new Cat();
		 cat->Extract(fin);
		 this->pet = cat;
	}
	else
	{
		throw TokenError("Invalid field label, Pet{ or Dog{ or Cat{ expected", "UnaryCommand:Get(inMgr)");
	}
 }

void UnaryCommand::Put(OutMgr& outMgr)
{
	Command::Put(outMgr);
	ostream& fout = outMgr.getStream();
	fout << " ";
	this->pet->Insert(fout);
}

/* END Unary Class */



/* 
BEGIN Binary Class 
*/
BinaryCommand::BinaryCommand() : Command()
{
	this->pet1 = NULL;
	this->pet2 = NULL;
}

BinaryCommand::~BinaryCommand()
{
	delete this->pet1;
	delete this->pet2;
}


BinaryCommand::BinaryCommand(InMgr& inMgr) : Command(inMgr)
{
}

Pet* BinaryCommand::GetPet1()
{
	return this->pet1;
}

Pet* BinaryCommand::GetPet2()
{
	return this->pet2;
}


void BinaryCommand::Execute(OutMgr& outMgr) throw(AppError)
{
	this->pet1->Perform(this->GetCommand(), outMgr.getStream(), *pet2);
}

void BinaryCommand::Extract(InMgr& inMgr) throw(TokenError)
{
	Command::Extract(inMgr);
}

void BinaryCommand::Insert(OutMgr& outMgr)
{
	Command::Insert(outMgr);
}

void BinaryCommand::Get( InMgr& inMgr) throw(TokenError)
{
	ifstream& fin = inMgr.getStream();
	string token;
	fin  >> token;	   
	if(token != "pet1:")
	{
		throw TokenError("Invalid field label, pet1: expected", "BinaryCommand:Get(1)");
	}

	inMgr.setFilePos();
	fin >> token;
	inMgr.resetFilePos();
	if(token == "Dog{")
	{
		 Dog  *dog1 = new Dog();
		 dog1->Extract(fin);
		 this->pet1 = dog1;

		 //read in action command
		 Command::Get(inMgr);

		 fin >> token;
		 if(token != "pet2:")
	 	 {
			throw TokenError("Invalid field label, pet2: expected", "BinaryCommand:Get(2)");
		 }

		 inMgr.setFilePos();
		 fin >> token;
		 inMgr.resetFilePos();
		 if(token == "Dog{")
		 {
			 inMgr.resetFilePos();
			 Dog  *dog2 = new Dog();
			 dog2->Extract(fin);
			 this->pet2 = dog2;
		 }
		 else
		 {
			 throw TokenError("Invalid Pet Instance, Dog{ expected", "BinaryCommand:Get(3)");
		 }
	}		 
	else
	{
		throw TokenError("Invalid Pet Instance, Dog{ expected", "BinaryCommand:Get(4)");
	}
 }

void BinaryCommand::Put(OutMgr& outMgr)
{	
	ostream& fout = outMgr.getStream();
	fout << "pet1: ";
	this->pet1->Insert(fout);
	fout << " ";
	Command::Put(outMgr);
	fout << " ";
	fout << "pet2: ";
	this->pet2->Insert(fout);
}

/* END Binary Class */