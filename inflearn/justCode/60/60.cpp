#include<iostream>
using namespace std;

int nums[10] = {0,};
bool ch[10] = {false,};
int n, a = 0, b = 0, total = 0;
bool flag = false;

void DFS(int depth){
    if(flag) return ;
    if(depth > n){
        for(int i = 0; i < n; i++){
            if(ch[i]){
                a+=nums[i];
            }else{
                b+=nums[i];
            }
        }
        if(a == b){
            cout<<"YES"<<"\n";
            flag = true;
            return ;
        }else flag = false;
        
    }else{
        ch[depth] = true;
        DFS(depth + 1);
        ch[depth] = false;
        DFS(depth + 1);
    }
}

void dfs(int L, int val){
    if(flag) return ;
    if(total/2 < val) return ;
    if(L > n){
        if((total - val) == val){
            flag = true;
        }
    }else{
        dfs(L+1, val+nums[L]);
        dfs(L+1, val);
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
        total += nums[i];
    }

    // DFS(1);
    dfs(1, 0);

    if(!flag) cout<<"NO";
    else cout<<"YES";

    return 0;
}