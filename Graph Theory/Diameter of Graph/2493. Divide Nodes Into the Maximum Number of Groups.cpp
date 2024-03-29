class Solution {
    int inf = 1e9;
    int color[505], dist[505][505], used[505];
    vector<int> g[505], currentNodes;
    
    bool bipartite(int u, int c = 2) {
        color[u] = c;
        for(int v: g[u]) {
            // never will going to backward to parent
            if(color[v] == 0 && !bipartite(v, c^1))
                return false;
            else if(color[u] == color[v])
                return false;
        }
        return true;
    }
    
    void findCurrentNodes(int u, int p) {
        used[u] = 1;
        currentNodes.push_back(u);
        for(int v: g[u]) {
            if(used[v] == 0 && v != p)
                findCurrentNodes(v, u);
        }
    }
    
    int get_diameter(int u) {
        currentNodes.clear();
        
        findCurrentNodes(u, 0);
        
        int mx = 1;
        // all nodes in current component
        for(int i = 0; i < currentNodes.size(); i++) {
            for(int j = i+1; j < currentNodes.size(); j++) {
                int a = currentNodes[i], b = currentNodes[j];
                    if(dist[a][b] != inf)
                        mx = max(mx, dist[a][b]);
            }
        }
        
        return mx;
    }

    void bfs(int u, int *d, int n) {
        for(int i = 1; i <= n; i++) {
            d[i] = inf;
        }

        queue<int> q;
        q.push(u);
        d[u] = 1;

        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int v: g[u]) {
                if(d[v] == inf) {
                    d[v] = 1 + d[u];
                    q.push(v);
                }
            }
        }
    }
    
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        for(auto it: edges) {
            int u = it[0], v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        memset(color, 0, sizeof(color));
        // if any component is not bipartite then there is no sulution
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0 && !bipartite(i))
                return -1;
        }
        
        // all pair shortest path using bfs
        for(int u = 1; u <= n; u++) {
            bfs(u, dist[u], n);
        }
        
        int ans = 0;

        // keeps track of previously used nodes in previous components
        memset(used, 0, sizeof(used)); 

        // sum up diameter of each component
        for(int i = 1; i <= n; i++) {
            if(used[i] == 0)
                ans += get_diameter(i);
        }
        
        return ans;
    }
};



