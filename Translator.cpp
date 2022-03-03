/*
 * Translator.cpp
 * 
 * Description: Translator application using Dictionary classes(ADT).
 *              User should not know what kind of data structure is used. 
 *
 * Author: Hayato Koyama
 * Last Modification Date: Feb. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "WordPair.h"
#include "BST.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "Dictionary.h"

//initially like this void display(const WordPair& anElement)
void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display



int main(int argc, char *argv[]) {

    void (*fun_ptr)(const WordPair&) = &display;
 



    

    Dictionary<WordPair>* testing = new Dictionary<WordPair>();
    
     
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "dataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  
  ifstream myfile (filename);
  if (myfile.is_open()) {
  	cout << "Reading from a file:" << endl; 
    while ( getline (myfile,aLine) )
    {
       pos = aLine.find(delimiter);
       englishW = aLine.substr(0, pos);
       //cout<<englishW<<endl;
       aLine.erase(0, pos + delimiter.length());
       translationW = aLine;
       WordPair aWordPair(englishW, translationW);
       //cout<<aWordPair<<endl;
       try {
            testing->put(aWordPair);
        }
        catch ( ElementAlreadyExistsException&anException ) {
            //cout<<"detected exception because "<< anException.what()<<endl;
        }
        //cout<<"testing element Count is "<<testing->getElementCount()<<endl;
	   // insert aWordPair into "testing" using a try/catch block
    }
    myfile.close();
    cout<<endl<<endl<<endl<<endl;
    // testing->displayContent((*fun_ptr));
    

    // If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) ) {
        // ... then display the content of the BST.
        cout<<"Ok, this display section is currently under construction"<<endl;
    }
    else if (argc == 1) {//no argument
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {   

          WordPair aWordPair(aWord);
          //search this word in the testing BST, if a word is found as a substring, then retrieve that element
          try{
               WordPair result = testing->get(aWordPair.getEnglish());
                cout<<endl<< result<<endl;
          }
          catch(ElementDoesNotExistException&anException){
              cout<<"**NOT FOUND**"<<endl;
          }
         
         
          // and pring the element.
          // retrieve aWordPair from "testing" using a try/catch block
		  // print aWordPair

       }
    }
    delete testing;
  }
  else 
    cout << "Unable to open file"; 
  
  
  return 0;
}