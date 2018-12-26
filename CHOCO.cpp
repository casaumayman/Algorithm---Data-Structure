#include<bits/stdc++.h>
using namespace std;
int a,b;
void Process(){
    cin>>a>>b;
    int temp = a*b-1;
    if (temp%2==0) cout<<"2";
    else cout<<"1";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
