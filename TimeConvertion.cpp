#include <bits/stdc++.h>
using namespace std;
string timeConversion(string s) {
    int hh,mm,ss;
    bool typeAM;
    string res="";
    hh=(s[0]-'0')*10+(s[1]-'0');
    mm=(s[3]-'0')*10+(s[4]-'0');
    ss=(s[6]-'0')*10+(s[7]-'0');
    if (s[8]=='A')
    {
        if (hh==12) hh=0;
    }
    else
    {
        if (hh!=12) hh+=12;
    }
    res+=hh/10+'0';
    res+=hh%10+'0';
    res+=':';
    res+=mm/10+'0';
    res+=mm%10+'0';
    res+=':';
    res+=ss/10+'0';
    res+=ss%10+'0';
    return res;
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
