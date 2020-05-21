#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    return abs(a) < abs(b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N, a[100001], lt = 0, rt, mini = 2147000000, ans1 = 0, ans2 = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }

    sort(a, a+N, compare);

    for(int i = 0; i < N - 1; i++){
        if(abs(a[i] + a[i + 1]) < mini){
            mini = abs(a[i] + a[i + 1]);
            ans1 = a[i];
            ans2 = a[i + 1];
        }
    }
    if(ans1 < ans2){
        cout<<ans1<<" "<<ans2<<"\n";
    }else{
        cout<<ans2<<" "<<ans1<<"\n";
    }
    return 0;
}