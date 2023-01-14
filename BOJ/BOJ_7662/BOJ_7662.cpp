#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef std::pair<int, int> pii;
using namespace std;

int visited[1000004];

int main(){
    fastio;
    int t, k;
    
    cin>>t;

    while(t--){
        priority_queue<pii> maxpq;
        priority_queue<pii, vector<pii>, greater<pii> > minpq;

        cin>>k;

        char oper;
        int num;
        for(int i = 0; i < k; i++){
            cin>>oper>>num;

            if(oper=='I'){
                maxpq.push({num, i});
                minpq.push({num, i});
                visited[i] = true;
            }else{
                if(num < 0){
                    while(!minpq.empty() && !visited[minpq.top().second]){
                        minpq.pop();
                    }
                    if(!minpq.empty()){ 
                        visited[minpq.top().second] = false;
                        minpq.pop();
                    }
                }else{
                    while(!maxpq.empty() && !visited[maxpq.top().second]){
                        maxpq.pop();
                    }
                    if(!maxpq.empty()){ 
                        visited[maxpq.top().second] = false;
                        maxpq.pop();
                    }
                }
            }
        }
        while(!minpq.empty() && !visited[minpq.top().second]){
            minpq.pop();
        }

        while(!maxpq.empty() && !visited[maxpq.top().second]){
            maxpq.pop();
        }

        if(maxpq.empty() && minpq.empty()){
            cout<<"EMPTY\n";
        }else{
            cout<<maxpq.top().first<<" "<<minpq.top().first<<"\n";
        }
    }
    return 0;
}