all: td

td: testDriver.o WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o BST.h BSTNode.h
	g++ -Wall -g -o td testDriver.o WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

testDriver.o: testDriver.cpp
	g++ -Wall -g -c testDriver.cpp 
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -g -c WordPair.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -g -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -g -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -g -c EmptyDataCollectionException.cpp

clean:
	rm -f td *.o