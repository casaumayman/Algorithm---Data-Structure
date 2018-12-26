#include<bits/stdc++.h>
using namespace std;
int dd,mm,yy;
int main()
{
	cin>>dd>>mm>>yy;
	if ((yy%4==0 && yy%100!=0) || yy%400==0)
		if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
			if (dd==31)
			{
				dd=1;
				if (mm==12)
				{
					mm=1;
					yy++;
				}
				else mm++;
			}
			else dd++;
		else if (mm==2)
			if (dd==29)
			{
				dd=1;
				mm++;
			}
			else dd++;
		else
			if (dd==30)
			{
				dd=1;
				mm++;
			}
			else dd++;
	else
		if (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
			if (dd==31)
			{
				dd=1;
				if (mm==12)
				{
					mm=1;
					yy++;
				}
				else mm++;
			}
			else dd++;
		else if (mm==2)
			if (dd==28)
			{
				dd=1;
				mm++;
			}
			else dd++;
		else
			if (dd==30)
			{
				dd=1;
				mm++;
			}
			else dd++;
	cout<<dd<<" "<<mm<<" "<<yy;
	return 0;
} 
