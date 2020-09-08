#include<iostream>
#include<queue>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    queue<int> q;
    int n, k, cnt = 1;
    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    // while(!q.empty()){
    //     int x = q.front();
    //     q.pop();
        
    //     if(cnt == k){
    //         cnt = 1;
    //         if(q.size() == 1){
    //             cout<<q.front()<<"\n";
    //             return 0;
    //         }
    //     }else{
    //         cnt++;
    //         q.push(x);
    //     }
    // }

    while(!q.empty()){
        for(int i = 1; i < k; i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        if(q.size() == 1){
            cout<<q.front()<<"\n";
            q.pop();
        }
    }

    return 0;
}