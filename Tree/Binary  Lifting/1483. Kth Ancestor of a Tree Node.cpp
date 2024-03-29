class TreeAncestor {
    vector<int> depth;
    vector<vector<int>> up;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        depth = vector<int>(n);
        up = vector<vector<int>>(n, vector<int>(20));
        
        //this is working for this particular problem
        parent[0] = 0;
        for(int i = 0; i < n; i++) {
            up[i][0] = parent[i];
            if(i != 0)
                depth[i] = 1 + depth[parent[i]];
            for(int j = 1; j < 20; j++) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        
        //binary lifting
        //this is not working bcz cant find k > 1 th parent for first node
        //but first node may have k > 1 th parent, and next nodes goes to wrong
        // rep(u, 1, n) {
        //     rep(i, 1, 30) {
        //         up[u][i] = up[up[u][i-1]][i-1];
        //     }
        // }

        // binary lifting
        // first find  2^1, then 2^2, then 2^3...for all u
        rep(i, 1, 30) {
            rep(u, 1, n) {
                up[u][i] = up[up[u][i-1]][i-1];
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) 
            return -1;
        
        for(int i = 19; i >= 0; i--) {
            if(k >= (1 << i)) {
                node = up[node][i];
                k -= (1 << i);
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
