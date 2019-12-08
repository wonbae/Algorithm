#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<bool> dot(1000 + 1, true);
    vector<int> x;
    vector<int> y;

    int a,b;

    
    for(int i = 0; i <3; i++){
        cin>>a>>b;

        for(int j = 0; j < x.size(); j++){
            if(x[j] == a){
                x.pop_back();
            }else{
                x.push_back(a);
            }
        }
    }

    for(int i = 1000; i > 0; i--){
        if(!dot[i]){
            cout<<i<<" ";
        }
    }cout<<"\n";



    return 0;
}