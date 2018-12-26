#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\O+UTPUT.txt","w",stdout);
	int n;
	cin>>n;
	if (n < 1 || n > 9){
        cout<<"NONE";
        return 0;
	}
	for (int i = 1;i <= 9;i++){
        cout<<n<<"x"<<i<<"="<<n * i<<"\n";
	}
	return 0;
}
