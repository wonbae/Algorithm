#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, M, lt = 0, rt, mid, num;
    cin>>N;
    vector<int> v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    
    cin>>M;
    for(int i = 0; i < M; i++){
        lt = 0;
        rt = N - 1;
        bool ok = false;

        cin>>num;

        while(lt <= rt){
            mid = (lt + rt) / 2;
            if(v[mid] == num){
                cout<<1<<" ";
                ok = true;
                break;
            }else if(v[mid] > num){
                rt = mid - 1;
            }else if(v[mid] < num){
                lt = mid + 1;
            }
        }

        if(!ok){
            cout<<0<<" ";
        }
    }
    
    return 0;
}