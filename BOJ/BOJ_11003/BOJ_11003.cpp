#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;

int main(){
    fastio;

    int n, l;
    cin>>n>>l;
    vector<ll> v(n+1);
    vector<ll> d(n+1);
    priority_queue<pair<ll, int> , vector<pair<ll,int> >, greater<pair<ll,int> > > pq;

    for(int i = 1; i <= n; i++){
        cin>>v[i];
    }

    for(int i = 1; i <= n; i++){
        int start = (i - l + 1);
        
        pq.push({v[i], i});

        int index = pq.top().second;

        while(index < start){
            pq.pop();
            index = pq.top().second;
        }

        if(start <= index){
            d[i] = pq.top().first;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<d[i]<<" ";
    }cout<<"\n";

    return 0;
}