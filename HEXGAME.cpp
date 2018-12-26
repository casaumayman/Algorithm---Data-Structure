#include<bits/stdc++.h>
using namespace std;
struct Hex
{
    char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
	char buoc;
} temp;
bool check(Hex a)
{
	if (a.a1==1 &&
		a.a2==2 &&
		a.a3==3 &&
		a.a4==8 &&
		a.a5==0 &&
		a.a6==0 &&
		a.a7==4 &&
		a.a8==7 &&
		a.a9==6 &&
		a.a10==5) return true;
	return false;
}
Hex xoay1(Hex a)
{
	/*
	   a1  a2  a3
	a4	 a5	 a6   a7
	   a8  a9  a10
	*/
	Hex i;
	i.buoc=a.buoc+1;
	i.a5=a.a5;
	i.a3=a.a3;
	i.a7=a.a7;
	i.a10=a.a10;
	i.a4=a.a8;
	i.a8=a.a9;
	i.a9=a.a6;
	i.a6=a.a2;
	i.a2=a.a1;
	i.a1=a.a4;
	return i;
}
Hex xoay2(Hex a)
{
	Hex i;
	i.a6=a.a6;
	i.a1=a.a1;
	i.a4=a.a4;
	i.a8=a.a8;
	i.a5=a.a9;
	i.a9=a.a10;
	i.a10=a.a7;
	i.a7=a.a3;
	i.a3=a.a2;
	i.a2=a.a5;
	i.buoc=a.buoc+1;
	return i;
}
void Process()
{	
	scanf("%d %d %d\n",&temp.a1,&temp.a2,&temp.a3);
	scanf("%d %d %d %d\n",&temp.a4,&temp.a5,&temp.a6,&temp.a7);
	scanf("%d %d %d",&temp.a8,&temp.a9,&temp.a10);
	queue <Hex> que;
	temp.buoc=0;
	que.push(temp);
	Hex k1;
	while (!que.empty())
	{
		temp=que.front();
		que.pop();
		k1=xoay1(temp);
		if (check(k1))
		{
			printf("%d",k1.buoc);
			break;
		}
		que.push(k1);
		k1=xoay2(temp);
		if (check(k1))
		{
			printf("%d",k1.buoc);
			break;
		}
		que.push(k1);
	}
}
int main()
{
	Process();
	return 0;
}
