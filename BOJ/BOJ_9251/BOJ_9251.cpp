// // LCS(Longest Common Subsequence, 최장 공통 부분 수열)

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string str1, str2;
    cin>>str1>>str2;

    int len1 = str1.length();
    int len2 = str2.length();

    int dp[1001][1001] = {0,};

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout<<dp[len1][len2];
}