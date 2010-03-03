#ifndef _DOG
#define _DOG

#include "IOMgmt.h"
#include "Pet.h"

using namespace IOMgmt;

class Dog : public Pet {
      public:
              Dog();												//Default constructor
              Dog(string name, string dna, string sex);             //Parametric constructor			  
			  string Bark();
			  Dog& Mate(Pet& partner) throw(AppError);
			  virtual bool IsCommandSpeak(string command);
			  virtual bool IsCommandMate(string command);
			  virtual void Perform(string command, ostream& fout) throw(AppError);
		      virtual void Perform(string command, ostream& fout, Pet& pet) throw(AppError);
              virtual void Extract(ifstream& fin ) throw(TokenError);	//Boundary input
              virtual void Insert( ostream& fout );						//Boundary output

      protected:
              virtual void  Get( ifstream& fin) throw(TokenError);	//Boundary input
              virtual void  Put( ostream& fout);					//Boundary output
};//Dog

#endif