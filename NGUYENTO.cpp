#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>n;
	if (n < 2){
        cout<<"NO";
	}
	else if (n == 2){
        cout<<"YES";
	}
	else{
        for (int i=2;i<=sqrt(n);i++)
        if (n % i == 0){
            cout<<"NO";
            return 0;
        }
        cout<<"YES";
	}
	return 0;
}
