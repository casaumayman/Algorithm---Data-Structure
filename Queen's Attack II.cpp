#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int n,k,X,Y;
pair <int,int> a[100001];
void Input(){
    cin>>n>>k;
    cin>>X>>Y;
    for (int i=1;i<=k;i++)
        cin>>a[i].x>>a[i].y;
}
bool check(int x,int y){
    if (x<1 || x>n || y<1 || y>n) return false;
    return true;
}
void Process(){
    Input();
    int d1,d2,d3,d4,c1,c2,c3,c4;
    d1 = Y - 1;
    d2 = X - 1;
    d3 = n - Y;
    d4 = n - X;
    c1 = min(d1,d2);
    c2 = min(d3,d2);
    c3 = min(d3,d4);
    c4 = min(d4,d1);
    for (int i=1;i<=k;i++){
        if ((a[i].y < Y) && (a[i].x == X)) d1 = min(d1,Y - a[i].y - 1);
        if ((a[i].x < X) && (a[i].y == Y)) d2 = min(d2,X - a[i].x - 1);
        if ((a[i].y > Y) && (a[i].x == X)) d3 = min(d3,a[i].y - Y - 1);
        if ((a[i].x > X) && (a[i].y == Y)) d4 = min(d4,a[i].x - X - 1);
        if ((X - a[i].x == Y - a[i].y) && (a[i].x < X)) c1 = min(c1, X - a[i].x - 1);
        if ((a[i].x + a[i].y)==(X+Y) && (a[i].x < X)) c2 = min(c2, X - a[i].x - 1);
        if ((X - a[i].x == Y - a[i].y) && (a[i].x > X)) c3 = min(c3, a[i].x - X - 1);
        if ((a[i].x + a[i].y)==(X+Y) && (a[i].x > X)) c4 = min(c4, a[i].x - X - 1);
    }
    cout<<d1+d2+d3+d4+c1+c2+c3+c4;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
