#include<bits/stdc++.h>
using namespace std;
char x[21];
int n,coun;
bool check()
{
	stack <char> st;
	for (int i=1;i<=n;i++)
		if (x[i]=='(') st.push('(');
		else 
		{
			if (st.empty()) return false;
			else st.pop();
		}
	if (!st.empty()) return false;
	return true;
}
char ele(int i)
{
	return (i==1)?'(':')';
}
void xuat()
{
	coun++;
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<"\n";
}
void submit(int i)
{
	for (int j=1;j<=2;j++)
	{
		x[i]=ele(j);
		if (i==n) 
			if (check()) xuat(); else;
		else submit(i+1);
	}
}
int main()
{
	cin>>n;
	submit(1);
	cout<<coun;
	return 0;
}
