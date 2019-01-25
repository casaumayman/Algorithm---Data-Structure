#include<bits/stdc++.h>
using namespace std;
const int BASE = 40000;
int n,T;
bool isPrime[BASE];
vector <int> Prime;
void init(){
    for (int i=2;i<=BASE;i++) isPrime[i] = true;
    for (int i=2;i<=BASE;i++)
        if (isPrime[i])
        for (int j=i*i;j<=BASE;j+=i) isPrime[j] = false;
    for (int i=2;i<=BASE;i++)
        if (isPrime[i]) Prime.push_back(i);
}
void Process(){
    cin>>n;
    for (int i=1;i<n;i++) cout<<Prime[i]*Prime[i-1]<<" ";
    cout<<Prime[n-1]*2<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	init();
	cin>>T;
	while (T--) Process();
	return 0;
}
