#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

deque<int> dq[1001];

void solve(int idx, int dir){
    int tmp;

    if(dir == 1){
        tmp = dq[idx].back();
        dq[idx].pop_back();
        dq[idx].push_front(tmp);
    }else{
        tmp = dq[idx].front();
        dq[idx].pop_front();
        dq[idx].push_back(tmp);
    }
}

int main(){
    fastio; 
    int t, k, idx, dir=0, p=0,ans=0;
    string str;

    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>str;
        for(int j = 0; j < str.size(); j++){
            dq[i].push_back(str[j]-'0');
        }
    }

    // cout<<"\nbase\n";
    // for(int i = 0; i < t; i++){
    //     for(int n : dq[i]){
    //         cout<<n<<" ";
    //     }cout<<"\n";
    // }

    cin>>k;

    for(int i = 0; i < k; i++){
        vector<pair<int, int> > check;
        cin>>idx>>dir;
        idx--;
        check.push_back({idx,dir});
        
        p = dir;

        for(int j = idx; j < t-1; j++){
            if(dq[j][2] != dq[j+1][6]){
                p *= (-1);
                check.push_back({j+1, p});
            }else{
                break;
            }
        }

        p = dir;
        for(int j = idx; j > 0; j--){
           if(dq[j][6] != dq[j-1][2]){
                p *= (-1);
                check.push_back({j-1, p});
           }else break;
        }
        
        for(int j = 0; j < check.size(); j++){
            int index = check[j].first;
            int direction = check[j].second;
            
            solve(index, direction);
        }

        // cout<<"\nduring\n";
        // for(int i = 0; i < t; i++){
        //     for(int n : dq[i]){
        //         cout<<n<<" ";
        //     }cout<<"\n";
        // }
    }

    for(int i = 0; i < t; i++){
        if(dq[i].front() == 1) ans++;
    }
    cout<<ans;

    return 0;
}