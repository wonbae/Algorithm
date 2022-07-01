#include<bits/stdc++.h>
using namespace std;

string vowels = "aeiou";

bool check_vow(string s){
    for(int i = 0; i < vowels.size(); i++){
        if(s.find(vowels[i]) != -1){
            return true;
        }
    }
    return false;
}

bool check_seq(string s){
    int v=0, c=0;
    // cout<<"str : "<<s<<"\n";
    for(int i = 0; i < s.size(); i++){
        
        if(vowels.find(s[i]) != -1){
            // cout<<"vow : "<<s[i]<<"\n";
            ++v;
            c=0;
        }else{
            // cout<<"cons : "<<s[i]<<"\n";
            ++c;
            v=0;
        }
        // cout<<v<<"\n";
        if(v >= 3 || c >= 3) return false;
        if(s[i] == s[i+1]){
            if(s[i] == 'o' || s[i] == 'e') continue;
            else return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    string str;
    
    while(true){
        cin>>str;
        if(str == "end") break;
        bool one=false, two=false;

        if(check_vow(str)){
            one=true;
        }
        if(check_seq(str)){
            two=true;
        }

        if(one && two){
            cout<<"<"<<str<<"> "<<"is acceptable.\n";
        }else{
            cout<<"<"<<str<<"> "<<"is not acceptable.\n";
        }
    }


    return 0;
}