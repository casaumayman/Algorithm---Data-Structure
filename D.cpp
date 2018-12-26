#include<bits/stdc++.h>
using namespace std;
int n;
bool a,b,c;
void Input(){
    cin>>n;
    int x;
    for (int i=1;i<=n;i++){
        cin>>x;
        if (x == 1) a = true;
        else if (x == 2) b = true;
        else c = true;
    }
}
void Process(){
    Input();
    int res;
    if (!a && !b && !c) res = 48;
    if (a && !b && !c) res = 35;
    if (!a && b && !c) res = 35;
    if (!a && !b && c) res = 35;
    if (a && b && !c) res = 25;
    if (a && !b && c) res = 25;
    if (!a && b && c) res = 25;
    if (a && b && c) res = 17;
    cout<<res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
