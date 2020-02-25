#include<bits/stdc++.h>
using namespace std;

int facto5(int n){
    int cnt = 0;
    int val = n;
    // for(int i = 5; i <= n; i *= 5){
    //     cnt += n / i;
    // }
    while(val > 0){
        val /= 5;
        cnt += val;
    }

    return cnt;
}

int facto2(int n){
    int cnt = 0;
    int val = n;
    // for(int i = 2; i <= n; i *= 2){
    //     cnt += n / i;
    // }

    while(val > 0){
        val /= 2;
        cnt += val;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, r;
    cin>>n>>r;

    // nCr = nPr/r! = n! / (r! (n - r)!)
    int res2 = facto2(n) - facto2(r) - facto2(n - r);
    int res5 = facto5(n) - facto5(r) - facto5(n - r);
    
    int answer = min(res2, res5);
    cout<<answer<<"\n";

    return 0;
}