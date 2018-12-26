#include<bits/stdc++.h>
using namespace std;
string S,T;
int z[2000001];
int n,m;
void Input(){
    cin>>S>>T;
    S = T + S;
    n = S.length();
    m = T.length();
    int l=0, r=0;
    z[0] = n;
    for (int i=1;i<n;i++){
        if (i>r){
            l = r = i;
            while (r<n && S[r] == S[r-l]) r++;
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else{
                l = i;
                while (r<n && S[r] == S[r-l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}
void Process(){
    Input();
//for (int i=0;i<n;i++) cout<<z[i]<<" ";
    for (int i=m;i<n;i++)
        if (z[i] >= m) cout<<(i - m + 1)<<" ";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\casau\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\casau\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
