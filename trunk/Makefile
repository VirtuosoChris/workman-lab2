CC=g++
CFLAGS=-c

PetApp: Pet.o Cat.o Dog.o AppError.o IOMgmt.o Command.o PetApp.o
	$(CC) Pet.o Cat.o Dog.o AppError.o IOMgmt.o Command.o PetApp.o -o PetApp

Pet.o: Pet.cpp Pet.h IOMgmt.h AppError.h
	$(CC) $(CFLAGS)  Pet.cpp

Cat.o: Cat.cpp Cat.h Pet.h IOMgmt.h
	$(CC) $(CFLAGS) Cat.cpp

Dog.o: Dog.cpp Dog.h Pet.h IOMgmt.h
	$(CC) $(CFLAGS) Dog.cpp

AppError.o: AppError.cpp AppError.h
	$(CC) $(CFLAGS) AppError.cpp

IOMgmt.o: IOMgmt.cpp IOMgmt.h AppError.h
	$(CC) $(CFLAGS) IOMgmt.cpp

Command.o: Command.cpp Command.h IOMgmt.h
	$(CC) $(CFLAGS) Command.cpp

PetApp.o: PetApp.cpp Command.h
	$(CC) $(CFLAGS) PetApp.cpp

clean:
	rm -r Pet.o Cat.o Dog.o AppErro.o IOMgmt.o Command.o PetApp.o
