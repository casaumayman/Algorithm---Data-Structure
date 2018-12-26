#include<bits/stdc++.h>
using namespace std;
int Grundy[16][16],T;
int dx[4] = {-2,-2,1,-1};
int dy[4] = {1,-1,-2,-2};
void init(){
    memset(Grundy,-1,sizeof(Grundy[0][0])*16*16);
    Grundy[1][1] = 0;
}
int calcMeg(unordered_set <int> Set){
    int Meg = 0;
    while (Set.find(Meg) != Set.end()) Meg++;
    return Meg;
}
bool check(int x,int y){
    if (x<1 || x>15) return false;
    if (y<1 || y>15) return false;
    return true;
}
int calcGrundy(int x,int y){
    if (Grundy[x][y] != -1) return Grundy[x][y];
    unordered_set <int> Set;
    int xx,yy;
    for (int i=0;i<4;i++){
        xx = x + dx[i];
        yy = y + dy[i];
        if (check(xx,yy)) Set.insert(calcGrundy(xx,yy));
    }
    Grundy[x][y] = calcMeg(Set);
    return Grundy[x][y];
}
void Process(){
    int n,xorVal = 0,x,y;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        xorVal ^= calcGrundy(x,y);
    }
    cout<<(xorVal?"First\n":"Second\n");
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
