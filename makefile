#MakeFile created by automake-OvenVan

BIN	= contact.exe
CC	= gcc
CFLAG	= -g3 -Wall -static-libgcc =std=c++11
CXX	= g++
CXXFLAG	= -g3 -Wall -static-libgcc -std=c++11 -lstdc++
OBJ	= CheckInterface.o Contact.o ContactInterface.o MainDelMenu.o MainMdfMenu.o MainNewMenu.o MainStrategy.o MainTestMenu.o MainVewMenu.o MainVewMenuInterface.o Person.o PrtMenuInterface.o StdAfx.o ViewAllMenu.o ViewCategoryMenu.o ViewExactMenu.o ViewFuzzyMenu.o ViewStrategy.o main.o 

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN)

CheckInterface.o: CheckInterface.cpp
	$(CC) -c CheckInterface.cpp -o CheckInterface.o $(CXXFLAG)

Contact.o: Contact.cpp
	$(CC) -c Contact.cpp -o Contact.o $(CXXFLAG)

ContactInterface.o: ContactInterface.cpp
	$(CC) -c ContactInterface.cpp -o ContactInterface.o $(CXXFLAG)

MainDelMenu.o: MainDelMenu.cpp
	$(CC) -c MainDelMenu.cpp -o MainDelMenu.o $(CXXFLAG)

MainMdfMenu.o: MainMdfMenu.cpp
	$(CC) -c MainMdfMenu.cpp -o MainMdfMenu.o $(CXXFLAG)

MainNewMenu.o: MainNewMenu.cpp
	$(CC) -c MainNewMenu.cpp -o MainNewMenu.o $(CXXFLAG)

MainStrategy.o: MainStrategy.cpp
	$(CC) -c MainStrategy.cpp -o MainStrategy.o $(CXXFLAG)

MainTestMenu.o: MainTestMenu.cpp
	$(CC) -c MainTestMenu.cpp -o MainTestMenu.o $(CXXFLAG)

MainVewMenu.o: MainVewMenu.cpp
	$(CC) -c MainVewMenu.cpp -o MainVewMenu.o $(CXXFLAG)

MainVewMenuInterface.o: MainVewMenuInterface.cpp
	$(CC) -c MainVewMenuInterface.cpp -o MainVewMenuInterface.o $(CXXFLAG)

Person.o: Person.cpp
	$(CC) -c Person.cpp -o Person.o $(CXXFLAG)

PrtMenuInterface.o: PrtMenuInterface.cpp
	$(CC) -c PrtMenuInterface.cpp -o PrtMenuInterface.o $(CXXFLAG)

StdAfx.o: StdAfx.cpp
	$(CC) -c StdAfx.cpp -o StdAfx.o $(CXXFLAG)

ViewAllMenu.o: ViewAllMenu.cpp
	$(CC) -c ViewAllMenu.cpp -o ViewAllMenu.o $(CXXFLAG)

ViewCategoryMenu.o: ViewCategoryMenu.cpp
	$(CC) -c ViewCategoryMenu.cpp -o ViewCategoryMenu.o $(CXXFLAG)

ViewExactMenu.o: ViewExactMenu.cpp
	$(CC) -c ViewExactMenu.cpp -o ViewExactMenu.o $(CXXFLAG)

ViewFuzzyMenu.o: ViewFuzzyMenu.cpp
	$(CC) -c ViewFuzzyMenu.cpp -o ViewFuzzyMenu.o $(CXXFLAG)

ViewStrategy.o: ViewStrategy.cpp
	$(CC) -c ViewStrategy.cpp -o ViewStrategy.o $(CXXFLAG)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o $(CXXFLAG)

