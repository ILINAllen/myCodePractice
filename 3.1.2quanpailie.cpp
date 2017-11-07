#include<iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
void perm(int list[],int m,int begin)
{
	if(begin==m)
	{
		for(int i=0;i<m;i++)
			cout<<list[i];
		cout<<endl;	
	}
	for(int j=begin;j<m;j++)
	{
		swap(list[begin],list[j]);
		perm(list,m,begin+1);
		swap(list[begin],list[j]);
	}	
}




int main()
{
	int list[]={1,2,3};
	
	perm(list,3,0);
	return 0;

}

