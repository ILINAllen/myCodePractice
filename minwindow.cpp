class Solution {
public:
	string minWindow(string S, string T) {

		int TMap[128] = { 0 };

		for (int i = 0; i < T.size(); ++i)
		{
			TMap[T[i]]++;
		}

		int begin = 0, end = 0, head = 0, len = INT_MAX, count = 0;

		count = T.size();

		while (end < S.size())
		{

			if (TMap[S[end]] > 0)
			{
				count--;
			}
			TMap[S[end]]--;
			end++;

			while (count == 0)
			{
				
				if (len > (end - begin))
				{
					len = end - begin;
					head = begin;
				}

				if (TMap[S[begin]] == 0)
				{
					count++;
				}
				TMap[S[begin]]++;
				begin++;
			}
		}
		return len == INT_MAX ? "" : S.substr(head, len);
	}
};