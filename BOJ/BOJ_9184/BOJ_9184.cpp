#include<bits/stdc++.h>
using namespace std;

int dp[51][51][51];

int recur(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if(a > 20 || b > 20 || c > 20) return recur(20, 20, 20);

    else if(dp[a][b][c] != 0) return dp[a][b][c];

    else if(a < b && b < c){
        dp[a][b][c] = recur(a, b, c-1) + recur(a, b-1, c-1) - recur(a, b-1, c);
    }else{
        dp[a][b][c] = recur(a-1, b, c) + recur(a-1, b-1, c) + recur(a-1, b, c-1) - recur(a-1, b-1, c-1);
    }
    return dp[a][b][c];
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int a, b, c;
    while(true){
        cin>>a>>b>>c;
     
        if(a == -1 && b == -1 && c == -1) break;

        int result = recur(a, b, c);
        
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<result<<"\n";
    }

    return 0;
}