#ifndef _CAT
#define _CAT

#include "IOMgmt.h"
#include "Pet.h"

using namespace IOMgmt;

class Cat : public Pet {
      public:
              Cat();													//Default constructor
              Cat(string name, string dna, string sex, string color);   //Parametric constructor
			  string MyColorIs();
			  string Cry();
			  bool IsCommandColor(string command);
			  bool IsCommandSpeak(string command);
			  virtual void Perform(string cmd, ostream& fout) throw(AppError);
              virtual void Extract(ifstream& fin ) throw(TokenError);	//Boundary input
              virtual void Insert( ostream& fout );						//Boundary output
		friend ifstream& operator>>(ifstream& fin, Cat& obj) throw(TokenError);
		friend ostream&  operator<<(ostream& fout, Cat& obj);

      protected:
              virtual void  Get( ifstream& fin) throw(TokenError);	//Boundary input
              virtual void  Put( ostream& fout);					//Boundary output

	  private:
			  string color;
};//Cat

#endif