#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int unf[1001];

int Find(int v){
    if(v == unf[v]) return v;
    return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, cost;
    long long mini_cost = 0;
    vector<pair<int, pair<int, int> > > v;

    cin>>n;

    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>cost;
            if(i >= j) continue;
            else if(i < j){
                v.push_back(make_pair(cost, make_pair(i+1, j+1)));
            }
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(Find(v[i].second.first) != Find(v[i].second.second)){
            mini_cost += v[i].first;
            Union(v[i].second.first, v[i].second.second);
        }
    }

    cout<<mini_cost<<"\n";

    return 0;
}