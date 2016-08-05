template<typename HashObj>
class HashTable
{
  public:
    explicit HashTable(int size=101);
    
    bool contains(const HashObj & x) const; // if HashObj is const.
    
    void makeEmpty();
    bool insert(const HashObj & x);
    bool insert(HashObj && x); //An rvalue reference behaves just like an lvalue reference except that it can bind to a temporary (an rvalue),
                               //whereas you can not bind a (non const) lvalue reference to an rvalue.

}
