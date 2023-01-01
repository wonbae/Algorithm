#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int visited[104];
int a[104];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    int n, k, ans=0;
    cin>>n>>k;
    vector<int> multi;
    for(int i = 0; i < k; i++){
        cin>>a[i];
    }

    for(int i = 0; i < k; i++){
        if(!visited[a[i]]){
            if(multi.size() == n){ //concent 꽉차있으면
                int pos, last=0;
                for(int v : multi){
                    int here = INF;
                    for(int j = i+1; j < k; j++){
                        if(v == a[j]){
                            here = j;
                            break;
                        }
                    }
                    if(last < here){
                        last = here;
                        pos = v;
                    }
                }
                visited[pos] = 0;
                multi.erase(find(multi.begin(), multi.end(), pos));
                ans++;
            }
            multi.push_back(a[i]);
            visited[a[i]]++;
        }        
    }

    cout<<ans<<"\n";

    return 0;
}