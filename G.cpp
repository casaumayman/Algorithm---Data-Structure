#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,1,-1};
struct cell{
    int x,y,mins;
    cell(){}
    cell(int a,int b,int c){
        x = a;
        y = b;
        mins = c;
    }
};
int n,m;
int sx,sy,fx,fy;
bool invalid;
int a[5001][5001];
queue <cell> que;
void Input(){
    cin>>n>>m;
    int x,y;
    cin>>sx>>sy>>fx>>fy;
    if (((sx + sy) % 2) != ((fx + fy) % 2)) invalid = true;
    for (int i=1;i<=m;i++) {
        cin>>x>>y;
        a[x][y]=INT_MAX;
    }
}
bool check(int x,int y){
    if (x<1 || x>n || y<1 || y>n) return false;
    if (a[x][y]==INT_MAX) return false;
    return true;
}
void Process(){
    Input();
    if (invalid) {
        cout<<-1;
        return;
    }
    if (sx == fx && sy == fy) {
        cout<<0;
        return;
    }
    que.push(cell(sx,sy,0));
    a[sx][sy] = -1;
    cell temp;
    cell temp2;
    while (!que.empty()){
        temp = que.front();
        que.pop();
        if (temp.x == fx && temp.y == fy){
            break;
        }
        a[temp.x][temp.y] = temp.mins;
        for (int i=0;i<4;i++){
            for (int j=1;check(temp.x+j*dx[i],temp.y+j*dy[i]);j++){
                if (a[temp.x+j*dx[i]][temp.y+j*dy[i]] == 0 ||    a[temp.x+j*dx[i]][temp.y+j*dy[i]]>temp.mins+1) {
                    a[temp.x+j*dx[i]][temp.y+j*dy[i]] = temp.mins + 1;
                    que.push(cell(temp.x+j*dx[i],temp.y+j*dy[i],temp.mins+1));
                }
            }
        }
    }
    if (!a[fx][fy]) cout<<-1<<"\n";
    else cout<<a[fx][fy]<<"\n";
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++) cout<<((a[i][j]==INT_MAX)?9:a[i][j])<<" ";
//        cout<<"\n";
//    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
