#include <bits/stdc++.h>
using namespace std;
int n;
struct cmp{
    bool operator() (int a,int b) {return a>b;}
};
multiset <int,cmp> myset;
int main(){
    srand(time(NULL));
    cin>>n;
    for (int i=1;i<=n;i++) myset.insert(rand()%100);
    for (auto x:myset) cout<<x<<" ";
    int m;
    cin>>m;
    auto it = myset.upper_bound(m);
    //it--;
    cout<<*it;
    return 0;
}
