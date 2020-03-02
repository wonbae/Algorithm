#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> beg;
vector<int> en;

void hanoi(int st, int en, int n){
    if(n <= 0) return;

    hanoi(st, 6 - st - en, n - 1);
    cout<<st<<" "<<en<<"\n";
    hanoi(6 - st - en, en, n - 1);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    cout<<(1 << n) - 1<<"\n";
    hanoi(1, 3, n);
    
    return 0;
}