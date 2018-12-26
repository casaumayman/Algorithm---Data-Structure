#include<bits/stdc++.h>
using namespace std;
const int PRIME[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
map <int,bool> semiPrime;
int T,N;
void create(){
    for (int i=0;i<24;i++)
        for (int j=i+1;j<25;j++)
            if (PRIME[i]*PRIME[j]<=200) semiPrime[PRIME[i]*PRIME[j]]=true;
}
bool check(int value){
    map <int,bool> :: iterator it;
    for (it = semiPrime.begin(); it != semiPrime.end(); it++)
        if (semiPrime[value - (*it).first] && semiPrime[(*it).first]){
//            cout<<(*it).first<<" "<<value - (*it).first<<"\n";
            return true;
        }
    return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	create();
	cin>>T;
	while (T--) {
        cin>>N;
        if (check(N)) cout<<"YES\n";
        else cout<<"NO\n";
	}
	return 0;
}
