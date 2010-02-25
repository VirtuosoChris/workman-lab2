#ifndef _DOG_H
#define	_DOG_H

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

#include "Pet.h"

class  Dog: public Pet
{
    private:  ////data members of Dog are inherited; define only those specific to Dog

    public:  //methods
          Dog();    			                //default constructor
          Dog( string name, string dna, string sex);	//parametric constructor
          virtual ~Dog();                               // virtual destructor

          //Inspectors of Pet are inherited; define only Dog inspectors
          Perform(string); //???
          void   Extract( ifstream& fin ) throw(AppError); //Override Extractor
          void   Insert( ostream& fout ); //Override Insertor

          //Must override
          string    Bark();
          Dog   Mate(Dog);

          //Must define friends
          friend  ifstream& operator>>( ifstream& fin, Dog& obj) throw(AppError);
          friend  ostream& operator<<( ostream& fout, Dog& obj);

    protected:
          void Get();
          void Put();
};

#endif