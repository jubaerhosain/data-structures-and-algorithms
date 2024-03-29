class Solution {
private:
    int max_quality = 0;
    vector<vector<pair<int, int>>> graph;
    
    void dfs(int u, int currValue, int currTime, int maxTime, vector<int> &values) {
        if(currTime > maxTime)
            return;
        
        currValue += values[u];
        if(u == 0) 
            max_quality = max(max_quality, currValue);
        
        int tmp = values[u];
        values[u] = 0;
        
        for(auto it: graph[u]) {
            int v = it.first;
            int time = it.second;
            dfs(v, currValue, currTime + time, maxTime, values);
        }
        
        // restore value of u
        values[u] = tmp;
    }
    
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        graph.resize(n);
        
        // build graph
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int time = it[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // backtracking by dfs
        dfs(0, 0, 0, maxTime, values);
        
        return max_quality;
    }
};





