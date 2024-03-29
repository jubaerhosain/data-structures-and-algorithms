class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        
        for(int i = 0; i < shifts.size(); i++) {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int d = shifts[i][2];
            if(d == 0) {
                left[r] += -1;
                if(l > 0) left[l-1] += 1;
            } else {
                right[l] += 1;
                if(r < n-1) right[r+1] += -1;
            }
        }
        
        for(int i = 1; i < n; i++) 
            right[i] += right[i-1];
        for(int i = n-2; i >= 0; i--)
            left[i] += left[i+1];
        
        for(int i = 0; i < n; i++) {
            left[i] += right[i];
            left[i] %= 26;
            left[i] = (left[i] + 26)%26;
        }
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            c = (c+left[i]) % 26;
            s[i] = 'a' + c;
        }
        
        return s;
    }
};