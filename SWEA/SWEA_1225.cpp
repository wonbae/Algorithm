#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue <int> q;
    int inn = 0, tc;
    for (int t = 0; t<10; t++){
        cin>>tc;
        for(int i = 0; i<8; i++){
            cin>>inn;
            q.push(inn);
        }//입력하고 큐에 넣어줌
        int cnt = 0;//cnt초기화
        while(!(q.back()==0)){
            inn = q.front() - (++cnt);
            q.pop();
            if(inn<0)
                inn = 0;
            q.push(inn);
            if(cnt == 5)//n번째 사이클
                cnt = 0;
        }
        
        cout<<" #"<<tc<<" ";
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<"\n";}
    return 0;
}