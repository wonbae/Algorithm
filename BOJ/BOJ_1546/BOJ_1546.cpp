#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, max = 0;
    double sum = 0;
    double score[1000];

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>score[i];
        if(max < score[i]){
            max = score[i];
        }
    }
    for(int i = 0; i < n; i++){
        score[i] = (score[i] / max) * 100;
        sum += score[i];
    }
    double res = sum / n;
    
    cout<<res<<"\n";

    return 0;
}
