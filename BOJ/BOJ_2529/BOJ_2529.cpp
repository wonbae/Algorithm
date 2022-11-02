#include<bits/stdc++.h>
using namespace std;

char a[10];
bool check[10];
int k;
vector<string> ans;

bool comp(char a, char b, char op){
    if(a > b && op == '>') return true;
    if(a < b && op == '<') return true;
    return false;
}

void solve(int idx, string nums){
    if(idx == k+1){
        ans.push_back(nums);
        return ;
    }

    for(int i = 0; i <= 9; i++){
        if(check[i]) continue;
        if(idx == 0 || comp(nums[idx-1], i+'0', a[idx-1])){
            check[i] = 1;
            solve(idx+1, nums+to_string(i));
            check[i] = 0;
        }
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    cin>>k;
    for(int i = 0; i < k; i++){
        cin>>a[i];
    }

    solve(0, "");

    sort(ans.begin(), ans.end());

    cout<<ans[ans.size()-1]<<"\n"<<ans[0]<<"\n";

    return 0;
}