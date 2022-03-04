/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Hayato Koyama
 * Date: March 3rd. 2022
 */

 #pragma once

#include "BST.h"

template <class ElementType>
class Dictionary {
	
private:

    BST<ElementType> * keyValuePairs;   

	
public:


    // Constructors and destructor:
	Dictionary();                               // Default constructor
    Dictionary(ElementType& element);           // Parameterized constructor 
    ~Dictionary();                              // Destructor 
	
// Dictionary operations:    

    // Description: get the elementCount of the dictionary.
	unsigned int getElementCount() const;
	
	// Description: Puts "newElement" into the dictionary.
	// Pre-condition: "newElement" does not already exist in the Dictionary.
    // Post- condition: newElement is successfully added to the dictionary. 
	void put(const ElementType& newElement);

	// Description: Gets "newElement" from the dictionary.
	// Pre-condition: the Dictionary must not be empty.
    // Post- condition: targetElement is successfully retrieved from the dictionary. 
    //                  if the element is not in the dictionary, return "**NOT FOUND**".
	ElementType& get(const ElementType& targetElement) const;

    // Description: Display the content in alphabetical order.
	// Pre-condition: the Dictionary must not be empty.
    void displayContent(void visit(const ElementType&)) const;
	
}; // end Dictionary

#include "Dictionary.cpp" // Including "Dictionary.cpp" (instead of copying the content of Dictionary.cpp) 
                          // is another way of creating templates.