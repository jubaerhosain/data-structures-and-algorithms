class Solution {
    vector<int> top_sorting(vector<vector<int>> con, int k) {
        vector<int> indegree(k+1, 0);
        vector<vector<int>> graph(k+1);
        for(auto &it: con) {
            indegree[it[1]] += 1;
            graph[it[0]].push_back(it[1]);
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v: graph[u]) {
                indegree[v]--;
                if(indegree[v] == 0) 
                    q.push(v);
            }
        }
        
        return ans;
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        vector<int> rowOrder = top_sorting(rowC, k);
        vector<int> colOrder = top_sorting(colC, k);
        
        // check cycle
        if(rowOrder.size() != k || colOrder.size() != k)
            return {};        
        
        // row index and col index of i
        vector<int> r(k+1), c(k+1);
        for(int i = 0; i < k; i++) {
            r[rowOrder[i]] = i;
            c[colOrder[i]] = i;
        }
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++) 
            ans[r[i]][c[i]] = i;
        
        return ans;
    }
};


