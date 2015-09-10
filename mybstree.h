//Name: Tim Buesking
//Class: CS153 Section A
//Date: 5/12/14
//Desc: Binary Search Tree Class

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include <string>
#include "abstractbstree.h"
 
using namespace std;
 
  template < typename T >
  struct TreeNode
  {
    T m_data;
    TreeNode* m_right;
    TreeNode* m_left;
  
    TreeNode( const T& x, TreeNode<T>* left, TreeNode<T>* right)
    {
      m_data = x;
      m_left = left;
      m_right = right;  
    }
  };
 
  template < class T >

  class MyBSTree : public AbstractBSTree<T>
  {

    private:
  
      TreeNode <T>* m_root;
      int m_size;

    public:
  
    // Default Constructor
      MyBSTree()  {
                     m_size= 0;
                     m_root = NULL;
                  }
      
	  // 
	  MyBSTree(const T& x, TreeNode<T>* left, TreeNode<T>* right)
                {
                  m_root = new TreeNode <T> (x, left, right);
                  m_size = 0;
                }
			  
  // Purpose: Accessor function for the number of elements in the tree
  // Returns: number of elements in the tree 
  virtual int size() const;


  // Purpose: Checks if a tree is empty
  // Returns: 'true' if the tree is empty
  //     'false' otherwise  
  virtual bool isEmpty() const;


  // Purpose: Returns the height of the tree
  // Returns: height the tree 
  virtual int height() const;


  // Purpose: finds the maximum element in the Tree
  // Returns: a const reference to the maximum element
  virtual const T& findMax() const;


  // Purpose: finds the minimum element in the Tree
  // Returns: a const reference to the minimum element
  virtual const T& findMin() const;


  // Purpose: finds an element in the Tree
  // Parameters: x is value to be found 
  // Returns: 
  //     If The tree contains x then  
  //         return N, the level of the node containing x
  //         (the root is considered level 0)
  //     If The tree does not contains x then  
  //         return -N, where N is the level of the tree 
  //         reached in the search + 1
  virtual int contains(const T& x) const;


    
  /*** ---- Mutator Operations ---- */

  
  // Purpose: Clears the Tree
  // Postconditions: an empty Tree
  virtual void clear();


  // Purpose: Inserts an element into a tree
  // Parameters: x is value to be added to the tree
  // Postconditions: The tree now contains x
  //     if the tree already contains x, ignore insertion
  virtual void insert(const T& x);

    
  // Purpose: Removes an element from the tree
  // Parameters: x, the element to remove
  // Postconditions: the tree does not contains x
  virtual void remove(const T& x);
          
     
  /*** ---- Output Operations ---- */

  // Purpose: Prints the Tree in Pre-Order    
  virtual void printPreOrder() const;


  // Purpose: Prints the Tree in Pre-Order    
  virtual void printPostOrder() const; 


  // Purpose: Prints the Tree In-Order with formatting
  //     each level indented 4 spaces, one element per line    
  virtual void print() const;
  
  
  // Purpose: Inserts an element into a tree
  // Parameters: x is value to be added to the tree
  // Postconditions: The tree now contains x
  //     if the tree already contains x, ignore insertion
  void recursive_insert(const T&x, TreeNode<T> * &k);    

  
  //Purpose: Returns a copy of the tree
  //Parameters: t is the pointer to the treenode
  TreeNode<T>* clone(const TreeNode<T>* t);
  

  void prettyPrint (const TreeNode<T>* t, int pad) const;

  int recursiveHeight( TreeNode <T> * & t) const;
   
  int recursive_contains(const T& x, const TreeNode <T>* t) const;
  
  void recursive_remove (const T&x, TreeNode<T> * &t);
  
  const T& getMin( TreeNode<T>* & t) const;

  const T& getMax( TreeNode<T>* & t) const;
  
  void trimTree (TreeNode <T>* & t);
  
  void recursive_pre( const TreeNode <T> *t) const;

  void recursive_post( const TreeNode <T> *t) const;

  
  // Destructor
 ~MyBSTree();

  // Equal Operator  
  MyBSTree & operator = (const MyBSTree & rhs);
  
  // Copy Constructor
  MyBSTree(const MyBSTree & cpy);
   
}; 

#endif 
#include "mybstree.hpp"
