#include<bits/stdc++.h>
using namespace std;
int n,a[21];
list <int> mylist;
void Input(){
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    mylist.push_back(a[0]);
}
void Process(){
    Input();
    for (int i=1;i<n;i++){
        auto it = mylist.end();
        it--;
        int pos = mylist.size() - 1;
        while (it != mylist.begin() && (*it)>a[i]){
            it--;
            pos--;
        }
        if (it == mylist.begin() && *it>a[i]){
            cout<<a[i]<<" 0\n";
            mylist.push_front(a[i]);
        }
        else{
            it++;
            pos++;
            cout<<a[i]<<" "<<pos<<"\n";
            mylist.insert(it,a[i]);
        }
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
