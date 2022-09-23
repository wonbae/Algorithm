#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<char> oper;
int ans=-987654321;

int operation(char a, int b, int c){
    if(a == '+') return b+c;
    else if(a == '-') return b-c;
    else if(a == '*') return b*c;
}

void solve(int here, int num){
    cout<<here<<"\n";
    if(here == nums.size() - 1){
        ans = max(ans, num);
        return ;
    }

    solve(here+1, operation(oper[here], num, nums[here+1]));
    if(here+2 <= nums.size()-1){
        int tmp = operation(oper[here+1], nums[here+1], nums[here+2]);
        solve(here+2, operation(oper[here], num, tmp));
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    int n;
    cin>>n;
    string str;
    cin>>str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
            oper.push_back(str[i]);
        }else{
            nums.push_back(str[i] - '0');
        }
    }

    solve(0, nums[0]);
    cout<<ans;
    return 0;
}