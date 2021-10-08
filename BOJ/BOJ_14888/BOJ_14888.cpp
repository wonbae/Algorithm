#include<iostream>
#include<vector>
using namespace std;

int min_ans = 2147000000, max_ans = -2147000000;
int n;
vector<int> oper;
vector<int> a;

void dfs(int res, int idx){
    if(idx == n){
        min_ans = min_ans > res ? res : min_ans;
        max_ans = max_ans < res ? res : max_ans;
        return ;
    }

    for(int i = 0; i < 4; i++){
        if(oper[i] > 0){
            oper[i]--;
            if(i == 0){
                dfs(res+a[idx], idx+1);
            }else if(i == 1){
                dfs(res-a[idx], idx+1);
            }else if(i == 2){
                dfs(res*a[idx], idx+1);
            }else if(i == 3){
                dfs(res/a[idx], idx+1);
            }
            oper[i]++;
        }
    }
    return ;
}


int main(){    
    cin>>n;
    a.resize(n);
    oper.resize(4);

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < 4; i++){
        cin>>oper[i];
    }
    dfs(a[0], 1);
    cout<<max_ans<<"\n"<<min_ans;
    return 0;
}