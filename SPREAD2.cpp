#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010];
void Input(){
    cin>>n;
    int x;
    a[0] = 0;
    for (int i=1;i<=n;i++){
        cin>>x;
        a[i]=a[i-1]+x;
    }
}
void Process(){
    Input();
    int kq = 1,i = a[1]+1,t,j = 1;
    t = a[i] - a[j-1];
    while (i<n){
        kq++;
        j = i;
        i += t;
        if (i<=n) t += a[i] - a[j];
    }
    cout<<kq<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) {
        Process();
	}
	return 0;
}
