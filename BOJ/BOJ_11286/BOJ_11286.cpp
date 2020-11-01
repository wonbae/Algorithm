#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;
    cin>>n;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < n; i++){
        cin>>a;
        if(a == 0){
            if(pq.empty()){
                cout<<a<<"\n";
            }else{
                int res = pq.top().second;
                cout<<res<<"\n";
                pq.pop();
            }
        }else{
            pq.push(make_pair(abs(a), a));
        }
    }
    return 0;
}