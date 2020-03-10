#include<bits/stdc++.h>
using namespace std;

int n, k;
int ans[10];
int cnt = 0;
bool flag = true;

void backtracking(int depth, int sum){;
    if(flag == false || sum > n) return;

    if(sum == n){
        cnt++;
        if(k == cnt){
            flag = false;
            
            int i = 0;
            for( i = 0; i < depth - 1; i++){
                cout<<ans[i]<<"+";
            }
            cout<<ans[i]<<"\n";
        }
        return;
    }

    for(int i = 1; i <= 3; i++){
        ans[depth] = i;
        backtracking(depth + 1, sum + i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int idx = 0;

    cin>>n>>k;

    for(int i = 1; i <= 3; i++){
        ans[idx] = i;
        backtracking(idx + 1, i);
    }
    
    if(flag) cout<<-1<<"\n";
    
    return 0;
}

