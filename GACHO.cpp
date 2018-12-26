#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int m,n;
    cin>>n>>m;
    int x = m - 2 * n;
    if (x < 0 || x % 2 != 0){
        cout<<"-1";
        return 0;
    }
    x /= 2;
    if (x > n){
        cout<<"-1";
        return 0;
    }
    int y = n - x;
    if (x * 4 + y * 2 != m){
        cout<<"-1";
        return 0;
    }
    cout<<y<<" "<<x;
    return 0;
}
