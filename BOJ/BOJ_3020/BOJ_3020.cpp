#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int N, H, mini = 2147000000, cnt = 0;
    cin>>N>>H;
    vector<int> v1(N/2), v2(N/2);

    for(int i = 0; i < N/2; i++){
        cin>>v1[i]>>v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for(int i = 1; i <= H; i++){
        int a = v1.size() - (lower_bound(v1.begin(), v1.end(), i) - v1.begin());
        int b = v2.size() - (lower_bound(v2.begin(), v2.end(), H - i + 1) - v2.begin());
        if(a + b < mini){
            mini = a + b;
            cnt = 1;
        }else if(a + b == mini) cnt++;
    }

    cout<<mini<<" "<<cnt<<"\n";
    return 0;
}