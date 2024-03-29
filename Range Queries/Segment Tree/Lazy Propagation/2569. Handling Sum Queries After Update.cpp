// #include<bits/stdc++.h>
// using namespace std;

class Solution {
    struct Node {
        int lazy, sum;
        Node() {
            lazy = sum = 0;
        }
    };

    vector<Node> tree;
    int buildST(int i, int l, int r, vector<int> &a) {
        if(l == r) 
            return tree[i].sum = a[l];
        int mid = (l + r) / 2;
        return tree[i].sum = buildST(2*i+1, l, mid, a) + buildST(2*i+2, mid+1, r, a);
    }

    void pending_update(int i, int sl, int sr) {
        if(tree[i].lazy%2 != 0) {
            tree[i].sum = (sr-sl+1) - tree[i].sum;
        }
        
        if(sl != sr) {             //update child nodes and reset parent (i)
            tree[2*i+1].lazy += tree[i].lazy;
            tree[2*i+2].lazy += tree[i].lazy;
        }
            
        tree[i].lazy = 0;
    }

    void range_update(int i, int sl, int sr, int l, int r, int val) {
        pending_update(i, sl, sr);

        if(sr < l || r < sl)          // no overlap;
            return;

        if(sl >= l && sr <= r)  {     // total overlap
            tree[i].lazy += val;
            pending_update(i, sl, sr);
            return;
        }

        int mid = (sl + sr) / 2;
        range_update(2*i+1, sl, mid, l, r, val);
        range_update(2*i+2, mid+1, sr, l, r, val);
        
        //update intermediate nodes after returning the value of the leaf node
        tree[i].sum = tree[2*i+1].sum + tree[2*i+2].sum;  
    }

    int query(int i, int sl, int sr, int l, int r) {
        pending_update(i, sl, sr);
        
        if(sl >= l && sr <= r)          // total overlap
            return tree[i].sum;
        else if(sr < l || r < sl)       // no overlap;
            return 0;

        int mid = (sl + sr) / 2;
        return query(2*i+1, sl, mid, l, r) + query(2*i+2, mid+1, sr, l, r);
        
    }

public:
    vector<long long> handleQuery(vector<int>& a, vector<int>& b, vector<vector<int>>& queries) {
        int n = a.size();
        tree.resize(4*n);

        buildST(0, 0, n-1, a);

        vector<long long> ans;
        long long sum2 = 0;
        for (int i: b)
            sum2 += i;

        for(auto it: queries) {
            if(it[0] == 1) {
                range_update(0, 0, n-1, it[1], it[2], 1);
            } else if(it[0] == 2) {
                sum2 += (query(0, 0, n-1, 0, n-1) * (long long)it[1]);
            } else {
                ans.push_back(sum2);
            }
        }

        return ans;
    }
};


