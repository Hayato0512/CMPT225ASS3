/*
 * Translator.cpp
 * 
 * Description: Translator application using Dictionary classes(ADT).
 *              User should not know what kind of data structure is used. 
 *
 * Author: Hayato Koyama
 * Last Modification Date: March 3rd. 2022
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
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "Dictionary.h"

//description : desplay the content of anElement.
//              will be passed as an argument when needed.
void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display



int main(int argc, char *argv[]) {

  //initiate the function pointer that points display() to pass it to a function.
  void (*fun_ptr)(const WordPair&) = &display;
 
  Dictionary<WordPair>* dict = new Dictionary<WordPair>();
    
     
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  //read texts from the file myDataFile.text
  ifstream myfile (filename);
  if (myfile.is_open()) {

    while ( getline (myfile,aLine) )
    { 
       pos = aLine.find(delimiter);
       //get the english word first
       englishW = aLine.substr(0, pos);
       aLine.erase(0, pos + delimiter.length());
       //get the translation next
       translationW = aLine;
       //make a WordPair object with obtained english and translation.
       WordPair aWordPair(englishW, translationW);
       //try/catch mechanism. when the dictionary already has the input element, it throw an exception
       //to prevent duplicate elements.
       try {
            dict->put(aWordPair);
        }
        catch ( ElementAlreadyExistsException&anException ) {
            //cout<<"detected exception because "<< anException.what()<<endl;
        }
    }
    myfile.close();
    
    // If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "display") == 0) ) {
        // ... then display the contents of the dictionary.
        dict->displayContent(*fun_ptr);
    }
    else if (argc == 1) {//if no argument, 
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {   

          //if user input "Display", display all the contents in ascending order.
          if(aWord=="display"){
            dict->displayContent(*fun_ptr);
          }
          else{
            //initiate WordPair object with the english that user entered.
            WordPair aWordPair(aWord);
            //search this word in the testing BST, if a word is found as a substring, then retrieve that element
            try{
                WordPair result = dict->get(aWordPair.getEnglish());
                cout<<endl<< result<<endl;
            } 
            //if not found, print "**NOT FOUND**".
            catch(ElementDoesNotExistException&anException){
              cout<<"**NOT FOUND**"<<endl;
            }
          }
         

       }
    }
    //free the allocated dictionary object at the end.
    delete dict;
  }
  else 
    cout << "Unable to open file"; 
  
  
  return 0;
}