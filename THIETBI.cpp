#include<bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int A[100005];
bool check[100005], change[100005];

void procc()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n;i++)
	{
		cin >> A[i];
		if(A[i]>n || check[A[i]])
			change[i] = true;
		else
			check[A[i]] = true;
	}
	int j = 1;
	for(int i = 1;i <=n;i++)
	{
		if(!change[i])
			cout << A[i] << " ";
		else
		{
			while(check[j]){
				j++;
			} 
			cout << j << " ";
			check[j] = true;
		}
	}
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	procc();
	return 0;
}

