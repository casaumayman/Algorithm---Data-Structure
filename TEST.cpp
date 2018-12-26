#include <bits/stdc++.h>
using namespace std;
int n;
int sum_digit(int x){
    int t=0;
    while (x){
        t += (x%10);
        x /= 10;
    }
    return t;
}
int main(){
    cin>>n;
    cout<<((sum_digit(n)%10 == 8)?"YES":"NO");
    return 0;
}
