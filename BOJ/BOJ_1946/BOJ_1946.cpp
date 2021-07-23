#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n, cnt = 1;
        vector<pair<int, int> > v;
        cin>>n;
        for(int j = 0; j < n; j++){
            int paper, interview;
            cin>>paper>>interview;
            v.push_back({paper, interview});
        }

        sort(v.begin(), v.end());

        int tmp = v[0].second;

        for(int k = 0; k < n; k++){
            if(v[k].second < tmp){
                tmp = v[k].second;
                cnt++;
            }
        }

        cout<<cnt<<"\n";

    }

    return 0;
}