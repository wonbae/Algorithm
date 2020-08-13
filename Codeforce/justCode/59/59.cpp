#include<iostream>
using namespace std;

int n;
bool visit[10];

void DFS(int a){
   if(a > n){
       for(int i = 1; i <= n; i++){
           if(visit[i]){
               cout<<i<<" ";
           }
       }cout<<"\n";
       
       return ;
   }
   else{
       visit[a] = true;
       DFS(a + 1);
       visit[a] = false;
       DFS(a + 1);
   }
}

int main(){
    cin>>n;
    DFS(1);
    return 0;
}