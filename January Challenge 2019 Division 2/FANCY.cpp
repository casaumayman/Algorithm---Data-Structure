#include<bits/stdc++.h>
using namespace std;
int T;
string S;
bool check(string s){
    if (s=="not") return true;
    if (s.size()<5) return false;
    if (s.substr(0,4) == "not ") return true;
    if (s.substr(s.size()-4) == " not") return true;
    if (s.find(" not ") != string::npos) return true;
    return false;
}
void Process(){
    cin>>T;
    T++;
    while (T--){
        getline(cin,S);
        if (S=="") continue;
        if (check(S)) cout<<"Real Fancy\n";
        else cout<<"regularly fancy\n";
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
