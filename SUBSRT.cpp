#include<bits/stdc++.h>
using namespace std;
const int BASE=1000000007;
string a,b;
int hashB,hashA[1000001],pow[1000001];
void Input()
{
	cin>>a>>b;
	for (int i=0;i<b.length();i++) hashB=(hashB*26+(b[i]-'a'))%BASE;
	hashA[0]=a[0]-'a';
	for (int i=1;i<a.length();i++) hashA[i]=(hashA[i-1]*26+(a[i]-'a'))%BASE;
	
}
int main()
{
	return 0;
}
