// try to understand smartly


class Solution {
   int dp[101][101];
    
    int recur(int left, int right, string &s) {
        if(left > right)
            return 0;
        else if(left == right)
            return 1;
        else if(dp[left][right] != -1)
            return dp[left][right];
        
        int skip = 1 + recur(left+1, right, s);
        int keep = 1e9;
        for(int l = left+1; l <= right; l++) {
            if(s[l] == s[left]) 
                keep = min(keep, recur(left+1, l-1, s) + recur(l, right, s));
                
        }
        
        return dp[left][right] = min(skip, keep);
    }
    
public:
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        
        //l, r, streak, s
        return recur(0, s.size()-1, s);
    }
};



