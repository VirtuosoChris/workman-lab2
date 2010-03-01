#ifndef _CAT
#define _CAT
#include "Pet.h"

class Cat : public Pet
{
	public:
		Cat();
		Cat(string Name, string Dna, string Sex, string Color);
		void Perform(string cdm, ostream& fout);
		string MyColorIs();
		string Cry();
		void Extract(ifstream& fin) throw (AppError);
		void Insert(ostream&);
	protected:
		void Get (ifstream&) throw (AppError);
		void Put (ostream&);
		
	private:
		string color;
			
};
#endif
