#ifndef _COMMAND
#define _COMMAND

#include "IOMgmt.h"
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"

using namespace IOMgmt;

class Command {
	public:
		Command();													//Default constructor
		~Command();
		Command(InMgr& inMgr);										//Boundary constructor
		string GetCommand(); 										//Inspector
	    virtual void Execute(OutMgr& outMgr) throw(AppError);   //Executes desired command		
		virtual void Extract(InMgr& inMgr) throw(TokenError);		//Boundary input
		virtual void Insert(OutMgr& outMgr);						//Boundary output

	friend InMgr& operator>>(InMgr& inMgr, Command& obj) throw(TokenError);
	friend OutMgr& operator<<(OutMgr& outMgr, Command& obj);

	protected:
		virtual void  Get(InMgr& inMgr) throw(TokenError);	//Boundary input
		virtual void  Put(OutMgr& outMgr)				 ;	//Boundary output

	private:
		string command;
};//Command

class UnaryCommand : public Command
{
	public:
		UnaryCommand();
		~UnaryCommand();
		UnaryCommand(InMgr& inMgr);
		//GetCommand() is inherited
		Pet* GetPet();
		virtual void Execute(OutMgr& outMgr) throw(AppError);   //Executes desired command		
		virtual void Extract(InMgr& inMgr) throw(TokenError);		//Boundary input
		virtual void Insert(OutMgr& outMgr);						//Boundary output

	protected:
		virtual void  Get(InMgr& inMgr) throw(TokenError);	//Boundary input
		virtual void  Put(OutMgr& outMgr)				 ;	//Boundary output

	private:
		Pet* pet;
};

class BinaryCommand : public Command
{
	public:
		BinaryCommand();
		~BinaryCommand();
		BinaryCommand(InMgr& inMgr);
		//GetCommand() is inherited
		Pet* GetPet1();
		Pet* GetPet2();
		virtual void Execute(OutMgr& outMgr) throw(AppError);   //Executes desired command		
		virtual void Extract(InMgr& inMgr) throw(TokenError);	//Boundary input
		virtual void Insert(OutMgr& outMgr);					//Boundary output

	protected:
		virtual void  Get(InMgr& inMgr) throw(TokenError);	//Boundary input
		virtual void  Put(OutMgr& outMgr);				 ;	//Boundary output

	private:
		Pet* pet1;
		Pet* pet2;
};
#endif