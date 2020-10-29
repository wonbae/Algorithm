#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(100);
int n, x;

int lm(int i){
    int maxi = -2147000000;
    for(int j = i - 1; j >= 0; j--){
        if(maxi < v[j]){
            maxi = v[j];
        }
    }
    return maxi;
}

int rm(int i){
    int maxi = -2147000000;
    for(int j = i + 1; j < n; j++){
        if(maxi < v[j]){
            maxi = v[j];
        }
    }
    return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool flag = false;
    int ans = 0;
    cin>>n>>x;

    v.resize(n, 0);

    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }

    do{
        ans = 0;
        for(int i = 1; i < n - 1; i++){
            int left_max = lm(i);
            int right_max = rm(i);
            int hi = left_max < right_max ? left_max : right_max;

            if(v[i] < hi){
                ans += hi - v[i];
            }
            if(ans > x) break;
        }
        if(ans < x) break;
        if(ans == x){
            flag = true;
            for(int i = 0; i < v.size(); i++){
                cout<<v[i]<<" ";
            }
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    if(!flag){
        cout<<-1;
    }
    return 0;
}