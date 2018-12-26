#include<bits/stdc++.h>
using namespace std;
int n,k;
struct cmp{
    bool operator() (int a,int b) {return a>b;}
};
multiset <int,cmp> myset;
void Input(){
    cin>>n>>k;
    int x;
    for (int i=1;i<=n;i++){
        cin>>x;
        myset.insert(x);
    }
}
void Process(){
    Input();
    long long res = 0;
    while (!myset.empty()){
        auto it = myset.begin();
        res += *it;
        //cout<<*it<<"\n";
        while (it!=myset.end()){
            auto itf = myset.upper_bound((*it) - k + 1);
            myset.erase(it);
            it = itf;
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
