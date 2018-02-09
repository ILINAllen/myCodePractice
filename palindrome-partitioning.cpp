//如果要求输出所有可能的解，往往都是要用深度优先搜索。如果是要求找出最优的解，或者解的数量，往往可以使用动态规划。

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;        
        vector<string> cur;     
        dfs(s, cur, res);        
        return res;
    }
    
    bool ispalindrome(string s)
    {
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
     
    void dfs(string s, vector<string>& cur, vector<vector<string>>& res)
    {
        if(s.size() < 1)
        {
            res.push_back(cur);
            return;
        }    
        for(int i = 0; i < s.size(); ++i)
        {
            if(not ispalindrome(s.substr(0, i + 1)))
                continue; 
            cur.push_back(s.substr(0, i + 1));
            string sright = s.substr(i + 1, s.size() - i - 1);
            dfs(sright, cur, res);   
            cur.pop_back();
        }  
    }
};
