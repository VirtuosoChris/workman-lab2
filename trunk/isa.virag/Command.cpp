#include "Command.h"

Command::Command(){}
		
Command::Command(ifstream& fin)
{
	//	
}	

void Command::Execute (ostream& fout) throw (AppError)
{
	//
}

void Command::Extract (ifstream& fin) throw (TokenError)
{
	//
}
void Command::Insert (ostream& fout)
{
	//
}

ifstream& operator>>( ifstream& fin, Command& Obj) throw(TokenError)
{
      Obj.Extract( fin );
      return fin;
}

ostream& operator<<( ostream& fout, Command& Obj)
{
     Obj.Insert(fout);
     return fout;
}

void Command::Get (ifstream& fin) throw (TokenError)
{
	//
}
void Command::Put (ostream& fout)
{
	//
}
