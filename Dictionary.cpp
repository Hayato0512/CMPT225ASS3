#include "Dictionary.h"
#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

template <class ElementType>
Dictionary<ElementType>::Dictionary()
{   keyValuePairs = new BST<ElementType>;

}


template <class ElementType>
Dictionary<ElementType>::~Dictionary()
{

}

template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{
    keyValuePairs->getElementCount();
}

//insert
template <class ElementType>
void Dictionary<ElementType>::put(const ElementType& newElement)
{   
    keyValuePairs->insert(newElement);

}


//retrieve
template <class ElementType>
ElementType& Dictionary<ElementType>::get(const ElementType& targetElement) const
{
    keyValuePairs->retrieve(targetElement);
}
//traverseInorder
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const{
    keyValuePairs->traverseInOrder(visit);
}