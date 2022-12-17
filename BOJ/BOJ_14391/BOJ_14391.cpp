#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int n, m, ans;
int a[5][5];

int main(){
    FASTIO
    cin>>n>>m;
    

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        for(int j = 0; j < str.size(); j++){
            a[i][j] = str[j]-'0';
        }
    }

    for(int s = 0; s < (1<<(n*m)); s++){
        int sum = 0;

        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                int k = i * m + j;
                if((s & (1<<k)) == 0){
                    cur = cur * 10 + a[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                int k = j * m + i;
                if((s & (1<<k)) != 0){
                    cur = cur * 10 + a[j][i];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ans = max(ans, sum);
    }

    cout<<ans<<"\n";
    return 0;
}