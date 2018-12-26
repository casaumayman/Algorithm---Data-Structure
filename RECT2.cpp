#include<bits/stdc++.h>
using namespace std;
int x1,x2,x3,y_1,y2,y3;
int main()
{
	cin>>x1>>y_1>>x2>>y2>>x3>>y3;
	x1=x1 xor x2 xor x3;
	y_1=y_1 xor y2 xor y3;
	cout<<x1<<" "<<y_1;
	return 0;
}
