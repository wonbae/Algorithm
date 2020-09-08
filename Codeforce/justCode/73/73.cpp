#include<iostream>
#include<queue>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    priority_queue<int> pq;
    int num;

    while(1){
        cin>>num;
        if(num<0) return 0;

        if(num > 0){
            pq.push(num);
        }else{
            if(pq.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
    }
    return 0;
}