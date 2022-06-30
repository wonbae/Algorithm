#include<bits/stdc++.h>
using namespace std;

char v[100][100];
int n;

string dfs(int row, int col, int siz){
    if(siz==1) return string(1, v[row][col]); //char to string

    char tmp = v[row][col];
    string ans = "";

    for(int i = row; i < row+siz; i++){
        for(int j = col; j < col+siz; j++){
            if(tmp != v[i][j]){
                ans+='(';
                ans+=dfs(row, col, siz/2);
                ans+=dfs(row, col + siz/2, siz/2);
                ans+=dfs(row + siz/2, col, siz/2);
                ans+=dfs(row + siz/2, col + siz/2, siz/2);
                ans+=')';
                return ans;
            }
        }
    }
    return string(1, v[row][col]);
}

int main(){    
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin>>n;
    string str;
    for(int i = 0; i < n; i++){
        cin>>str;
        for(int j = 0; j < str.size(); j++){
            v[i][j] = str[j];
        }
    }

    cout<<dfs(0, 0, n)<<"\n";


    return 0;
}