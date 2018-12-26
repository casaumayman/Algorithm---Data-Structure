#include<bits/stdc++.h>
using namespace std;
string s;
void Process(){
    cin>>s;
    int i=0;
    int start = 0;
    char t = s[0];
    bool change = false;
    bool lui = false;
    if (s.size()==2 && s[0]=='1' && s[1]<'6')
    while (i<s.size() && start<s.size()){
        if (change){
            s[i] = '8';
            i++;
            continue;
        }
        t = s[i];
        if (lui) s[i]--;
        lui = false;
        if (s[i]<'6') {
            s[i] = '8';
            lui = true;
            i--;
            continue;
        }


        if (i<start) break;
        while (s[i]>'0' && s[i]!='6' && s[i]!='8') s[i]--;
        if (t != s[i]) change = true;

        if (s[i] == '0' && start == i) start++;
        i++;
    }
    for (int i=start;i<s.size();i++) cout<<s[i];
    //cout<<start;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
