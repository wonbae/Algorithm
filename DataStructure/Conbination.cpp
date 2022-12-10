#include<bits/stdc++.h>
using namespace std;

bool desc(char c, char d){
    return c > d;
}

bool desc2(bool a, bool b){
    return a < b;
}

int main(){
    
    const int r = 3;

    vector<char> arr{'a','b','c','d','e'};
    
    vector<bool> tmp(arr.size(), false);

    for(int i = 0; i < r; i++){
        tmp[i] = true;
    }

    // sort(arr.begin(), arr.end(), desc);
    sort(tmp.begin(), tmp.end(), desc2);

    do{
        for(int i = 0; i < tmp.size(); i++){
            cout<<tmp[i]<<" ";
        }cout<<"\n";

        for(int i = 0; i < arr.size(); i++){
            if(tmp[i]){
                cout<<arr[i]<<" ";
            }
        }cout<<"\n";
    }while(next_permutation(tmp.begin(), tmp.end()));

    return 0;
}