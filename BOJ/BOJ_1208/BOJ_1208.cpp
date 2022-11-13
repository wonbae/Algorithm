#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0), cin.tie(NULL);

using namespace std;

int N, S;
long long cnt;
vector<int> v;
vector<int> a, b;

void setA(int index, int sum){
    sum += v[index];

    if(index >= N/2){
        return ;
    }
    if(sum == S){
        cnt++;
    }
    
    a.push_back(sum);
    setA(index+1, sum-v[index]);
    setA(index+1, sum); 
}

void setB(int index, int sum){
    sum += v[index];

    if(index >= N){
        return ;
    }
    if(sum == S){
        cnt++;
    }
    
    b.push_back(sum);
    setB(index+1, sum-v[index]);
    setB(index+1, sum);
}

int main(){
    FAST_IO
    cin>>N>>S;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin>>v[i];
    }

    setA(0, 0);
    setB(N/2, 0);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < a.size(); i++){
        int tmp = S - a[i];
        int upper = upper_bound(b.begin(), b.end(), tmp) - b.begin();
        int lower = lower_bound(b.begin(), b.end(), tmp) - b.begin();
        cnt += (upper - lower);
    }

    cout<<cnt<<"\n";

    return 0;
}