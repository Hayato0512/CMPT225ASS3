all: translate

translate: WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o BST.h BSTNode.h Dictionary.h Translator.o 
	g++ -Wall -g -o trans Translator.o WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

Translator.o: Translator.cpp
	g++ -Wall -g -c Translator.cpp
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -g -c WordPair.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -g -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -g -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -g  -c EmptyDataCollectionException.cpp

clean:
	rm -f translate *.o