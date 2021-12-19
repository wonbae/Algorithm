#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[1001][1001]={0,};
string str,str2;

void printLCS(int r, int c){
    if(dp[r][c] == 0) return ;
    if(str[r-1] == str2[c-1]){
        printLCS(r-1, c-1);
        cout<<str[r-1];
    }else{
        dp[r-1][c] > dp[r][c-1] ? printLCS(r-1, c) : printLCS(r, c-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>str>>str2;
    int len = str.length(), len2 = str2.length();

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len2; j++){
            if(str[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout<<dp[len][len2]<<"\n";
    printLCS(len, len2);
    return 0;
}