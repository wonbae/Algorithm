#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;


    string a[n+1];
    int map[101][101] = {0,};

    

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(a[i][j] == 'X'){
                map[i][j] = 1;
            }
            else if(a[i][j] == '.'){
                map[i][j] = 0;
            }

        }
    }


    int with = 0;   // 가로

    for(int i = 0; i < n; i++){
        int count = 0; 
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0){
                count++;
            }
            else if(map[i][j] == 1){
                if(count == 0){
                    continue;
                }else{
                    count = 0;
                }
                
            }

            if(count == 2){
                with++;
                continue;
            }
        }
    }


    int vertical = 0;   // 세로

    for(int j = 0; j < n; j++){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(map[i][j] == 0){
                count++;
            }
            else if(map[i][j] == 1){
                if(count == 0){
                    continue;
                }else{
                    count = 0;
                }
                
            }

            if(count == 2){
                vertical++;
                continue;
            }
        }
    }

    cout<<with<<" "<<vertical<<"\n";


    return 0;
}