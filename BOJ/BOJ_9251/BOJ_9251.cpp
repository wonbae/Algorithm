// // LCS(Longest Common Subsequence, 최장 공통 부분 수열)미완성

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str[1000];
    cin >> str[0];
    int len = str[0].size();
    
    for(int i=1; i<len; i++){
        str[i] = str[0].substr(i);
        cout<< str[i] <<endl;
    }
    sort(str, str+len);
    for(int i=0; i<len; i++)
        cout << str[i] << endl;
}