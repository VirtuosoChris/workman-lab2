#ifndef _PET
#define _PET

#include "IOMgmt.h"
#include "AppError.h"
#include <vector>
using namespace IOMgmt;

class Pet {
	public:
		Pet();												//Default constructor
		Pet(string name, string dna, string sex);           //Parametric constructor

		string GetName(); /* Inspectors */
		string GetDna();
		string GetSex();

		bool IsCommandName(string command); /* helper methods */
		bool IsCommandSpecies(string command);
		bool IsCommandSex(string command);
		bool IsSexValid(string sex);

		virtual string MyNameIs(); /* virtual methods */
		virtual string MySpeciesIs();
		virtual string MySexIs();				
		virtual bool IsCommandValid(string command);
		virtual void Perform(string command, ostream& fout) throw(AppError);			//			
		virtual void Perform(string command, ostream& fout, Pet& pet) throw(AppError);
		virtual void Extract(ifstream& fin ) throw(TokenError);	//Boundary input
		virtual void Insert( ostream& fout );						//Boundary output

	friend ifstream& operator>>(ifstream& fin, Pet& obj) throw(TokenError);
	friend ostream&  operator<<(ostream& fout, Pet& obj);

	protected:
		virtual void  Get( ifstream& fin) throw(TokenError);	//Boundary input
		virtual void  Put( ostream& fout);					//Boundary output

	private:
		string name;
		string dna;
		string sex;
		void ValidateSex();
	};//Pet

#endif