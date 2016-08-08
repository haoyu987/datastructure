template <typename Comparable>
class BinaryHeap
{
  public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const vector<Comparable> & items);
    
    bool isEmpty() const;
    const Comparable & findMin() const;
    
    void insert(const Comparable & x);
    void insert(Comparable && x);
    void deleteMin();
    void deleteMin(Comparable & minItem);
    void makeEmpty();
    
  private:
    int currentSize;
    vector<Comparable> array;
    
    void buildHeap();
    void percolateDown(int hole);
};

void insert(const Comparable & x)
{
  if(currentSize == array.size() - 1)
    array.resize(array.size() * 2);
    
  int hole=++currentSize;
  Comparable copy=x;
  
  array[0] = std::move(copy);
  for(; x<array[hole/2];hole /= 2)
    array[hole] = std::move(array[hole/2]);
  array[hole] = std::move(array[0]);
}
