class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		
		if(num.size() < 3) return -1;
		int sum = 0;
		int res = 50000;
		DFS(num, target, 0, 0, sum, res);
		return res;
    }
	
	void DFS(vector<int> & num, int target, int index, int temp, int &sum, int &res) {
		
		if(index > num.size())
			return;
		
		if(temp > 3)
			return;
		
		else if(temp == 3 && abs(sum - target) < abs(res - target)) 
		{
			res = sum;
			return;
		}
		else if(temp < 3){
			for(int i = index; i < num.size(); ++i) {
				sum += num[i];
				DFS(num, target, i + 1, temp + 1, sum, res);
				sum -= num[i];
			}	
		}		
	}
	
};