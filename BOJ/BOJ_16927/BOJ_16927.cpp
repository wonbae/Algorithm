#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, r, c, mod;
    cin>>n>>m>>r;
    vector<vector<int> > v(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    if(m < n) c = m / 2;
    else c = n / 2;

    // mod = 2 * (n + m - 4 * (c - 2));
    // r %= mod;

        for(int t = 0; t < c; t++){
            int T = t;
            int B = n - 1 - t;
            int R = m - 1 - t;
            int L = t;
            int rr = r %(2 * (R-L+1) + 2 * (B-T+1) - 4);
            while(rr--){
                int tmp = v[t][t];
                for(int i = L; i < R; i++) v[T][i] = v[T][i + 1];
                for(int i = T; i < B; i++) v[i][R] = v[i + 1][R];
                for(int i = R; i > L; i--) v[B][i] = v[B][i - 1];
                for(int i = B; i > T; i--) v[i][L] = v[i - 1][L];
                v[T + 1][L] = tmp;
            }
        }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }

    return 0;
}