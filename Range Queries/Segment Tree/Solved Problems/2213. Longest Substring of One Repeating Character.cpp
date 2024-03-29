class Solution {
private:
    struct Node {
        int max, size;
        int prefix_size, suffix_size;
        char prefix_char, suffix_char;
        Node(char ch) {
            max = size = 1;
            prefix_size = suffix_size = 1;
            prefix_char = suffix_char = ch;
        }
    };
    
    // segment tree
    string a;
    vector<Node> tree;
    
    Node merge_node(Node left, Node right) {
        Node ans('a');

        // merge prefix
        ans.prefix_size = left.prefix_size;
        if(left.prefix_size == left.size && left.prefix_char == right.prefix_char)
            ans.prefix_size = left.prefix_size + right.prefix_size;
        ans.prefix_char = left.prefix_char;
        
        // merge suffix
        ans.suffix_size = right.suffix_size;
        if(right.suffix_size == right.size && right.suffix_char == left.suffix_char)
            ans.suffix_size = right.suffix_size + left.suffix_size;
        ans.suffix_char = right.suffix_char;
        
        // size of this segment node
        ans.size = left.size + right.size;
        
        // max size
        int tmp = max(ans.suffix_size, ans.prefix_size);
        if(left.suffix_char == right.prefix_char)
            tmp = max(tmp, left.suffix_size + right.prefix_size);
        ans.max = max({left.max, right.max, tmp});
        
        return ans;
    }
    
    Node buildST(int i, int l, int r) {
        if(l == r) {
            Node node(a[l]);
            tree[i] = node;
            return tree[i];
        }

        int mid = (l + r) / 2;
        Node left = buildST(2*i+1, l, mid);
        Node right = buildST(2*i+2, mid+1, r);
     
        return tree[i] = merge_node(left, right);
    }
    
    void update(int i, int sl, int sr, int pos, char ch) {
        if(sl == sr) { 
            //update in the leaf node of the tree
            Node node(ch);
            tree[i] = node;
            return;
        }

        int mid = (sl + sr) / 2;
        if(pos <= mid) 
            update(2*i+1, sl, mid, pos, ch);
        else 
            update(2*i+2, mid+1, sr, pos, ch);

        //update intermediate nodes after returning the value of the leaf node
        tree[i] = merge_node(tree[2*i+1], tree[2*i+2]);      
    }
    
    
public:
    vector<int> longestRepeating(string s, string qchars, vector<int>& qIndices) {
        int N = s.length();
        a = s;
        
        Node dummy('a');
        tree.resize(4*N+5, dummy);
        
        // build segment tree
        // 0 indexing segment tree
        buildST(0, 0, N-1);
        
        // for(int i = 0; i < tree.size(); i++)
        //     cout << tree[i].max << endl;
        
        vector<int> ans;
        for(int i = 0; i < qIndices.size(); i++) {
            int pos = qIndices[i];
            char ch = qchars[i];
            update(0, 0, N-1, pos, ch);
            
            // root of segment tree contains max count
            ans.push_back(tree[0].max);
        }
        
        return ans;
    }
};

