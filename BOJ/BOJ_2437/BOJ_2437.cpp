#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(v[i] <= sum + 1){
            sum += v[i];
        }else{
            break;
        }
    }

    cout<<sum+1<<"\n";


    return 0;
}