#include<bits/stdc++.h>
using namespace std;
long long N,A,B;
void Process(){
    cin>>N>>A>>B;
    if (A>B) swap(A,B);
    if (N==1 && A!=B) cout<<0;
    else {
        long long maxs = B*(N-1)+A;
        long long mins = A*(N-1)+B;
        cout<<maxs-mins+1;
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
