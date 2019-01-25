#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_pow = 38;
ll M,t;
ll powof[39];
bool kql[39],kqr[39];
void Init(){
    powof[0] = 1;
    for (int i=1;i<=max_pow;i++) powof[i] = powof[i-1]*3;
}
int find_pow(ll x){
    int l = 0, r = max_pow, m=(l+r)/2;
    int temp = -1;
    while (l<=r){
        if (powof[m] <= x){
            temp = m;
            l = m+1;
        } else r = m - 1;
        m = (l+r)/2;
    }
    return temp;
}
bool check(ll x){
    int f = find_pow(x);
    //cout<<f<<"\n";
    for (int i = f;i>=0;i--){
        if (x >= powof[i]){
            x -= powof[i];
            kqr[i] = true;
        } else kqr[i] = false;
    }
    if (x == 0) return true;
    return false;
}
void next_number(){
    int i=0;
    while (kql[i]){
        kql[i] = false;
        t -= powof[i];
        i++;
    }
    kql[i] = true;
    t += powof[i];
}
void Process(){
    cin>>M;
    while (!check(t+M)){
        next_number();
    }
    bool found = false;
    cout<<t<<": ";
    for (int i=0;i<=38;i++) if (kql[i]){
        cout<<i<<" ";
        if (!found) found = true;
    }
    if (!found) cout<<"-1";
    cout<<"\n";
    cout<<t+M<<": "; for (int i=0;i<=38;i++) if (kqr[i]) cout<<i<<" ";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Init();
	Process();
	return 0;
}
