#include<bits/stdc++.h>
using namespace std;
int n;
int UCNN(int a,int b){
    int r;
    while (b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void Process(){
    cin>>n;
    int x,res;
    for (int i=1;i<=n;i++){
        cin>>x;
        if (i==1) res = x;
        else res = UCNN(res,x);
    }
    cout<<(long long)res*(long long)n;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
