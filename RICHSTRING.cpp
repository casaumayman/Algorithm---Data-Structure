#include<bits/stdc++.h>
using namespace std;
string s;
bool m[26];
int n;
bool valid[2501];
int toint(char c){
    return (c-'A');
}
void process(){
    cin>>s;
    int i=0;
    string smax = "",stemp;
    char c;
    for (i=0;i<s.size();i++) valid[i]=true;
    i=0;
    while (i<s.size())
    {
        while (s[i]!=s[i+1]) i++;
        c = s[i];
        while (i<s.size() && s[i]==c){
            valid[i]=false;
            i++;
        }
    }
    int j,n = s.length();
    for (int i=0;i<n;i++) {
        if (!valid[i]) continue;
        for (int k=0;k<26;k++) m[k]=false;
        j = i;
        while (j<n && !m[toint(s[j])]) {
            m[toint(s[j])] = true;
            j++;
            if (!valid[j]) break;
        }
        if (j>=n || m[toint(s[j])] || !valid[j]) j--;
        stemp = s.substr(i,(j-i+1));
        if (stemp.size() > smax.size()) {
            smax = stemp;
        }
        else if ((stemp.size() == smax.size()) && stemp[0]<smax[0]) {
            smax = stemp;
        }
    }
    cout<<smax;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	process();
	return 0;
}
