// https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively

class Solution {
public:
    int findKthLargest(vector<int>& nums,int k){
        priority_queue<int,std::vector<int>, std::greater<int>> numq;
        for(auto x:nums){
            numq.push(x);
            if(numq.size()>k) numq.pop();
        }
        return numq.top();
    }

};
