#include<bits/stdc++.h>
using namespace std;
int T;
void Process(){
    int n,x,xorVal = 0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x;
        xorVal ^= x;
    }
    cout<<(xorVal?"First\n":"Second\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}
