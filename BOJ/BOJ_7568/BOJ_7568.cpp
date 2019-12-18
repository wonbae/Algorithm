#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    vector<pair<int, int> > v;
    int x,y;

    cin>>T;
    
    for(int i = 0; i < T; i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    for(int i = 0; i < T; i++){
        int count = 1;
        for(int j = 0; j < T; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                count++;
            }
        }
        cout<<count<<" ";
    }


    return 0;
}