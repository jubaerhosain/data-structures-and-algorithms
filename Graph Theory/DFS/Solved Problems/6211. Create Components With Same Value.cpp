class Solution {
    int cmp = 0;
    vector<vector<int>> g;
    
    int dfs(int u, int p, const int &fac, vector<int> &nums) {
        // sum of subtree nodes including u
        int sum = nums[u];
        for(int v: g[u]) {
            if(v == p) continue;
            sum += dfs(v, u, fac, nums);
        }
        
        // if fac divides sum then one component found
        if(sum%fac == 0)
            cmp += 1;
        return sum;
    }

    
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) 
            sum += nums[i];
        
        // find factors of sum
        vector<int> factors;
        for(int i = 1; i*i <= sum; i++) {
            if(sum%i == 0) {
                factors.push_back(i);
                if(i != sum/i)
                    factors.push_back(sum/i);
            }
        }
        
        // sort them in ascending order (min factor makes max number of component)
        sort(factors.begin(), factors.end());
        
        
        // MAKE GRAPH
        g.resize(n);
        for(auto it: edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        int mx = *max_element(nums.begin(), nums.end());
        for(int f: factors) {
            if(f < mx) continue;
            
            cmp = 0;
            dfs(0, -1, f, nums);
            
            if(cmp != 0) {
                if(sum/cmp == f && sum%cmp == 0)
                    return cmp - 1;
            }
        }
        
        return 0;
    }
};


