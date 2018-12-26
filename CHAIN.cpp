#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Process(){
    Input();
    int res = 0,coun = n;
    for (int i=1;i<=n;i++){
        if (a[i] < coun-1){
            res += a[i];
            coun -= a[i]+1;
            if (coun == 1) break;
        }
        else{
            res += coun-1;
            break;
        }
    }
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
