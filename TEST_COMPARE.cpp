#include<bits/stdc++.h>
using namespace std;
int cA,cB,cAB;
void Input(){
    srand(time(NULL));
    cA = 0;
    cB = 0;
    cAB = rand()%5;
}
string code_chuan(){
    if(cAB == cA && cB == cA && cB == 0 || (cA == cB && cAB == 0)){
        return "ALICE";
        exit(0);
    }
    if(cA >= (cB + cAB % 2) || (cAB % 2 == 1 && cB == cA))
        return "BOB";
    else
        return "ALICE";
}
string my_code(){
    if (cA > cB) return "BOB";
    else if (cA < cB) return "ALICE";
    else {
        if (cAB % 2 == 0) return "ALICE";
        else return "BOB";
    }
}
void Output(){
    cout<<cA<<" "<<cAB<<" "<<cB<<"\n";
    cout<<"code chuan: "<<code_chuan()<<"\n";
    cout<<"my code: "<<my_code();
}
void Process(){
    Input();
    while (my_code()==code_chuan()){
        Input();
    }
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
