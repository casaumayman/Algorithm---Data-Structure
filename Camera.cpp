#include<bits/stdc++.h>
using namespace std;
int n,a[100001],l[100001],r[100001];
char h[100001];
void Input(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>h[i];
    }
}
void Process(){
    Input();
    int left=1,right=1;
    while (left <= n && right <= n){
        while (right<n && a[right]<=a[right+1]) right++;
        while (left < right) r[left++] = right;
        right++;
    }
    r[n] = n;
    left = n; right = n;
    while (left >= 1 && right >= 1) {
        while (left>1 && a[left]<=a[left-1]) left--;
        while (right > left) l[right--] = left;
        left--;
    }
    l[1]=1;
//    cout<<l<<" "<<r<<"\n";
//    for (int i=1;i<=n;i++) cout<<l[i]<<" ";
    for (int i=1;i<=n;i++)
        if (h[i]=='E') cout<<r[i]-i<<" ";
        else cout<<i-l[i]<<" ";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
