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
        vector<int> nsel(n);
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if(stk.size() == 0)
                nsel[i] = n;
            else 
                nsel[i] = stk.top();
            stk.push(i);
        }
        return nsel;
    }
    
    
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pfsum(n, 0);
        
        pfsum[0] = nums[0];
        for(int i = 1; i < n; i++)
            pfsum[i] = pfsum[i-1] + nums[i];
        
        vector<int> nsel = NSEL(nums);
        vector<int> nser = NSER(nums);
        long long ans = -1;
        for(int i = 0; i < n; i++) {
            long long mn = nums[i];
            int l = nsel[i] + 1;
            int r = nser[i] - 1;
            long long sum = (l == 0 ? pfsum[r] : pfsum[r] - pfsum[l-1]);
            ans = max(ans, sum*mn);                
        }
        
        return (int)(ans%1000000007);
    }
};

















