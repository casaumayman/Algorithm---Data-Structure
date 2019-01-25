#include<bits/stdc++.h>
using namespace std;
int k,m,n,T;
int a[51][51],b[3][51];
int dx[8] = {-1,-2,-1,0,1,2,1,0};
int dy[8] = {1,0,-1,-2,-1,0,1,2};
void Input(){
    cin>>m>>n;
    k = 0;
}
bool valid(int x,int y,bool isInit){
    if (isInit){
        if (x>=1 && x<=50 && y>=1 && y<=50) return true;
        return false;
    }
    if (x>=1 && x<=m && y>=1 && y<=n) return true;
    return false;
}
int calc(int x,int y,int a[51][51],bool isInit){
    int xx,yy;
    unordered_set <int> myset;
    for (int k=0;k<8;k++){
        xx = x+dx[k];
        yy = y+dy[k];
        if (valid(xx,yy,isInit) && a[xx][yy]!=-1){
            myset.insert(a[xx][yy]);
        }
    }
    int value = 1;
    while (myset.find(value)!=myset.end()) value++;
    return value;
}
void init(){
    for (int i=1;i<=50;i++)
        for (int j=1;j<=50;j++){
            a[i][j] = calc(i,j,a,true);
    }
}
void Process(){
    Input();
    if (m==2 || n==2){
        if (m==2){
            if (n==1)
                cout<<"1\n";
            else if (n==2)
                cout<<"2\n";
            else
                cout<<"3\n";
            for (int i=0;i<n;i++){
                cout<<(i%3)+1<<" ";
            }
            cout<<"\n";
            for (int i=0;i<n;i++){
                cout<<(i%3)+1<<" ";
            }
            cout<<"\n";
        }
        else{
            if (m==1)
                cout<<"1\n";
            else if (m==2)
                cout<<"2\n";
            else
                cout<<"3\n";
            for (int i=0;i<m;i++){
                cout<<(i%3)+1<<" "<<(i%3)+1<<"\n";
            }
            cout<<"\n";
        }
    }
    else{
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++) if (a[i][j]>k) k=a[i][j];
        cout<<k<<"\n";
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++) cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
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
