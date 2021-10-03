#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n, ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<pair<int, int> > vec;

    cin>>n;

    for(int i = 0; i < n; i++){
        int d, c;
        cin>>d>>c;
        vec.push_back(make_pair(d,c));
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++){
        pq.push(vec[i].second);
        if(pq.size() > vec[i].first){
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout<<ans<<"\n";
    return 0;
}