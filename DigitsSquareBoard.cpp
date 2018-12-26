#include<bits/stdc++.h>
using namespace std;
int n,num[31][31],T;
int Grundy[31][31][31][31];
bool isPrime(int x){
    if (x==2 || x==3 || x==5 || x==7) return true;
    return false;
}
int calcMeg(unordered_set<int> Set){
    int Meg = 0;
    while (Set.find(Meg) != Set.end()) Meg++;
    return Meg;
}
bool check_quare(int a,int b,int x,int y){
    if (a == x && y == b) return false;
    for (int i=a; i<=x; i++)
        for (int j=b;j<=y;j++)
            if (!isPrime(num[i][j])) return true;
    return false;
}
int calcGrundy(int a,int b,int x,int y){
    if (Grundy[a][b][x][y] != -1) return Grundy[a][b][x][y];
    if (!check_quare(a,b,x,y)) {
        Grundy[a][b][x][y] = 0;
        return 0;
    }
    unordered_set <int> Set;
    for (int i=b;i<=y-1;i++)
    {
        Set.insert(calcGrundy(a,b,x,i)^calcGrundy(a,i+1,x,y));
    }
    for (int i=a;i<=x-1;i++)
    {
        Set.insert(calcGrundy(a,b,i,y)^calcGrundy(i+1,b,x,y));
    }
    Grundy[a][b][x][y] = calcMeg(Set);
    return Grundy[a][b][x][y];
}
void init(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          for (int k=1;k<=n;k++)
            for (int l=1;l<=n;l++)
              Grundy[i][j][k][l] = -1;
}
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>num[i][j];
}
void Process(){
    Input();
    init();
    int win = calcGrundy(1,1,n,n);
    cout<<((win==0)?"Second\n":"First\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while(T--) Process();
	return 0;
}
