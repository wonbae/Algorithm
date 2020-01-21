#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str = "";
    string result = "";
    vector<int> v;
    bool flag = true;
    

    cin>>str;

    int len = str.length();

    for(int i = 0; i < len; i++){
        v.push_back(i);
    }

    do{
        for(int i = 0; i < v.size() / 2; i++){
            if(str[v[i]] == str[v[len - 1 - i]]){
                flag = true;
                continue;
            }else{
                flag = false;
                break;
            }
        }

        if(flag){
            for(int i = 0; i < v.size(); i++){
                result += str[v[i]];
            }
            break;
        }
        

    }while(next_permutation(v.begin(), v.end()));

    if(!flag){
        cout<<"I'm Sorry Hansoo"<<"\n";
    }

    cout<<result<<"\n";

    return 0;
}