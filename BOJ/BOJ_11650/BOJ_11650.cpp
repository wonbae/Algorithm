#include<bits/stdc++.h>
using namespace std;

// bool comp(const pair<int, int> &a, const pair<int, int> &b){
//     return a.first == b.first ? a.second < b.second : a.first < b.first;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin>>N;

    vector<pair<int, int> > v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i].first>>v[i].second;
        // v.push_back(make_pair(a, b));
    }

    // sort(v.begin(), v.end(), comp);
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }

    return 0;
}