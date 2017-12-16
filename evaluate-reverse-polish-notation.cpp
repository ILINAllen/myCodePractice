/**
 ＊
 *  1.这种逆波兰表达式，很明显，用栈求解。
 *  2.需要注意的一点，就是来一个新的符号的时候，将栈中的两个值取出进行操作，再放回栈中。
 *    此时先取出的为num2,后取出的为num1，进行num1 (+-/*) num2 操作
 *
 **/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    
		if(tokens.size() < 2)return 0;
		stack<int> st;
		
		for(auto s: tokens)
		{
			if((s == "+") || (s == "-") || (s == "*") || (s == "/"))
			{
				if(st.size() < 2)return 0;
				int num2 = st.top();
				st.pop();
				int num1 = st.top();
				st.pop();
				
				int res = 0;
				if(s == "+")
					res = num1 + num2;
				else if(s == "-")
					res = num1 - num2;
				else if(s == "*")
					res = num1 * num2;
				else if(s == "/")
					res = num1 / num2;
				
				st.push(res);
			}
			else
				st.push(stoi(s));	
		}
		if(st.size() == 1)return st.top();
		else return 0;
    }
};