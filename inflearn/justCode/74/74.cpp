#include<iostream>
#include<queue>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    priority_queue<int, vector<int>, greater<int> > pq;
    //greater 안쓸꺼면 입력값과 출력값에 -1을 곱해주자
    int num;

    while(1){
        cin>>num;
        if(num<0) return 0;

        if(num > 0){
            pq.push(num);
            // pq.push(-num);
        }else{
            if(pq.empty()){
                cout<<-1<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                // cout<<-pq.top()<<"\n";
                pq.pop();
            }
        }
    }
    return 0;
}