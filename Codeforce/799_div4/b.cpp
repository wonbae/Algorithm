#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        deque<int> v(n);
        for(int i = 0; i < v.size(); i++){
            cin>>v[i];
        }

        int lt = 0, rt = v.size() - 1;
        while(lt != rt){
            if(v[lt] != v[rt]){
                
            }
        }

    }
    return 0;
}