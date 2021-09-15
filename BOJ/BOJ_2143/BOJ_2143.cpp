#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int T, n, m;
    cin>>T>>n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        cin>>v1[i];
    }
    cin>>m;
    vector<int> v2(m);
    for(int i = 0; i < m; i++){
        cin>>v2[i];
    }

    for(int i = 0; i < n; i++){
        int sum = v1[i];    
        for(int j = i + 1; j < n; j++){
            sum += v1[j];
            v1.push_back(sum);
        }
    }

    for(int i = 0; i < m; i++){
        int sum = v2[i];
        for(int j = i + 1; j < m; j++){
            sum += v2[j];
            v2.push_back(sum);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int lt = 0, rt = v2.size()-1;
    long long ans = 0;

    while(lt < v1.size() && rt >= 0){
        if(v1[lt] + v2[rt] > T){
            rt--;
        }else if(v1[lt] + v2[rt] < T){
            lt++;
        }else if(v1[lt] + v2[rt] == T){

            long long cnt = 1, cnt2 = 1;

            while(v1[lt] == v1[lt+1] && lt+1 < v1.size()){
                cnt++;
                lt++;
            }
            while(v2[rt] == v2[rt-1] && rt-1 >= 0){
                cnt2++;
                rt--;
            }
            ans+=cnt*cnt2;
            lt++, rt--;
        }
    }

    cout<<ans<<"\n";
    return 0;
}