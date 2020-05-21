#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[4001], b[4001], c[4001], d[4001];
int combine1[16000001], combine2[16000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            combine1[i*N + j] = a[i] + b[j];
            combine2[i*N + j] = c[i] + d[j];
        }
    }

    sort(combine2, combine2+(N*N));

    ll res = 0;
    for(int i = 0; i < N*N; i++){
        res += (upper_bound(combine2, combine2+(N*N), -combine1[i]) - lower_bound(combine2, combine2+(N*N), -combine1[i]));
    }

    cout<<res<<"\n";
    return 0;
}