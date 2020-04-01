#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int E, S, M, year = 1;
    int e = 1, s = 1, m = 1;

    cin>>E>>S>>M;

    while(1){
        if(e == E && s == S && m == M) break;
        e++, s++, m++;
        year++;  
        if((e %= 16) == 0)  e = 1;
        if((s %= 29) == 0)  s = 1;
        if((m %= 20) == 0)  m = 1;
    }
    
    cout<<year<<"\n";

    return 0;
}