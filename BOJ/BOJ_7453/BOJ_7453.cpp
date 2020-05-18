#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> a(N), b(N), c(N), d(N);
    for(int i = 0; i < N; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    for(int i = 0; i < N; i++){
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<"\n";
    }


    return 0;
}