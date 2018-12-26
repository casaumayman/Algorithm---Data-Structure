#include<bits/stdc++.h>
using namespace std;
string a[10];
int n;
string s;
void init(){
    a[0] = "_0";
    a[2] = "abc2";
    a[3] = "def3";
    a[4] = "ghi4";
    a[5] = "jkl5";
    a[6] = "mno6";
    a[7] = "pqrs7";
    a[8] = "tuv8";
    a[9] = "wxyz9";
    a[1] = ".,?!1";
}
int findc(char c,int k){
    for (int i=0;i<a[k].length();i++)
        if (a[k][i] == c) return (i+1);
    return 0;
}
void searching(char c,int &num,int &pos){
    int t;
    for (int i=0;i<=9;i++){
        t = findc(c,i);
        if (t != 0){
            num = i;
            pos = t;
            return;
        }
    }
}
void Process(){
    cin>>s;
    int res = 0,num,pos,prev_num;
    prev_num = 1;
    for (int i=0;i<s.length();i++){
        searching(s[i],num,pos);
        if (num == prev_num) res += pos;
        else {
            res += pos + 1;
            prev_num = num;
        }
    }
    cout<<res<<"\n";
}
int main()
{
 	#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	init();
	cin>>n;
	while (n--){
        Process();
	}
	return 0;
}

