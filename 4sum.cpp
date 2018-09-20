class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		set<vector<int> > st;
		vector<int> temp;
		if(num.size() < 4) return res;
		
		sort(num.begin(), num.end());
		int sum = 0;
		DFS(st, temp, num, 0, sum, target);
		
		for(auto it = st.begin(); it != st.end(); ++it) {
			res.push_back(*it);
		}
		return res;
    }
	
	void DFS(set<vector<int> > & st, vector<int> & temp, vector<int> &num, int index, int &sum, int target) {
				
		if(index > num.size())
			return;
		if(temp.size() >= 4 && sum != target)
			return;
		
		else if(temp.size() == 4 && sum == target) {
			st.insert(temp);
			return;
		
		}			
		else {	
			for(int i = index; i < num.size(); ++i) {
				sum += num[i];
				temp.push_back(num[i]);
				DFS(st, temp, num, i + 1, sum, target);
				temp.pop_back();
				sum -= num[i];
			}			
		} 
	}
	
	
};