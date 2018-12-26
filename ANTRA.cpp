#include<bits/stdc++.h>
using namespace std;
int dem[13];
int so(char c)
{
	switch (c)
	{
		case '3': return 0; break;
		case '4': return 1; break;
		case '5': return 2; break;
		case '6': return 3; break;
		case '7': return 4; break;
		case '8': return 5; break;
		case '9': return 6; break;
		case 'T': return 7; break;
		case 'J': return 8; break;
		case 'Q': return 9; break;
		case 'K': return 10; break;
		case 'A': return 11; break;
		case '2': return 12; break;
	}
}
void nhap()
{
	char c,j;
	for (int i=1;i<=13;i++)
	{
		cin>>c>>j;
		dem[so(c)]++;
	}
}
bool diff()
{
	for (int i=0;i<13;i++)
		if (!dem[i]) return false;
	return true;
}
bool tuquy2()
{
	return (dem[12]==4);
}
bool namdoithong()
{
	for (int i=0;i<=8;i++)
	{
		int t=0;
		for (int j=i;j<=i+4;j++)
			if (dem[j]>1) t++;
		if (t==5) return true;
	}
	return false;
}
bool saudoibk()
{
	int t=0;
	for (int i=0;i<13;i++)
	{
		t+=dem[i]/2;
	}
	return (t==6);
}
int main()
{
	nhap();
	if (tuquy2() || namdoithong() || diff() || saudoibk()) cout<<"YES";
	else cout<<"NO";
	return 0;
}
