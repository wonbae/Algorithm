#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int num;
        int two = 0;
        int five = 0;

        cin>>num;

        for(int i = 2; i <= num; i *= 2){
            two += num/i;
        }

        for(int j = 5; j <= num; j *= 5){
            five += num/j;
        }

        cout<<min(two, five)<<"\n";
    }
    return 0;
}