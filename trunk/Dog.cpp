
#include "Dog.h"


//data members
//          string  name;
//          string  dna;
//          string  sex;

//constructors
 Dog:: Dog()
{ //default constructor
}

Dog::Dog( string Name, string Dna, string Sex): Pet(Name, Dna == "dog", Sex)
{ //parametric constructor
}

//destructor
Dog::~Dog()
{ // virtual destructor
}

//Bark method
Dog::Bark(Dog d)
{
    cout>>"Woof";
    if(d.MySexIs() == "female")
        cout>>"Woof";
}

//Properties
void      Dog::Get()  const
{ //Property
   return;
}

void      Dog::Put()  const
{ //Property
   return;
}


//Boundary methods


void   Dog::Extract(ifstream& fin )
{
           string opentkn, closetkn;
           fin >> opentkn;
           //error check: opentkn == "Dog{"
           string label1, label2, label3;
		   //Should make the following error checks as each token is read:
			//label1 == "name:" &&
			//label2 == "dna:" &&
			//label3 == "sex:"
           fin  >> label1 >> name
                >> label2 >> dna
                >> label3 >> sex;
           fin >> closetkn;
           //error check: closetkn == "}Dog"
}//Extract




void  Dog::Insert( ostream& fout )
{
           fout << endl;
           fout << " Dog{ ";
           fout << " name: "   << Dog.MyNameIs()
                << " dna: " << Dog.MySpeciesIs()
                << " sex: "   << Dog.MySexIs();
           fout << " }Dog ";
}//Insert





//Friends
ifstream& operator>>( ifstream& fin, Dog& Obj) throw(AppError)
{
      Obj.Extract( fin );
      return fin;
}

ostream& operator<<( ostream& fout, Dog& Obj)
{
     Obj.Insert(fout);
     return fout;
}

