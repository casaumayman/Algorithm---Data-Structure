#include<bits/stdc++>
using namespace std;
int T,n,A,B,cA,cB,cAB;
void Input(){
    cin>>n>>A>>B;
    int x;
    cA = cB = cAB = 0;
    for (int i=1;i<=n;i++){
        cin>>x;
        if ((x%A==0) && (x%B==0)) cAB++;
        else if (x%A==0) cA++;
        else if (x%B==0) cB++;
    }
}
void Process(){
    Input();
    if (cAB%2==0){
        if (cA > cB) cout<<"BOB\n";
        else cout<<"ALICE\n";
    } else {
        if (cB > cA) cout<<"ALICE\n";
        else cout<<"BOB\n";
    }
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
