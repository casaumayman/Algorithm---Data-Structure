#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
string S,T;
int n,m;
void Input(){
    srand(time(NULL));
    n = rand()%10 + 1;
    m = rand()%n + 1;
    for (int i=1;i<=n;i++) S += char(rand()%26 + 'a');
    for (int i=1;i<=m;i++) T += char(rand()%26 + 'a');
}
void Process(){
    Input();
    cout<<S<<"\n"<<T;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
