#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c, res;
    int count[10] = {0,};

    cin>>a>>b>>c;

    res = a * b * c;

    while(true){
        if(res == 0){
            break;
        }
        int remain = res % 10;
        res = res / 10;
        // cout<<"remain : "<<remain<<"\n";
        count[remain]++;
    }
    
    for(int i = 0; i < 10; i++){
        cout<<count[i]<<"\n";
    }

    return 0;
}