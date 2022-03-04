/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Hayato Koyama
 * Date: March 3rd. 2022
 */
#include "Dictionary.h"
#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

//Constructor
template <class ElementType>
Dictionary<ElementType>::Dictionary()
{   keyValuePairs = new BST<ElementType>;

}

//Destructor
template <class ElementType>
Dictionary<ElementType>::~Dictionary()
{
    delete keyValuePairs;
}

// Description: get the elementCount of the dictionary.
template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{   
    unsigned int ret = keyValuePairs->getElementCount();
    
    return ret;
    
}

// Description: Puts "newElement" into the dictionary.
// Pre-condition: "newElement" does not already exist in the Dictionary.
// Post- condition: newElement is successfully added to the dictionary.
template <class ElementType>
void Dictionary<ElementType>::put(const ElementType& newElement)
{   //call insert from BST class
    keyValuePairs->insert(newElement);

}


// Description: Gets "newElement" from the dictionary.
// Pre-condition: the Dictionary must not be empty.
// Post- condition: targetElement is successfully retrieved from the dictionary. 
//                  if the element is not in the dictionary, return "**NOT FOUND**".
template <class ElementType>
ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const
{   //call retrieve() from the BST class
    ElementType& translated = keyValuePairs->retrieve(targetElement);
    return translated;
}


// Description: Display the content in alphabetical order.
// Pre-condition: the Dictionary must not be empty.
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const{
    //call traverseInOrder() from the BST class
    keyValuePairs->traverseInOrder(visit);
}