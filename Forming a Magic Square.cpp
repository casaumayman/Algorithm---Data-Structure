#include<bits/stdc++.h>
using namespace std;
typedef vector<int> board;
board a,b;
int cost(board x, board y){
    int tmp = 0;
    for (int i=0;i<9;i++) tmp += abs(x[i]-y[i]);
    return tmp;
}
bool row(int x){
    int d = x*3, t = 0;
    for (int i=d;i<=d+2;i++) t += b[i];
    return (t==15);
}
bool col(int x){
    int d = x%3, t = 0;
    for (int i=d;i<=8;i+=3) t += b[i];
    return (t==15);
}
bool isMagic(){
    for (int i=0;i<3;i++)
        if (!row(i) || !col(i)) return false;
    int c1 = b[0] + b[4] + b[8];
    int c2 = b[2] + b[4] + b[6];
    return (c1 == c2);
}
void Process(){
    int x,mins = INT_MAX,tc;
    for (int i=0;i<9;i++){
        cin>>x;
        a.push_back(x);
    }
    board temp;
    for (int i=0;i<9;i++) b.push_back(i+1);
    do{
        if (isMagic()) {
            tc = cost(a,b);
            if (tc<mins){
                mins = tc;
                //temp = b;
            }
        }
    } while (next_permutation(b.begin(),b.end()));
    //cout<<"\n";
    cout<<mins;
//    for (int i=0;i<9;i++){
//        cout<<temp[i]<<" ";
//        if (i%3 == 2) cout<<"\n";
//    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
