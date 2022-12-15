#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int t,n;
    string promt, nums;
    cin>>t;

    while(t--){
        cin>>promt;
        cin>>n;
        cin>>nums;

        deque<int> dq;
        int x = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == '[' || nums[i] == ']') continue;
            else if(nums[i] == ','){
                dq.push_back(x);
                x = 0;
            }
            else{
                x = x * 10 + nums[i]-'0';
            }
        }
        
        if(x>0) dq.push_back(x);

        bool rev = false, error = false;
        for(int i = 0; i < promt.size(); i++){
            if(promt[i] == 'R'){
                rev = !rev;
            }else{
                if(dq.empty()){
                    error = true;
                    break;
                }else{
                    if(rev) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }

        if(error) cout<<"error\n";
        else{
            if(rev){
                reverse(dq.begin(), dq.end());
            }

            cout<<"[";
            for(int i = 0; i < dq.size(); i++){
                cout<<dq[i];
                if(i != dq.size() - 1) cout<<",";
            }cout<<"]\n";
        }
    }
    return 0;
}