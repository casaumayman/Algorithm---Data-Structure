#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1001][1001],b[1001][1001];
bool visited[1001][1001];
int sx,sy,fx,fy;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
struct kq{
    kq bak;
    kq now;
    kq(){}
    kq(ele a,ele b1){
        bak = a;
        bak = b;
    }
};
queue <kq> st;
bool check(int x,int y,char c){
    if (x<1 || x>m) return false;
    if (y<1 || y>n) return false;
    if (visited[x][y]) return false;
    if (a[x][y]=='#' && c=='a') return false;
    if (b[x][y]=='#' && c=='b') return false;
    return true;
}
void Input(){
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='S'){
                sx = i;
                sy = j;
            }
            if (a[i][j]=='F'){
                fx = i;
                fy = j;
            }
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>b[i][j];
}
vector <ele> kq_a,kq_b;
void trace(kq t,char c){
    if (c=='a'){
        while (t.bak.x!=-1)
    }
}
void Process(){
    Input();
    int res=-1,xx,yy;
    visited[sx][sy] = true;
    st.push(kq(ele(-1,-1,-1),ele(sx,sy,1)));
    kq t;
    while (!st.empty()){
        t = st.front();
        st.pop();
        if (t.now.x == fx && t.now.y == fy) {
            trace(t,'a');
            break;
        }
        for (int i=0;i<4;i++){
            xx = t.x + dx[i];
            yy = t.y + dy[i];
            if (check(xx,yy)){
                visited[xx][yy] = true;
                st.push(ele(xx,yy,t.step+1));
            }
        }
    }
    if (res == -1) cout<<res;
    else cout<<res - 2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
