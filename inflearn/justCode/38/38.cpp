//Inversion Sequence
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n;
    cin>>n;
    vector<int> is(n + 1), os(n + 1);

    for(int i = 1; i <= n; i++){
        cin>>is[i];
    }

    for(int i = n; i >= 1; i--){
        int pos = i;
        for(int j = 1; j <= is[i]; j++){
            os[pos] = os[pos + 1];
            pos++;
        }
        os[pos] = i;
    }

    for(int i = 1; i <= n; i++){
        cout<<os[i]<<" ";
    }cout<<"\n";

    return 0;
}