#include<bits/stdc++.h>
using namespace std;

bool arr[10001];

void eratos(){
    for(int i = 0; i <= sqrt(10000); i++){
        int idx = pow(i, 2);
        arr[idx] = true;
    }
}
int main(){
    eratos();

    int M, N, sum = 0;
    cin>>M>>N;

    int mini = 987654321;
    for(int i = M; i <= N; i++){
        if(arr[i]){
            sum += i;
            mini = min(mini, i);
        }
    }

    if(sum == 0 || mini == 987654321) cout<<-1<<"\n";
    else cout<<sum<<"\n"<<mini<<"\n";
    
    return 0;
}