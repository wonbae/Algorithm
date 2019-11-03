#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool compare(pair<double, int> a, pair<double, int> b)
{
    // 실패율이 같다면 스테이지 번호가 작은것!
    if(a.first == b.first)
        return a.second < b.second;
    
    // 실패율이 큰것이 앞!
    return a.first > b.first;
}
 
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int users[501]={0};
    int userSize = stages.size();
    vector<pair<double, int>> failure;
    
    // 각각의 스테이지에 도달한 유저수
    for(vector<int>::iterator it = stages.begin(); it!=stages.end(); it++)
        users[*it-1]++;
    
    for(int i=0; i<N; i++)
    {
        if(users[i] == 0)
            failure.push_back(make_pair(0, i+1));
        else
        {
            failure.push_back(make_pair((double)users[i]/userSize, i+1));
            userSize -= users[i];
        }
    }
    
    sort(failure.begin(), failure.end(), compare);
    
    for(vector<pair<double, int>>::iterator it = failure.begin(); it!=failure.end(); it++)
        answer.push_back(it->second);
 
    return answer;
}
