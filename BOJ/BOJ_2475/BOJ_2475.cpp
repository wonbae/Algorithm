#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum = 0;
    for(int i = 0; i < 5; i++){
        cin>>n;
        sum += pow(n,2);
    }
    cout<<sum % 10<<"\n";
    return 0;
}