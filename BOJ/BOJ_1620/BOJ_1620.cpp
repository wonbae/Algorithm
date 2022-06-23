#include<iostream>
#include<unordered_map>
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
        name[str]=i;
        number[i]=str;
    }

    string query;
    for(int i = 0; i < m; i++){
        cin>>query;
        if(atoi(query.c_str()) == 0){//string -> char -> int, 문자가 맨 처음 있으면 0을 반환, (숫자+문자)면 문자 나오기 전 숫자만 나옴
            cout<<name[query]<<"\n";
        }else{
            cout<<number[atoi(query.c_str())]<<"\n";
        }
    }
    
    return 0;
}