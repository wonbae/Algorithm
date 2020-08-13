#include<iostream>
using namespace std;

int nums[10] = {0,};
bool ch[10] = {false,};
int n, a = 0, b = 0;

void DFS(int depth){
    if(depth > n){
        for(int i = 0; i < n; i++){
            if(ch[i]){
                a+=nums[i];
            }else{
                b+=nums[i];
            }
        }
        if(a == b){
            cout<<"YES"<<"\n";
            return ;
        }
        return ;
    }else{
        ch[depth] = true;
        DFS(depth + 1);
        ch[depth] = false;
        DFS(depth + 1);
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    DFS(1);

    return 0;
}