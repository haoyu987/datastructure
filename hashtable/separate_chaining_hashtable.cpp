template<typename HashedObj>
class HashTable
{
  public:
    explicit HashTable(int size=101);
    
    bool contains(const HashedObj & x) const; // if HashObj is const.
    
    void makeEmpty();
    bool insert(const HashedObj & x);
    bool insert(HashedObj && x); //An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary (an rvalue),
                               //whereas you can not bind a (non const) lvalue reference to an rvalue.
    bool remove(const HashedObj & x);
    
  private:
    vector<list<HashedObj>> theLists;  // The array of lists.
    int currentSize;
    
    void rehash();
    size_t myhash(const HashedObj & x) const;
};


size_t myhash(const HashedObj & x) const
{
  static hash<HashedObj> hf;
  return hf(x) % theLists.size();
}

void makeEmpty()
{
  for(auto & theList: theLists)
    theList.clear();
}

bool contains(const HashedObj & x) const
{
  auto & whichList = theLists[myhash(x)];
  return find(begin(whichList),end(whichList),x) != end(whichList);
}

bool remove(const HashedObj & x)
{
  auto & whichList = theLists[myhash(x)];
  auto itr = find(begin(whichList),end(whichList),x);
  
  if(itr == end(whichList))
    return false;
    
  whichList.erase(itr);
  --currentSize;
  return true;
}

bool insert(const HashedObj & x)
{
  auto & whichList = theLists[myhash(x)];
  if(find(begin(whichList),end(whichList),x) != end(whichList))
    return false;
  whichList.push_back(x);
  
  if(++currentSize > theLists.size())
    rehash;
    
  return true;
}

void rehash()
{
  vector<list<HashedObj>> oldLists = theLists;
  
  // Create new double-sized, empty table
  theLists.resize(nextPrime(2 * theLists.size()));
  for(auto & thisList: theLists)
    thisList.clear();
    
  // Copy table over
  currentSize = 0;
  for(auto & thisList: oldLists)
    for(auto & x: thisList)
      insert(std::move(x));
}
