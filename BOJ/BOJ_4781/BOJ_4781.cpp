#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

struct info{
    int cal;
    float price;
};

int knapsack(float capacity, vector<info>& items){
    vector<int> dp(capacity + 1, 0);
    
    for(int i = 1; i <= capacity; i++){
        for(auto item : items){
            if(item.price <= i){
                dp[i] = max(dp[i], dp[i - item.price] + item.cal);
            }
        }
    }

    return dp[capacity];
}


int main(){
    fastio;

    int n;
    float capacity;

    while(true){
        cin>>n>>capacity;

        capacity = int((capacity*100) + 0.5);

        if(n == 0 && capacity == 0.00) break;

        vector<info> items(n);

        for(int i = 0; i < n; i++){
            float tmp;
            cin>>items[i].cal;
            cin>>tmp;
            items[i].price = int(tmp * 100 + 0.5);
        }

        cout<<knapsack(capacity, items)<<"\n";

    }

    return 0;
}