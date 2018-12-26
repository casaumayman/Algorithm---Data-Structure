#include<bits/stdc++.h>
using namespace std;
bool notPrime[100001];
int numberPrime[100001],T;
void san(){
    notPrime[0] = true;
    notPrime[1] = true;
    for (int i=2;i<=316;i++)
        if (!notPrime[i])
            for (int j=i*i;j<=100000;j+=i) notPrime[j] = true;
    for (int i=1;i<=100000;i++)
        if (notPrime[i]) numberPrime[i] = numberPrime[i-1];
        else numberPrime[i] = numberPrime[i-1] + 1;
}
void Process(){
    int n;
    cin>>n;
    cout<<((numberPrime[n]&1)?"Alice\n":"Bob\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	//Process();
	san();
	cin>>T;
	while (T--) Process();
	return 0;
}
