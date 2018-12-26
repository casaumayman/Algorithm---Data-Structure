#include<bits/stdc++.h>
using namespace std;
int a,b;
vector <pair<int,int> > kq;
void Process(){
    cin>>a>>b;
    while (a>0 && b>0 && (a+b)>=3){
        if (a>b){
            a -= 2;
            b -= 1;
            kq.push_back(make_pair(2,1));
        }
        else{
            b -= 2;
            a -= 1;
            kq.push_back(make_pair(1,2));
        }
    }
    cout<<kq.size()<<"\n";
    for (int i=0;i<kq.size();i++)
        cout<<kq[i].first<<" "<<kq[i].second<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
