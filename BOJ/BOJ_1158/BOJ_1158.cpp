#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;

    int N,K;
    int position;

    cin>>N>>K;

    for(int i = 1; i <= N; i++){
        v.push_back(i);
    }

    cout<<"<";

    while(1){

        position = (position + K - 1) % v.size();

        if(v.size() <= 1){
            cout<<v[position]<<">"<<"\n";
            break;
        }else{
            
            cout<<v[position]<<", ";
            v.erase(v.begin() + position);
        }
        
    }


    return 0;
}