#include<bits/stdc++.h>
using namespace std;
int T,n;
void Process(){
    cin>>n;
    bool just_one = true;
    int XorVal = 0,x;
    for (int i=1;i<=n;i++){
        cin>>x;
        if (just_one && x != 1) just_one = false;
        XorVal ^= x;
    }
    if (just_one){
        cout<<((n%2==0)?"First\n":"Second\n");
        return;
    }
    cout<<(XorVal?"First\n":"Second\n");
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
