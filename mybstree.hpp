//Name: Tim Buesking
//Class: CS153 Section A
//Date: 5/12/14
//Desc: Binary Search Tree Functions


#include <iostream>
#include <string>

  template<typename T>  
  int MyBSTree <T> :: size() const
  {
    return m_size;
  }

  template<typename T>  
  bool MyBSTree <T> ::isEmpty() const
  {
    if(m_root == NULL)
    {
      return true;
    }
    
    else
    {
      return false;
    }
  }

  template <typename T>
  int MyBSTree <T> ::height() const
  {
    TreeNode <T> * t = this -> m_root;
    return recursiveHeight(t);
  }
  
  template <typename T>
  int MyBSTree<T> :: recursiveHeight( TreeNode <T> * & t) const
  {
    
    if (t == NULL)
    {
      return 0;
    }
    
    int left = recursiveHeight (t -> m_left);
    int right = recursiveHeight (t ->m_right);
    
    if (left > right)
    {
      return (left + 1);
    }
    else
    {
      return (right + 1);
    }
  }

  template <typename T>
  const T&  MyBSTree <T> :: findMax() const
  {
    TreeNode <T> * t = this -> m_root;
    return getMax(t);
  }

  template <typename T>
  const T& MyBSTree <T> :: findMin() const
  {
    TreeNode <T> * t = this -> m_root;
    return getMin (t);
  }

  template <typename T>
  const T& MyBSTree<T>::getMin( TreeNode<T>* & t) const
  {
    string oops = "PANIC: Tree is Empty!!";
    if (t == NULL)
    {
      throw oops;
    }
    
    if ( t-> m_left == NULL)
    {
      return t -> m_data;
    }
    else
    {
      return (getMin (t -> m_left));
    }
  }
  
  template <typename T>
  const T& MyBSTree<T>::getMax( TreeNode<T>* & t) const
  {
    string oops = "PANIC: Tree is Empty!!";
    if (t == NULL)
    {
      throw oops;
    }
    
    if ( t-> m_right == NULL)
    {
      return t -> m_data;
    }
    else
    {
      return (getMax (t -> m_right));
    }
  }

  template <typename T>
  int MyBSTree <T> :: contains(const T& x) const
  {
    const MyBSTree* t = this;
    int depth = recursive_contains(x, t -> m_root);

    if (depth >= 0)
    {
      return depth;
    }
    else
    {
     return (0 - (height() +1));
    }
  }
  
  
  template <typename T>
  int MyBSTree<T> :: recursive_contains(const T& x, const TreeNode <T>* t) const
  {
    int depth = 0;
    
    if ( t -> m_data == x)
    {
      return 0;
    }
    
    else if ( x > t -> m_data)
    {
      depth = recursive_contains (x, t -> m_right);
      if (depth == -1)
      {
        return -1;
      }
      else
      {
        return (depth + 1);
      }
    }
    
    else if ( x < t -> m_data)
    {
     depth = recursive_contains (x, t -> m_left);
     if (depth == -1)
     {
       return -1;
     }
     else
       return (depth + 1);
    }

    return -1;
  }
  
  
  template <typename T>
  void MyBSTree <T> :: clear()
  {
    trimTree(m_root);
  }
  
  template <typename T>
  void MyBSTree <T> :: trimTree (TreeNode <T>* & t)
  {
    if ( t != NULL)
    {
      trimTree( t-> m_left);
      trimTree( t-> m_right);
      delete t;
    }
    return;  
  }

  template <typename T>
  void MyBSTree <T> :: insert(const T& x)
  {
    MyBSTree* t = this;
    recursive_insert(x, t-> m_root);
    m_size++;
    return;
  }

  template <typename T>
  void MyBSTree<T> :: recursive_insert(const T& x, TreeNode<T>* &k)
  {
    if (k == NULL)
    {
      k = new TreeNode<T> (x, NULL, NULL);
    }

    else if ( x < k -> m_data)
    {
      recursive_insert (x, k -> m_left);
    }
    else if ( x > k -> m_data)
    {
      recursive_insert (x, k -> m_right);
    }
    else
    {
      return;
    }

  }
  
  
  
  template <typename T>
  void MyBSTree <T> :: remove(const T& x)
  {
    recursive_remove (x, m_root);
    m_size--;
  }
  
  
  template <typename T>
  void MyBSTree <T> :: recursive_remove (const T&x, TreeNode<T> * &t)
  {
    if (t == NULL)
    {
      return;
    }
    
    if ( x < t -> m_data)
    {
      recursive_remove (x, t-> m_left);
    }
    
    if ( x > t -> m_data)
    {
      recursive_remove( x, t-> m_right);
    }
    
   if ( x == t -> m_data)
    {
      if ( (t-> m_left != NULL) && (t-> m_right != NULL))
      {
        t -> m_data = getMax( t-> m_left);
        recursive_remove ( t-> m_data, t-> m_left );
      }
      
      else
      {
        TreeNode <T>* tmp = t;
        t = tmp -> m_right;
        if (t == NULL)
        {
          t = tmp -> m_left;
        }
        delete tmp;
      }
    }
  }
  
  
  
  

  template <typename T>
  void MyBSTree <T> :: printPreOrder() const
  {
    recursive_pre(this -> m_root);
    return;
  }
  
  template <typename T>
  void MyBSTree<T> :: recursive_pre( const TreeNode <T> *t) const
  {
    if  (t != NULL)
    {
      cout << t -> m_data << endl;
      recursive_pre ( t -> m_left);
      recursive_pre( t -> m_right);
    }
    return;  
  }
  
  
  template <typename T>
  void MyBSTree <T> :: printPostOrder() const 
  {
    recursive_post (this -> m_root);   
    return;
  }
  
  template <typename T>
  void MyBSTree<T> :: recursive_post( const TreeNode <T> *t) const
  {
    if (t != NULL)
    {
      recursive_post ( t -> m_left);
      recursive_post ( t -> m_right);
      cout << t-> m_data << endl;
    }
    
    return;
  }
  
  template <typename T>
  void MyBSTree <T> :: print() const
  {
    prettyPrint(m_root, 0);
    return;
  } 

  template <typename T>
  void MyBSTree <T> :: prettyPrint (const TreeNode<T>* t, int pad) const
{
  string s(pad, ' ');
  if (t == NULL)
      cout << endl;
  else{
    prettyPrint(t -> m_right, pad+4);
    cout << s << t -> m_data << endl;
    prettyPrint(t -> m_left, pad+4);
  }  
}



  template <typename T>
  MyBSTree <T> :: ~MyBSTree()
  {
    clear();
  } 
  
  template <class T>
  MyBSTree <T>& MyBSTree<T> :: operator = (const MyBSTree <T> & rhs)
  {
    if(this != &rhs)
    {
      m_root = clone(rhs.m_root);
      m_size = rhs.m_size; 
    }
    return *this;
  }
  
  template <typename T>  
  MyBSTree <T> :: MyBSTree(const MyBSTree <T> & cpy)
  {
    *this = cpy;
  }
  
  template <typename T>
  TreeNode<T>* MyBSTree <T> :: clone(const TreeNode<T>* t)
  {
    if (t == NULL)
      return NULL;
    
    else{
      return new TreeNode<T>(t-> m_data, clone(t-> m_left),clone(t-> m_right));
    }  
  }
