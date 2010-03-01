#ifndef _DOG
#define _DOG
#include "Pet.h"

class Dog : public Pet
{
	public:
		Dog();
		Dog(string Name, string Dna, string Sex);
		void Perform(string cdm, ostream& fout) throw (AppError);
		void Perform(string cdm, ostream& fout, Dog& dog)  throw (AppError);
		string Bark();
		Dog mate(Dog dog);
		void Extract(ifstream& fin) throw (TokenError);
		void Insert(ostream& fout);
	protected:
		void Get (ifstream& fout);
		void Put (ostream& fout);
			
};
#endif
