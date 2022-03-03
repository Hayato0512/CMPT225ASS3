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
    delete keyValuePairs;
}

template <class ElementType>
unsigned int Dictionary<ElementType>::getElementCount() const
{
    unsigned int ret = keyValuePairs->getElementCount();
    
    return ret;
    
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
    ElementType& translated = keyValuePairs->retrieve(targetElement);
    return translated;
}
//traverseInorder
template <class ElementType>
void Dictionary<ElementType>::displayContent(void visit(const ElementType&)) const{
    keyValuePairs->traverseInOrder(visit);
}