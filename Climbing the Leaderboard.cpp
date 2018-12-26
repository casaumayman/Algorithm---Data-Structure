#include<bits/stdc++.h>
using namespace std;
int n,m,scores[200001],alice[200001],ranking[200001];
int rank_min;
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>scores[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>alice[i];
    int indx = 1;
    ranking[1] = 1;
    for (int i=2;i<=n;i++){
        if (scores[i]==scores[i-1]) ranking[i] = indx;
        else ranking[i] = ++indx;
    }
    rank_min = indx;
}
int pos_find(int l,int r,int x){
    int ll = l,rr = r,m = (ll+rr)/2,temp = 0;
    while (ll <= rr){
        if (scores[m] <= x){
            temp = m;
            rr = m-1;
        }
        else ll = m+1;
        m = (ll+rr)/2;
    }
    return temp;
}
void Process(){
    Input();
    int last = n,pos;
    for (int i=1;i<=m;i++){
        pos = pos_find(1,last,alice[i]);
        if (!pos) cout<<rank_min+1<<"\n";
        else {
            cout<<ranking[pos]<<"\n";
            last = pos;
        }
    }
    //for (int i=1;i<=n;i++) cout<<ranking[i]<<" ";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
