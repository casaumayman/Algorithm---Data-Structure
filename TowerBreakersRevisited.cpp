#include<bits/stdc++.h>
using namespace std;
int Grundy[1000001],T;
int calcMeg(unordered_set <int> Set){
    int Meg = 0;
    while (Set.find(Meg) != Set.end()) Meg++;
    return Meg;
}
int calcGrundy(int x){
    if (Grundy[x] != -1) return Grundy[x];
    int sqr = sqrt(x);
    unordered_set <int> Set;
    for (int i=2;i<=sqr;i++)
        if (x%i==0){
            Set.insert(calcGrundy(i));
            Set.insert(calcGrundy(x/i));
        }
    Set.insert(0);
    Grundy[x] = calcMeg(Set);
    return Grundy[x];
}
void init(){
    memset(Grundy,-1,sizeof(Grundy));
    Grundy[0] = 0;
    Grundy[1] = 0;
}
void Process(){
    int n,x,xorVal = 0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x;
        xorVal ^= calcGrundy(x);
    }
    cout<<(xorVal?"1\n":"2\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	init();
	cin>>T;
	while (T--) Process();
	return 0;
}
