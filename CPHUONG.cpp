#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	//Code
	cin>>n;
	int x = sqrt(n);
	if (x * x == n){
        cout<<"YES";
	}
	else cout<<"NO";
	return 0;
}
