// store values in descending order on the stack

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(nums.size(), -1);
        
        for(int i=n*2-1; i>=0; i--) {
            while(!st.empty() and st.top() <= nums[i%n]) st.pop();
            int curr = st.empty() ? -1: st.top();
            ans[i%n] = curr;
            st.push(nums[i%n]);
        }

        return ans;
    }
};