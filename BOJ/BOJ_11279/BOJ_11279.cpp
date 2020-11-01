#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;
    cin>>n;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        cin>>a;
        if(a == 0){
            if(pq.empty()){
                cout<<a<<"\n";
            }else{
                int res = pq.top();
                cout<<res<<"\n";
                pq.pop();
            }
        }else{
            pq.push(a);
        }
    }
    return 0;
}