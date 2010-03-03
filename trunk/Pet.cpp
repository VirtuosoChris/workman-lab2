#include "Pet.h"

Pet::Pet()
{
	this->name = "Apet";
	this->dna = "Pet";
	this->sex = "male";

	ValidateSex();
}

Pet::Pet(string name, string dna, string sex)
{
	this->name = name;
	this->dna = dna;
	this->sex = sex;

	ValidateSex();
}

string Pet::GetName()
{
	return this->name;
}

string Pet::GetDna()
{
	return this->dna;
}

string Pet::GetSex()
{
	return this->sex;
}

string Pet::MyNameIs()
{
	return this->name;
}

string Pet::MySpeciesIs()
{
	return this->dna;
}

string Pet::MySexIs()
{
	return this->sex;
}

bool Pet::IsCommandName(string command)
{
	if(command.compare("name?") == 0)
		return true;
	return false;
}

bool Pet::IsCommandSpecies(string command)
{
	if(command.compare("species?") == 0)
		return true;
	return false;
}

bool Pet::IsCommandSex(string command)
{
	if(command.compare("sex?") == 0)
		return true;
	return false;
}

bool Pet::IsSexValid(string sex)
{
	if(sex.compare("male") == 0 || sex.compare("female") == 0)
		return true;
	return false;
}

bool Pet::IsCommandValid(string command)
{
	if(IsCommandName(command))
	{
		return true;
	}
	else if(IsCommandSpecies(command))
	{
		return true;
	}
	else if(IsCommandSex(command))
	{
		return true;
	}
	return false;
}

void Pet::Perform(string command, ostream& fout, Pet& pet) throw(AppError)
{
}

void Pet::Perform(string command, ostream& fout) throw(AppError)
{
	if(IsCommandName(command))
	{
		fout << "My name is: " << MyNameIs() << endl;
	}
	else if(IsCommandSpecies(command))
	{
		fout << "My species is: " << MySpeciesIs() << endl;
	}
	else if(IsCommandSex(command))
	{
		fout << "My sex is: " << MySexIs() << endl;		
	}
	else
	{
		throw TokenError("Invalid command, name? or species? or sex? expected", "Pet::Perform(command)");
	}
}

void Pet::Extract(ifstream& fin) throw(TokenError)
{
	string opentkn, closetkn;
	fin >> opentkn;
	if( opentkn != "Pet{" )
		throw TokenError("Invalid Open Token!", "Pet::Extract(fin)");
	Get( fin ); 
	fin >> closetkn;
	if( closetkn != "}Pet" )
		throw TokenError("Invalid Close Token!", "Pet::Extract(fin)");
}

void Pet::Insert(ostream& fout)
{
	fout << "Pet{ ";
    Put( fout );
    fout << " }Pet";
}

void Pet::Get( ifstream& fin)  throw(TokenError)
{
	string label;
    fin >> label;
	if( label != "name:" )
		throw TokenError("Invalid field label, name: expected", "Pet::Get(inMgr)");
	fin >> this->name;

	fin >> label;
	if( label != "dna:" )
		throw TokenError("Invalid field label, dna: expected", "Pet::Get(inMgr)");
	fin >> this->dna;

	fin >> label;
	if( label != "sex:" )
		throw TokenError("Invalid field label, sex: expected", "Pet::Get(inMgr)");
	fin >> this->sex;

	ValidateSex();
}

void Pet::Put ( ostream& fout)
{
	fout << "name: " << this->name << " "
		<< "dna: " <<  this->dna << " "
		<< "sex: " << this->sex;
}

void Pet::ValidateSex()
{
	if(!IsSexValid(this->sex))
		throw TokenError("Invalid sex value, male or female expected", "Pet::ValidateSex(inMgr)");	
}