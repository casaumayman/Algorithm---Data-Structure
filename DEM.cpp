#include<bits/stdc++.h>
using namespace std;
string s;
int n;
struct Node{
    unsigned int res_0,res_1,res_2;
    Node(){}
    Node(int x,int y,int z){
        res_0=x;
        res_1=y;
        res_2=z;
    }
};
Node it[400001];
Node operator + (const Node& left,const Node& right){
    Node res;
    res.res_2=(left.res_0*right.res_2)+(left.res_2*right.res_0)+(left.res_1*right.res_1);
    res.res_1=(left.res_0*right.res_1)+(left.res_1*right.res_0)+(left.res_2*right.res_2);
    res.res_0=(left.res_0*right.res_0)+(left.res_1*right.res_2)+(left.res_2*right.res_1);
    return res;
}
void Input(){
    cin>>s;
    n=s.size();
    s=' '+s;
}
void build(int k,int l,int r){
    if (l==r){
        if ((s[l]-'0')%3==0){
            it[k]=Node(2,0,0);
        }
        else if ((s[l]-'0')%3==1){
            it[k]=Node(1,1,0);
        }
        else{
            it[k]=Node(1,0,1);
        }
        return;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    it[k]=it[k*2]+it[k*2+1];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Input();
	build(1,1,n);
	cout<<it[1].res_0-1;
	return 0;
}
