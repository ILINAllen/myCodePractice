class Solution {
public:
    int maxArea(vector<int> &height) {
    
		int maxnum = 0;
		for(int l = 0, r = height.size() - 1; l < r; )
		{
			maxnum = max(maxnum, (r - l)*min(height[l], height[r]));
			if (height[l] < height[r]) 
				l++;
			else
				r--;
		}
		return maxnum;
    }
};