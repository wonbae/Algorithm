//Anagram
#include<iostream>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);

    int a[26] = {0,};
    string st, st2;
    cin>>st>>st2;

    for(int i = 0; i < st.length(); i++){
        if(st[i] >= 65 && st[i] <= 90){
            // st[i] = st[i] + 32;
            // a[st[i] - 97]++;
            a[st[i] - 65]++;
        }else{
            a[st[i] - 97]++;
        }
    }

    for(int i = 0; i < st2.length(); i++){
        if(st2[i] >= 65 && st2[i] <= 90){
            st2[i] = st2[i] + 32;
            a[st2[i] - 97]--;
        }else{
            a[st2[i] - 97]--;
        }
    }

    for(int i = 0; i < 26; i++){
        if(a[i] == 0) continue;
        else{
            cout<<"NO";
            return 0;
        } 
    }

    cout<<"YES";

    return 0;
}