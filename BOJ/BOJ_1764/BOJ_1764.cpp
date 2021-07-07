#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// string a[500001], b[500001], c[500001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    // int N, M, idx = 0, aidx = 0, bidx = 0;
    // cin>>N>>M;
    
    // for(int i = 0; i < N; i++){
    //     cin>>a[i];
    // }
    // for(int i = 0; i < M; i++){
    //     cin>>b[i];
    // }

    // sort(a, a + N);
    // sort(b, b + M);

    // while(aidx < N && bidx < M){
    //     if(a[aidx] == b[bidx]){
    //         c[idx++] = a[aidx++];
    //         bidx++;
    //     }else if(a[aidx] > b[bidx]){
    //         bidx++;
    //     }else{
    //         aidx++;
    //     }
    // }

    // cout<<idx<<"\n";
    // for(int i = 0; i < idx; i++){
    //     cout<<c[i]<<"\n";
    // }

    int n, m;
    cin>>n>>m;

    map<string, bool> map;
    vector<string> v;

    for(int i = 0; i < n; i++){
        string input;
        cin>>input;
        map.insert(pair<string, bool> (input, false));
    }

    for(int i = 0; i < m; i++){
        string input;
        cin>>input;
        if(map.end() != map.find(input)){
            v.push_back(input);
        }
    }

    sort(v.begin(), v.end());
    
    cout<<v.size()<<"\n";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<"\n";
    }

    return 0;
}