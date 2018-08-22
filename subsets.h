class Solution {
public:
	static bool myCompare(const vector<int>& a1,const vector<int>& a2)
	{
		if(a1.size() < a2.size()) 
			return true;
		else if(a1.size() == a2.size())
			return a1 < a2;
		else
			return false;
	}
	void DFS(vector<vector<int> > & res, vector<int> &vec, vector<int> &S, int sindex)
	{
		res.push_back(vec);
		for(int i = sindex; i < S.size(); ++i)
		{
			vec.push_back(S[i]);
			DFS(res, vec, S, i + 1);
			vec.pop_back();
		}
	}
	
    vector<vector<int> > subsets(vector<int> &S) {

		vector<vector<int> > res;	
		vector<int> vec;
		sort(S.begin(), S.end());
		DFS(res, vec, S, 0);
		sort(res.begin(), res.end(), myCompare);
		return res;
    }

};