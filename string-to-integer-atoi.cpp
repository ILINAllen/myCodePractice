class Solution {
public:
int atoi(const char *str) {
	int l = strlen(str);
	int i = 0, flag = 1;

	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+')
	{
		i++;
        break;   
	}
	while (str[i] == '-')
	{
		i++;
		flag = -1;
        break;
	}

	int num = 0;
	for (; i < l; i++)
	{
		if(str[i] < '0' || str[i] > '9')break;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
			return flag == -1 ? INT_MIN : INT_MAX;
		num = num * 10 + str[i] - '0';
	}
	return num * flag;

}
};