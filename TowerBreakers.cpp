#include<bits/stdc++.h>
using namespace std;
int T,n,m;
void Process(){
    cin>>n>>m;
    if (m==1){
        cout<<"2\n";
        return;
    }
    if (n%2==0) cout<<"2\n";
    else cout<<"1\n";
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
