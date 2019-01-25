#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001],coun[100001],m,n;
void Input(){
    cin>>s;
    n = s.size();
    s = " "+s;
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>a[i];
        coun[a[i]]++;
    }
    sort(a+1,a+m+1);
}
void Process(){
    Input();
    int i = 1;
    int next;
    while (i<=m){
        int dem = coun[a[i]];
        next = a[i+dem];
        if (!next) next = a[n/2];
        if (dem%2==1) {
            for (int x = i; x<next;x++){
                int y = n - x + 1;
                swap(s[x],s[y]);
            }
        }
        i += dem;
    }
    for (int i=1;i<=n;i++) cout<<s[i];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
