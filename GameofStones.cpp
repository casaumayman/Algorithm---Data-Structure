#include<bits/stdc++.h>
using namespace std;
int T,n;
int Grundy[101];
int calMeg(unordered_set <int> us){
    int res = 0;
    while (us.find(res) != us.end()) res++;
    return res;
}
int calGrundy(int x){
    if (Grundy[x] != -1) return Grundy[x];
    unordered_set <int> us;
    us.insert(calGrundy(x-2));
    us.insert(calGrundy(x-3));
    us.insert(calGrundy(x-5));
    Grundy[x] = calMeg(us);
    return Grundy[x];
}
void Process(){
    memset(Grundy,-1,sizeof(Grundy));
    Grundy[0] = 0;
    Grundy[1] = 0;
    Grundy[2] = 1;
    Grundy[3] = 1;
    Grundy[4] = 2;
    Grundy[5] = 2;
    cin>>n;
//    for (int i=1;i<=n;i++) cout<<calGrundy(i)<<"\n";
    if (calGrundy(n)!=0) cout<<"First\n";
    else cout<<"Second\n";
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
