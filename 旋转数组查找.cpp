class Solution {
public:
    int search(int A[], int n, int target) {

		int low = 0;
		int high = n - 1;
		
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			if(A[mid] == target)
				return mid;
			
			if(A[low] <= A[mid]) {   //左侧有序
				if(A[low] <= target && target < A[mid]) {
					high = mid - 1;
				}
				else 
					low = mid + 1;
			
			}
			else {    //右侧有序
				if(A[mid] < target && target <= A[high])
				{
					low = mid + 1;
				}
				else
					high = mid - 1;
			}
		}
		return -1;
    }
};