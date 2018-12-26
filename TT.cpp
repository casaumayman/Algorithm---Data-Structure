#include<bits/stdc++.h>
using namespace std;
int n,a[20],tong_A,tong_B,dem;
vector <vector<char> > kq;
vector <char> temp;
void Input(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
}
void submit(int i){
    if (i == n){
        if (tong_A != tong_B) return;
        kq.push_back(temp);
        return;
    }
    for (int j=0;j<=1;j++){
        if (j){
            tong_B += a[i];
            temp.push_back('B');
            submit(i+1);
            tong_B -= a[i];
        }
        else{
            tong_A += a[i];
            temp.push_back('A');
            submit(i+1);
            tong_A -= a[i];
        }
        temp.pop_back();
    }
}
void Output(){
    if (kq.empty()){
        cout<<"khong chia duoc";
        return;
    }
    cout<<kq.size()<<"\n";
    for (int i=0;i<kq.size();i++){
        for (int j=0;j<n;j++) cout<<kq[i][j]<<" ";
        cout<<"\n";
    }
}
void Process(){
    Input();
    submit(0);
    Output();
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
