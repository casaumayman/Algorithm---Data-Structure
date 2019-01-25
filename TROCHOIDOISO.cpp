#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
typedef pair<int,int> ii;
int visited[1001001];
int number(int x,int y){
    return (x*1000+y);
}
ii bung(int k){
    ii t;
    t.first = k/1000;
    t.second = k%1000;
    if (!t.second) {
        t.second = 1000;
        t.first--;
    }
    return t;
}
bool valid(int x,int y){
    if (x>=1 && x<=1000 && y>=1 && y<=1000) return true;
    return false;
}
void BFS(){
    queue <int> que;
    int start = number(a,b);
    que.push(start);
    memset(visited,-1,sizeof(visited));
    visited[start] = 0;
    int x,y,xx,yy,hast;
    while (!que.empty()){
        int temp = que.front();
        que.pop();
        x = bung(temp).first;
        y = bung(temp).second;
        xx = x+y;
        yy = y;
        if (valid(xx,yy) && visited[number(xx,yy)] == -1){
            hast = number(xx,yy);
            visited[hast] = visited[temp]+1;
            que.push(hast);
            if (xx == c && yy == d) return;
        }
        xx = y;
        yy = x;
        if (valid(xx,yy) && visited[number(xx,yy)] == -1){
            hast = number(xx,yy);
            visited[hast] = visited[temp]+1;
            que.push(hast);
            if (xx == c && yy == d) return;
        }
        xx = x-y;
        yy = y;
        if (valid(xx,yy) && visited[number(xx,yy)] == -1){
            hast = number(xx,yy);
            visited[hast] = visited[temp]+1;
            que.push(hast);
            if (xx == c && yy == d) return;
        }
    }
}
void Process(){
    cin>>a>>b>>c>>d;
    BFS();
    if (visited[number(c,d)]==-1){
        cout<<-1;
        return;
    }
    cout<<visited[number(c,d)];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
