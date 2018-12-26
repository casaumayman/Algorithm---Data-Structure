#include<bits/stdc++.h>
using namespace std;
int n,a[101];
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Process(){
    Input();
    vector <int> indx;
    indx.push_back(1);
    for (int i=1;i<n;i++)
        if (a[i] != a[i+1]) indx.push_back(i+1);
    indx.push_back(n+1);
    int maxs = INT_MIN;
    for (int i=0;i<indx.size();i++){
        if (i==indx.size()-1) maxs = max(maxs,(n-indx[i]+1));
        else{
            maxs = max(maxs,indx[i+1]-indx[i]);
            if (a[indx[i+1]] - a[indx[i]] == 1) maxs = max(maxs, indx[i+2]-indx[i]);
        }
    }
    cout<<maxs;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
