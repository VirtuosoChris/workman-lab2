#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Command.h"

int main() {
	//retrieve input file & initialize up read stream
	InMgr finMgr("Enter name of Input file: ");
    ifstream& fin = finMgr.getStream();

	//retrieve output file & inititalize write stream
    OutMgr foutMgr("Enter name of Output file: ");
    ostream& fout = foutMgr.getStream();

    try
    {				
		string token;

		//remember this position
		finMgr.setFilePos();

		//read input until "END" is found
		while( fin >> token && token != "END")
		{
			UnaryCommand *unOp = new UnaryCommand();
			BinaryCommand *biOp = new BinaryCommand();

			if( token == "Command{" )
			{	
				fin >> token;
				finMgr.resetFilePos();

				if(token == "action:")
				{
					//retrieve unary command object
					finMgr >> *unOp;

					//display unary command object that was just read
					foutMgr << *unOp;
					fout << endl;

					//execute this unary command
					unOp->Execute(foutMgr);
					fout << endl;

					delete unOp;
				}
				else if(token == "pet1:")
				{
					//retrieve binary command object
					finMgr >> *biOp;

					//display binary command object that was just read
					foutMgr << *biOp;
					fout << endl;

					//execute this binary command
					biOp->Execute(foutMgr);
					fout << endl;
					
					delete biOp;
				}
				else
				{
					fout << "Unrecognizable Token in Input stream: " + token << endl;
					goto errors;
				}
			}
			else
			{
				fout << "Unrecognizable Token in Input stream: " + token << endl;
				goto errors;
			}

			Next:
				finMgr.setFilePos();
		}//while
    }
    catch(TokenError e)
    {
		fout << e.getMsg() << endl;
		fout << e.getOrigin() << endl;
    }
	catch(AppError e)
	{
		fout << e.getMsg() << endl;
		fout << e.getOrigin() << endl;
	}

errors:
    finMgr.close();
    foutMgr.close();

    return 0;
}//main