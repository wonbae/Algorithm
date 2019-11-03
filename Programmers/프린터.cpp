#include <string>
// #include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> que;
    priority_queue<int> pq;
    
    for(int i = 0 ; i < priorities.size(); i++){
        que.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!que.empty()){
        if(pq.top() == que.front().second){
            if(location == que.front().first){
                return answer + 1;
            }else{
                answer++;
                que.pop();
                pq.pop();
            }
        }
        else{
            que.push(que.front());
            que.pop();
        }
    }
    
    
    return answer;
}
