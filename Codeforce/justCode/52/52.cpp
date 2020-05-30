#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, i = 1;
    cin>>N;
    vector<int> v;
    v.push_back(i);
    i++;
    while(1){
        if(i % 2 == 0 || i % 5 == 0 || i % 3 == 0){
            v.push_back(i);
            cout<<i<<"\n";
            if(v.size() == N){
                cout<<v[N - 1]<<"\n";
                break;
            }
        }
        i++;
    }


    return 0;
}