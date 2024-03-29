class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();

        // {j, i} number of element less than i from (0 to j)
        vector<vector<int>> pref(n, vector<int>(n+1, 0));
        for(int j = 0; j < n; j++) {
            if(j > 0)
                pref[j] = pref[j-1];
            for(int i = nums[j]+1; i <= n; i++)
                pref[j][i] += 1;
        }

        // {j, i} number of element greater than i from (j to n-1)
        vector<vector<int>> suff(n, vector<int>(n+1, 0));
        for(int j = n-1; j >= 0; j--) {
            if(j < n-1)
                suff[j] = suff[j+1];
            for(int i = nums[j]-1; i >= 1; i--)
                suff[j][i] += 1;
        }

        long long ans = 0;
        for(int j = 1; j < n-2; j++) {
            for(int k = j + 1; k < n-1; k++) {
                if(nums[j] > nums[k]) {
                    int a = nums[k];
                    int b = nums[j];
                    ans += (1LL * pref[j-1][a] * suff[k+1][b]);
                }
            }
        }

        return ans;
    }
};


