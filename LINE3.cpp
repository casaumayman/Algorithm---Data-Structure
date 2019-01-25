#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,ex,ey;
int trace[1000];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool visited[1000],found = false;
bool a[31][31];
void Input(){
    cin>>n>>sx>>sy>>ex>>ey;
    int x;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++){
        cin>>x;
        a[i][j]=(bool)x;
    }
}
int number(int x,int y){
    return (x*n+y);
}
pair <int,int> bung(int k){
    pair <int,int> t;
    t.first = (k/n);
    t.second = k%n;
    if (!t.second){
        t.second = n;
        t.first--;
    }
    return t;
}
void BFS(){
    int x,y,xx,yy,hast;
    queue <int> que;
    int start = number(sx,sy);
    visited[start] = true;
    que.push(start);
    while(!que.empty()){
        int temp = que.front();
        que.pop();
        x = bung(temp).first;
        y = bung(temp).second;
        for (int i=0;i<4;i++){
            xx = x + dx[i];
            yy = y + dy[i];
            hast = number(xx,yy);
            if (xx>=1 && xx<=n && yy>=1 && yy<=n && !a[xx][yy] && !visited[hast]){
                que.push(hast);
                visited[hast] = true;
                trace[hast] = temp;
                if (xx==ex && yy==ey) {
                    found = true;
                    return;
                }
            }
        }
    }
}
void Output(){
    if (!found){
        cout<<0;
        return;
    }
    vector <int> kq;
    int start = number(sx,sy);
    int endd = number(ex,ey), t = endd;
    while (t != start){
        kq.push_back(t);
        t = trace[t];
    }
    cout<<kq.size()+1<<"\n";
    cout<<sx<<" "<<sy<<"\n";
    int x,y;
    for (int i=kq.size()-1;i>=0;i--){
        x = bung(kq[i]).first;
        y = bung(kq[i]).second;
        cout<<x<<" "<<y<<"\n";
    }
}
void Process(){
    Input();
    BFS();
    Output();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
