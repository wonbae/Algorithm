#include<iostream>
#include<vector>
using namespace std;

int num;
int sum;
vector<int> arr;

void dfs(int res, int idx){
    
    


}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>num;
        arr.resize(num, 0);
        for(int i = 1; i <= num; i++){
            arr[i-1] = i;
        }
        dfs(arr[0], 1);
    }

    return 0;
}