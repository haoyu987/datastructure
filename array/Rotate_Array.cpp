//   http://www.geeksforgeeks.org/array-rotation/
    
    void rotate(vector<int>& nums, int k) {
        int start = 0, n = nums.size();
        for (; k %= n; n -= k, start += k)
            for (int i = 0; i < k; i++) 
                swap(nums[start + i], nums[start + n - k + i]);
    }
