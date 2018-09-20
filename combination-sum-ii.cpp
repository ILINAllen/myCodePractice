class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > res;
		if(num.size() <= 0 || target <= 0)
			return res;
		set<vector<int> > st;
		vector<int> vec;
		sort(num.begin(), num.end());
		DFS(st, vec, num, target, 0);
		for(auto it = st.begin(); it != st.end(); ++it)
		{
			res.push_back(*it);
		}
		return res;
    }
	
	void DFS(set<vector<int> > &st, vector<int> &vec, vector<int> &num, int target, int start) {
		
		if(start > num.size())
			return;
		
		int sum = 0;
		for(int i = 0; i < vec.size(); ++i)
		{
			sum += vec[i];
		}
		if(sum == target)
		{
			st.insert(vec);
			return;
		}else if(sum > target)
		{
			return;
		}
		else
		{		
			for(int i = start; i < num.size(); ++i)
			{
				vec.push_back(num[i]);
				DFS(st, vec, num, target, i + 1);
				vec.pop_back();
			}	
		}
		
	}
	
	
};