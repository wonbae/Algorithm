#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int s, n, task, cnt = 0;
    bool flag = true;
    cin>>s>>n;
    vector<int> cache(s);

    for(int i = 0; i < n; i++){
        cin>>task;
        
        for(int j = 0; j < cache.size(); j++){
            if(cache[j] == task){
                //cache hit
                int tmp = cache[j];
                cache[j] = cache[0];
                cache[0] = tmp;
                flag = true;
            }else{
                flag = false;
            }
        }

        if(!flag){
            cnt = 0;
            for(int j = 0; j < s; j++){
                if(cache[j] != 0){
                    cnt++;
                }else break;
            }
            for(int j = cnt; j > 0; j--){
                cache[j] = cache[j - 1];
            }
            cache[0] = task;
        }
    }

    for(int i = 0; i < cache.size(); i++){
            cout<<cache[i]<<" ";
    }

    return 0;
}