#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    deque<int> dq;
    int N, M, idx;

    cin>>N>>M;

    int ans = 0;

    for(int i = 1; i <= N; i++){
        dq.push_back(i);
    }
    for(int j = 0; j < M; j++){
        cin>>idx;
        if(dq.front() == idx){
            dq.pop_front();
        }
        else{
            int pos = 1;
            for(deque<int>::iterator iter = dq.begin(); iter < dq.end(); iter++){
                if(*iter == idx){
                    break;
                }
                pos++;
            }

            int left = pos - 1;
            int right = dq.size() - pos + 1;

            if(left < right){
                for(int i = 0; i < left; i++){
                    int tmp = dq.front();
                    dq.pop_front();
                    dq.push_back(tmp);
                    ans++;
                }
                dq.pop_front();
                
            }else{
                for(int i = 0; i < right; i++){
                    int tmp = dq.back();
                    dq.pop_back();
                    dq.push_front(tmp);
                    ans++;
                }
                dq.pop_front();
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}