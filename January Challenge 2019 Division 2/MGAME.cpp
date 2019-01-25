#include<bits/stdc++.h>
using namespace std;
int T,n;
long long p;
void Process(){
    cin>>n>>p;
    if (n<3){
        cout<<p*p*p<<"\n";
    }
    else{
        long long M,res;
        if (n%2==0) M = n/2 - 1;
        else M = n/2;
        long long Nhanh_Be;
        if (n%2==0) Nhanh_Be = p - (n-M) + 2;
        else Nhanh_Be = p - (n-M) + 1;
        Nhanh_Be *= Nhanh_Be;
        if (n==p) {
            cout<<Nhanh_Be<<"\n";
            return;
        }
        int snl = p - n;
        long long Nhanh_Lon = sqrt(Nhanh_Be) + snl;
        Nhanh_Lon *= snl;
        res = Nhanh_Lon + Nhanh_Be;
        cout<<res<<"\n";
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>T;
	while (T--) Process();
	return 0;
}
