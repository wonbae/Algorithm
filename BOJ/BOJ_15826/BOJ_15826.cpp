#include<bits/stdc++.h>
using namespace std;

long long memorization[10001];



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string num;

    cin>>num;

    cout<<fib(num)<<"\n";

    return 0;
}