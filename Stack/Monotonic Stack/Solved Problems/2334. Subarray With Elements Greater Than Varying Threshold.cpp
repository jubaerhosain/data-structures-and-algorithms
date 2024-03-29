class Solution {
    // Next smaller element in the left
    vector<int> NSEL(vector<int> &nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> nsel(n);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if(stk.size() == 0)
                nsel[i] = -1;
            else 
                nsel[i] = stk.top();
            stk.push(i);
        }
        return nsel;
    }

    // Next smaller element in the right
    vector<int> NSER(vector<int> &nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> nser(n);
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if(stk.size() == 0)
                nser[i] = n;
            else 
                nser[i] = stk.top();
            stk.push(i);
        }
        return nser;
    }
    
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> nsel = NSEL(nums);
        vector<int> nser = NSER(nums);
        
        int len = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int l = nsel[i], r = nser[i];
            // suppose nums[i] is minimum in this subarray
            if(threshold/(r-l-1)<nums[i])
                len = max(len, r-l-1);
        }
        
        return len;
    }
};



