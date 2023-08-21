// #include<bits/stdc++.h>
// using namespace std;
// #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// int n, m;
// vector<int> v;

// void backt(int cnt, int idx){
//     if(cnt == m){
//         for(int i = 0; i < m; i++){
//             cout << v[i] << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     for(int i = idx; i < n; i++){
//         v[cnt] = i + 1;
//         backt(cnt + 1, i);
//     }
//     return;
// }

// int main(){
//     fastio;
    
//     cin >> n >> m;
//     v.resize(m);

//     backt(0, 0);

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int n, m;
vector<int> v;

void backt(int cnt, vector<int>& combination){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << combination[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        combination[cnt] = v[i];
        backt(cnt + 1, combination);
    }
    return;
}

int main(){
    fastio;
    
    cin >> n >> m;
    v.resize(n);

    for(int i = 1; i <= n; i++){
        v[i-1] = i;
    }

    vector<int> combination(m);
    backt(0, combination);

    return 0;
}
