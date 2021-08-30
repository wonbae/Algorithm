#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }else{
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m, weight, cost, ans = 2147483647;
    cin>>n>>m;
    vector<pair<int, int> > v;

    for(int i = 0; i < n; i++){
        cin>>weight>>cost;
        v.push_back(make_pair(weight, cost));
    }

    sort(v.begin(), v.end(), cmp);
    
    int amount = 0;
    int plus = 0;
    bool flag = true;

    for(int i = 0; i < n; i++){
        amount += v[i].first;

        if(i != 0 && v[i-1].second == v[i].second)    {
            plus += v[i].second;
        }else{
            plus = 0;
        }

        if(amount >= m){
            flag = false;
            ans = min(ans, plus + v[i].second);
        }
    }

    if(flag){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
