class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> result;
		if(dict.find(s) != dict.end())
			result.push_back(s);
		
		for(auto i = 1; i < s.size(); ++i)
		{
			string w = s.substr(i);
			
			if(dict.find(w) == dict.end())
				continue;
			string str = s.substr(0, i);
			vector<string> left = wordBreak(str, dict);
			
			for(auto iter = left.begin(); iter != left.end(); ++iter)
				*iter = *iter + ' ' + w;
			
			result.insert(result.begin(), left.begin(), left.end());	
		}
		return result;
    
    }
};