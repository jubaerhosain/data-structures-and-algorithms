class Solution {
public:
    int longestAwesome(string str) {
        // mask, index
        map<int, int> inx;
        inx[0] = -1;
        
        int mask = 0, ans = 1;
        for(int i = 0; i < str.length(); i++) {
            mask ^= (1 << (str[i]-'0'));
            
            // all are even
            if(inx.count(mask))
                ans = max(ans, i - inx[mask]);
            
            // one is odd and others are even
            for(int j = 0; j < 10; j++) {
                int tmp_mask = mask ^ (1<<j);
                if(inx.count(tmp_mask))
                    ans = max(ans, i - inx[tmp_mask]);
            }
            
            // add to map
            if(inx.count(mask) == 0)
                inx[mask] = i;
        }
        
        return ans;
    }
};