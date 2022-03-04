/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Hayato Koyama
 * Date of last modification: March 3rd. 2022
 */

#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

/* Constructors and destructor */

	// Default constructor
    template<class ElementType>
	BST<ElementType>::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor
    template<class ElementType>      
    BST<ElementType>::BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		elementCount = 1;	
	}               

    // Copy constructor
    template<class ElementType>  
	BST<ElementType>::BST(const BST<ElementType>& aBST)  
	{   root = NULL;
        //call copy_BST
        root = copy_BST(aBST.root,root);
        //set the elementCount same as the old BST
        elementCount = aBST.elementCount;
	}

    // Description: create a whole new BST by copying an old BST(deep copy)
	//               this is used from the copy constructor.
	//              .copy each nodes by vising them recursively.
    template<class ElementType>  
    BSTNode<ElementType>* BST<ElementType>::copy_BST(BSTNode<ElementType>* src, BSTNode<ElementType>* dest){
        //if the old BST is NULL, the new one is also NULL
        if(src==NULL){
            dest = NULL;
        }
        else{
            //allocate memory to the new Node
            dest = new BSTNode<ElementType>();
            //copy the element of the old root
            dest->element = src->element;
            
            //call copy_BST for left&right recursively, and assign them to the dest->left and right
            dest->left = copy_BST(src->left,dest->left);
            dest->right = copy_BST(src->right,dest->right);
            
        }
        return dest;
        
    }

	// Destructor 
    template<class ElementType> 
	BST<ElementType>::~BST() {
        //call deleteNode and set the elementCount = 0
    	deleteNode(root);
        elementCount = 0;
    }
    
    // Description: delete all the nodes in BST that are dynamically allocated.
	//               this is used from Destructor at the end of the program to make sure no memory leak.(works, checked with Valgrind)
	//               delete nodes by visiting them recursively, in post-order.
	template<class ElementType> 
    void BST<ElementType>::deleteNode(BSTNode<ElementType>* current){
        //if the tree is NULL, dont do anything
        if(current==NULL){
            return ;
        }
        else{
            //use post-order recursive traversal to successfully delete nodes from the bottom.
            deleteNode(current->left);
            deleteNode(current->right);
            delete current;
        }
    }
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)
    template<class ElementType>	
	unsigned int BST<ElementType>::getElementCount() const {		

		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
    template<class ElementType>
	void BST<ElementType>::insert(const ElementType& newElement) {
		
	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode<ElementType>(newElement);
            //cout<<"successfully inserted the item "<<newElement<<endl;
			elementCount++;
		}
		else{
		  if ( !insertR(newElement, root) ) {
  	         throw ElementAlreadyExistsException("Element already exists in the data collection.");
  	      }
          else{
              //cout<<"successfully inserted the item "<<newElement<<endl;
          }
        }
  	   return;
  	}

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    template<class ElementType>
	bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) { 
        //if current's element = anElement, return false;
        if(current->element==anElement){
            return false;
        }
        //if cuurent's elemt is not anelement,
        else{
           
            //(if newElement > current'element, 
            if(anElement > current->element){
                 //and if current has right child, call right child recursively
                if(current->hasRight()){
                    return insertR(anElement, current->right);
                }
                //if current doesnt have righ child, make a new node with an ELemnt and set the node to current's rightChild, Count++, return true)
                else{
                    BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
                    current->right = newNode;
                    elementCount++;
                    return true;
                }
            }
            //else if newElement < current's element,
            else if(anElement < current->element){
                //and if current has left child, call left child recursively
                if(current->hasLeft()){
                    return insertR(anElement, current->left);
                }    
                //if no right child, create a new node with new element, 
                //set that to current's leftChild, Count++ return true
                 else{
                    BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
                    current->left = newNode;
                    elementCount++;
                    return true;
                }

            }
            
        }
        return false;
	} //end of insertR

	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
    template<class ElementType>
    ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const {
        
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");
		
		// Otherwise, search for it		
		ElementType& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    template<class ElementType>
    ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {
        //if current == NULL, throw exception and return nullptr
        if(current==NULL){
            throw ElementDoesNotExistException("The element does not exist.");
            
        }
        else{//if target == current's element, return current->element
            if(targetElement == current->element){
                return current->element;
            }
            
            
            //else if target > current, call recursively with current-> right
            else if(targetElement > current->element)
                return retrieveR(targetElement, current->right);
             //else if target < current, call recursively with current->left
            else{
                return retrieveR(targetElement, current->left);
            }
        }

	} // end of retrieveR
				
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
    template<class ElementType>
	void BST<ElementType>::traverseInOrder(void visit(const ElementType&)) const {
		
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);
		
		return;
	}

    // Description: Recursive in order traversal of a binary search tree.	
	template<class ElementType>
	void BST<ElementType>::traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const {
        //if current is NULL, return 
        if(current==NULL)
            return ;

        //else, call left
        //      print current   => in-Order method
        //       call right
        else{
            traverseInOrderR(visit, current->left);
            visit(current->element);
            traverseInOrderR(visit, current->right);
        }
       ;
	}// end of traverseInOrderR