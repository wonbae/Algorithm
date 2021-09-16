#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;

    unordered_map<string, int> name;
    unordered_map<int, string> number;

    string str;
    for(int i = 1; i <= n; i++){
        cin>>str;
        name[str] = i;
        number[i] = str;
    }

    string query;
    for(int i = 0; i < m; i++){
        cin>>query;
        if(query[0] - '0' >= 0 && query[0] - '0' <= 9){
            int tmp = stoi(query);
            cout<<number[tmp]<<"\n";
        }else{
            cout<<name[query]<<"\n";
        }
    }
    return 0;
}