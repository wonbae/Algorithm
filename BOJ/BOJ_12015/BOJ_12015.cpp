#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    vector<int> v;
    cin>>N;
    cin>>num;
    v.push_back(num);

    for(int i = 1; i < N; i++){
        cin>>num;
        if(num > v.back()){
            v.push_back(num);
        }else{
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }
    cout<<v.size()<<"\n";
    return 0;
}