#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool choose[16];
string s;
set <ll> kq;
void Input(){
    cin>>s;
}
ll toNumber(){
    ll t = 0;
    ll temp = 1;
    for (int i=s.size()-1;i>=0;i--){
        if (choose[i]){
            t += (s[i]-'0') * temp;
            temp *= 10;
        }
    }
    return t;
}
void submit(int i){
    if (i==s.size()){
        ll num = toNumber();
        if (num%3 == 0) kq.insert(num);
        return;
    }
    for (int j=0;j<=1;j++){
        choose[i] = j;
        submit(i+1);
    }
}
void Process(){
    Input();
    submit(0);
    cout<<kq.size();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
