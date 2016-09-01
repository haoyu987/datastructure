template<Typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    BinarySearchTree(BinarySearchTree && rhs);
    ~BinarySearchTree();
    
    const Comparable & findMin() const;
    const Comparable & findMax() const;
    bool contains(const Comparable & x) const;
    bool isEmpty() const;
    void printTree(ostream & out = cout) const;
    
    void makeEmpty();
    void insert(const Comparable & x);
    void insert(const Comparable && x);
    void remove(const Comparable & x);
    
    BinarySearchTree & operator=(const BinarySearchTree & rhs);
    BinarySearchTree & operator=(BinarySearchTree && rhs);
    
  private:
    struct BinaryNode
    {
      Comparable element;
      BinaryNode *left;
      BinaryNode *right;
      
      BinaryNode(const Comparable & theElement, BinaryNode *lt,BinaryNode *rt)
        :element(theElement),left(lt),right(rt){}
        
      BinaryNode(Comparable && theElement, BinaryNode *lt,BinaryNode *rt)
        :element(std::move(theElement)),left(lt),right(rt){}
    };
    
    BinaryNode *root;
    
    void insert(const Comparable & x, BinaryNode * &t);
    void insert(Comparable && x, BinaryNode * & t);
    void remove(const Comparable & x,BinaryNode * & t);
    BinaryNode * findMin(BinaryNode *t) const;
    BinaryNode * findMax(BinaryNode *t) const;
    bool contains(const Comparable & x,BinaryNode *t) const;
    void makeEmpty(BinaryNode * & t);
    void printTree(BinaryNode *t,ostream & out) const;
    BinaryNode * clone(BinaryNode *t) const;
};

bool contains(const Comparable &x) const
{
  return contains(x,root);
}

void insert(const Comparable&x)
{
`insert(x,root);
}

void remove(const Comparable & x)
{
  remove(x,root);
}

bool contains(const Comparable &x,BinaryNode *t) const
{
  if(t==nullptr)
    return false;
  else if(x<t->element)
    return contains(x,t->left);
  else if(x>t->element)
    return contains(x,t->right);
  else
    return true;
}

BinaryNode * findMin(BinaryNode *t) const
{
  if(t==nullptr)
    return nullptr;
  if(t->left==nullptr)
    return t;
  return findMin(t->left);
}

BinaryNode * findMax(BinaryNode *t) const
{
  if(t!=nullptr)
    while(t->right != nullptr)
      t = t->right;
  return t;
}

void insert(const Comparable & x,BinaryNode * & t)
{
  if(t==nullptr)
    t=new BinaryNode(x,nullptr,nullptr);
  else if(x<t->element)
    insert(x,t->left);
  else if(x>t->element)
    insert(x,t->right);
  else
    ; // duplicate
}

void remove(const Comparable&x, BinaryNode * & t)
{
  if(t==nullptr)
    return;  // not found
  if(x<t->element)
    remove(x,t->left);
  else if(x>t->element)
    remove(x,t->right);
  else if(t->left != nullptr && t->right != nullptr)
  {
    t->element = findMin(t->right)->element;
    remove(t->element,t->right);
  }
  else
  {
    BinaryNode *oldNode = t;
    t = (t->left != nullptr) ? t->left : t->right;
    delete oldNode;
  }
  
  ~BinarySearchTree()
  {
    makeEmpty();
  }
  
  void makeEmpty(BinaryNode * & t)
  {
    if(t != nullptr)
    {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    t = nullptr;
  }
  
  BinarySearchTree( const BinarySearchTree & rhs) : root(nullptr)
  {
    root = clone(rhs.root);
  }
  
  BinaryNode * clone(BinaryNode * t) const
  {
    if(t==nullptr)
      return nullptr;
    else
      return new BinaryNode(t->element,clone(t->left),clone(t->right));
  }

};
