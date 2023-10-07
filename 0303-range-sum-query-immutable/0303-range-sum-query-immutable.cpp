class NumArray {
public:
    vector<int> VECTORS;

    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int I : nums)
        {
            sum += I;
            VECTORS.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
        {
            return VECTORS[right];
        }
        
        return VECTORS[right] - VECTORS[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */