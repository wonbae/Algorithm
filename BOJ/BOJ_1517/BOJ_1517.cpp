#include <bits/stdc++.h>
 
using namespace std;
 
struct ar {
    int val, idx;
}arr[500000];
 
bool cmp(ar a, ar b) {
    return a.val > b.val;
}
 
int n, tree[500001];
 
void update(int idx) {
    while (idx <= n) {
        tree[idx]++;
        // cout<<"update : "<<tree[idx]<<"\n";
        idx += (idx & -idx);
    }
}
 

int sum(int idx) {
    int ans = 0;
 
    while (idx > 0) {
        ans += tree[idx];
        // cout<<"idx: "<<idx<<" tree : "<<tree[idx]<<" ans : "<<ans<<"\n";
        idx -= (idx & -idx);
    }
 
    return ans;
}


void printree(){
    for(int i = 0; i< n+2; i++){
        cout<<tree[i]<<" ";
    }cout<<"\n";
}
 

int main() {
    int i;
    long long ans = 0;
 
    scanf("%d", &n);
 
    for (i = 0;i < n;++i) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i + 1;
    }
 
    sort(arr, arr + n, cmp);
 
    for (i = 0;i < n;++i) {
        ans += sum(arr[i].idx - 1);
        update(arr[i].idx);
        printree();
    }
 
    printf("%lld", ans);
 
    return 0;
}