#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ele{
    ll real_value;
    double fake_value;
    int type;
};
bool cmp(ele x,ele y){
    if (x.fake_value < y.fake_value) return true;
    return false;
}
vector <ele> myvec;
int n,q;
ll kq[100001];
void Input(){
    cin>>n>>q;
    ll x,y;
    ele t;
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        t.real_value = x;
        t.fake_value = x + 0.2;
        t.type = 0;
        myvec.push_back(t);
        t.real_value = y;
        t.fake_value = y - 0.2;
        t.type = 1;
        myvec.push_back(t);
    }
    for (int i=1;i<=q;i++){
        cin>>x>>y;
        t.real_value = x;
        t.fake_value = x + 0.3;
        t.type = i + 2;
        myvec.push_back(t);
        t.real_value = y;
        t.fake_value = y - 0.3;
        t.type = i + 2;
        myvec.push_back(t);
    }
    sort(myvec.begin(),myvec.end(),cmp);
}
void Process(){
    Input();
    ll res = 0;
    ll coun = 0,temp = 0;
    ll pos;
    for (int i=0;i<myvec.size();i++){
        if (myvec[i].type > 1){
            pos = myvec[i].type - 2;
            res += coun*(myvec[i].real_value - temp);
            temp = myvec[i].real_value;
            if (!kq[pos]) kq[pos] = res;
            else kq[pos] = res - kq[pos];
        }
        else{
            res += coun*(myvec[i].real_value - temp);
            if (myvec[i].type == 0) coun++;
            else coun--;
            temp = myvec[i].real_value;
        }
        //cout<<myvec[i].real_value<<" "<<myvec[i].type<<" "<<res<<"\n";
    }
    for (int i=1;i<=q;i++) cout<<kq[i]<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
