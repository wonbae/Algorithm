#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> dpASC(n + 1, 1);
    vector<int> dpDESC(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                dpASC[i] = max(dpASC[i], dpASC[j] + 1);
            }
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = n; j > i; j--){
            if(v[i] > v[j]){
                dpDESC[i] = max(dpDESC[i], dpDESC[j] + 1);
            }
        }
    }


    // for(int i = 1; i <= n; i++){
    //     cout<<dpASC[i]<<" ";
    // }cout<<"\n";

    // for(int i = 1; i <= n; i++){
    //     cout<<dpDESC[i]<<" ";
    // }cout<<"\n\n";



    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], dpASC[i] + dpDESC[i]);
    }

    cout << *max_element(ans.begin(), ans.end()) - 1;

    return 0;
}
