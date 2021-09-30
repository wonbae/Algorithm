#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    priority_queue<int> minus;
    priority_queue<int> plus;

    int maxlen=0, ans = 0;
    
    for(int i = 0; i < n; i++){
        int num;
        cin>>num;
        if(num < 0){
            minus.push(-num);
        }else{
            plus.push(num);
        }
        maxlen = max(abs(num), maxlen);
    }

    
    while(!minus.empty()){
        for(int i = 1; i <= m; i++){
            if(i == 1){
                ans += abs(minus.top());
                minus.pop();
            }else{
                if(minus.empty())
                    break;
                else
                    minus.pop();
            }
        }
    }

    while(!plus.empty()){
        for(int i = 1; i <= m; i++){
            if(i == 1){
                ans += plus.top();
                plus.pop();
            }else{
                if(plus.empty())
                    break;
                else
                    plus.pop();
            }
        }
    }

    cout<<(ans*2)-maxlen<<"\n";
    return 0;
}