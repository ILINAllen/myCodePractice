class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len1 = strlen(s);
        int len2 = strlen(p);
        if(p == NULL)return false; 
        vector<vector<bool>> DP(len1 + 1, vector<bool>(len2 + 1, false));
        DP[0][0] = true;
        for(int j = 1; j <= len2; j++)
        {
            if(p[j - 1] == '*' && (j - 2 >= 0 && DP[0][j - 2] || DP[0][j - 1]))
                DP[0][j] = 1;            
        }
        for (int i=1; i <= len1; ++i) {
            DP[i][0] = false;
           }
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    DP[i][j] = DP[i - 1][j - 1];
                
                else if(p[j - 1] == '*')
                {
                    DP[i][j] = (j - 2 >= 0 && DP[i][j - 2]) || DP[i][j - 1] || 
                    (DP[i - 1][j] && ((i >= 2 && j >= 2 && s[i - 1] == s[i - 2] && s[i - 2] == p[j - 2]) || (j >= 2 && p[j - 2] == '.')));
                    
                }
                else 
                    DP[i][j] = false;   
            }
        }
        return DP[len1][len2];
    }
};
