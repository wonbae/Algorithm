#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    freopen("input.txt", "rt", stdin);
    int n,m,d;
    cin>>n;
    vector<pair<int, int> > v;
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++){
        cin>>m>>d;
        v.push_back(make_pair(d,m));
    }

    sort(v.begin(), v.end(), desc);

    int max_day = v.front().first;

    while(max_day > 0){
        for(int i = 0; i < n; i++){
            if(max_day == v[i].first){
                pq.push(v[i].second);
            }
        }
        max_day--;
    }

    int total = 0;

    for(int i = 0; i < v.front().first; i++){
        total += pq.top();
        pq.pop();
    }

    cout<<total<<"\n";

    return 0;
}