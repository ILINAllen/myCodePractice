/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		
		if (points.size() == 0)return 0;
		if (points.size() == 1)return 1;
		
		
		
		int maxnum = 1;
		for(int i = 0; i < points.size(); ++i)
		{
			
			int vcnt = 0;
			int dupnum = 0;
			int tempmaxnum = 1;
			map<double, int>kmap;
			for(int j = 0; j < points.size(); ++j)
			{
				
				if(i != j)
				{
					double x1 = points[i].x - points[j].x;
					double y1 = points[i].y - points[j].y;	
					if(x1 == 0 && y1 == 0)
					{
						dupnum++;
					}
					else if(x1 == 0)
					{
						if(vcnt == 0)
							vcnt = 2;
						else
							vcnt++;
						tempmaxnum = max(vcnt, tempmaxnum);
					}
					else
					{
						if(kmap[y1/x1] == 0)
							kmap[y1/x1] = 2;
						else
							kmap[y1/x1]++;
						tempmaxnum = max(kmap[y1/x1], tempmaxnum);
					}					
				}

			}
			maxnum = max(maxnum, tempmaxnum + dupnum);
			

		}

		return maxnum;
    }
};