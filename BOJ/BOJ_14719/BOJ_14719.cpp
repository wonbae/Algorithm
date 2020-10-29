#include <iostream>
#include <vector>
using namespace std;

vector<int> v(100);
int h, w;

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
    for(int j = i + 1; j < w; j++){
        if(maxi < v[j]){
            maxi = v[j];
        }
    }
    return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ans = 0;
    cin>>h>>w;
    v.resize(w + 1);

    for(int i = 0; i < w; i++){
        cin>>v[i];
    }

    for(int i = 1; i < w - 1; i++){
        int left_max = lm(i);
        int right_max = rm(i);
        int hi = left_max < right_max ? left_max : right_max;

        if(v[i] < hi){
            ans += hi - v[i];
        }
    }

    cout<<ans<<"\n";

    return 0;
}