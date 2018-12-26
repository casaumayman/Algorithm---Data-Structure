#include<bits/stdc++.h>
using namespace std;
string s = "-";
char *n;
void Input(){
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI4\\TEST10\\BAI4.INP","w");
    srand(time(NULL));
    for (int i = 0; i < 200; i++){
        s += char((rand() % 10) + '0');
    }
    n = new char[s.size() + 1];
    strcpy(n, s.c_str());
    cout<<s<<"\n";
    fprintf(f,"%s\n",n);
    fclose(f);
}
void Process() {
    FILE *f = fopen("C:\\Users\\casau\\Desktop\\contest\\Tasks\\BAI4\\TEST10\\BAI4.OUT","w");
    int t = 0;
    for (int i=1; i < s.size(); i++) t += s[i]-'0';
    if (s[0] != '-') t += s[0] - '0';
    fprintf(f,"%d",t);
    cout<<t;
    fclose(f);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	Process();
	return 0;
}
