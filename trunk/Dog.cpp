#include "Dog.h"

Dog::Dog() : Pet()
{
}

Dog::Dog(string name, string dna, string sex)
	: Pet(name, dna, sex)
{
}

string Dog::Bark()
{
	if(this->GetSex() == "male")
	{
		return "Woof";
	}
	else if(this->GetSex() == "female")
	{
		return "Woof Woof";
	}
}

Dog& Dog::Mate(Pet& partner) throw(AppError)
{
	if(
		/* Ensure both dog species are dog */
		(this->GetDna() != "dog" || partner.GetDna() != "dog")

		||

		/* Ensure male->female OR female->male are mating*/
		((this->GetSex() == "male" && partner.GetSex() != "female")
		|| 
		(this->GetSex() == "female" && partner.GetSex() != "male")))
	{
		throw AppError("Couple cannot mate, expects dog species and male-female couple",
			"Dog::Mate(partner)");
	}

	Dog *dog = new Dog(this->MyNameIs() + "+" + partner.MyNameIs(), "dog", this->MySexIs());
	return *dog;
}

bool Dog::IsCommandSpeak(string command)
{
	if(command == "speak!")
		return true;
	return false;
}

bool Dog::IsCommandMate(string command)
{
	if(command == "mate!")
		return true;
	return false;
}

void Dog::Perform(string command, ostream& fout) throw(AppError)
{
	if(IsCommandSpeak(command))
	{
		fout << "My bark is: " << Bark() << endl;
	}
	else
	{
		Pet::Perform(command, fout);
	}
}

void Dog::Perform(string command, ostream& fout, Pet& pet)
{
	if(IsCommandMate(command))
	{
		Dog& offspring = Mate(pet);
		fout << "The offspring is: ";
		offspring.Insert(fout);
		fout << endl;
	}
	else
	{
		throw AppError("Invalid binary operation, mate? expected", "Dog::Perform(command, fout, dog");
	}
}

void Dog::Extract(ifstream& fin) throw(TokenError)
{
	string opentkn, closetkn;
	fin >> opentkn;
	if( opentkn != "Dog{" )
		throw TokenError("Invalid Open Token!", "Dog::Extract(fin)");
	Get( fin ); 
	fin >> closetkn;
	if( closetkn != "}Dog" )
		throw TokenError("Invalid Close Token!", "Dog::Extract(fin)");
}

void Dog::Insert(ostream& fout)
{
	fout << "Dog{ ";
    Put( fout );
    fout << " }Dog";
}

void Dog::Get( ifstream& fin)  throw(TokenError)
{
	Pet::Get(fin);
}

void Dog::Put ( ostream& fout)
{
	Pet::Put(fout);
}