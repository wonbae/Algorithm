#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, T;
    vector<int> v;
    int sum = 0;
    int answer = 0;

    cin>>T;

    for(int t = 0; t < T; t++){
        cin>>n;
        v.push_back(n);

    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        answer += sum;
    }

    cout<<answer<<"\n";

    return 0;
}