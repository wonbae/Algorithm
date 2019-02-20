//SWEA 1954
#include <iostream>
#include <string.h>
int map[11][11];

using namespace std;

int main(){

    int x,y,T,count,Direction,len,Length;
    cin>>T;

    for(int i = 1; i<=T; i++){
        x=0; y=1;
        Direction = 1; count = 1;
        memset(map,0, sizeof(map));

        cin>>len;
        Length = len;

        while(len>=0){
            for(int a = 1; a<=len; a++){
                x+=Direction;
                map[y][x] = count++;
            }
            if(--len<0){
                break;
            }
            for(int k =1 ; k<=len ; k++){
                y+=Direction;
                map[y][x]=count++;
            }
            Direction *= -1;
        }
        cout<<"#"<<i<<endl;

        for(int k = 1; k<=Length ; k++){
            for(int j = 1; j<=Length ; j++){
                cout<<map[k][j]<<" ";
            }cout<<endl;
        }

    }

    return 0;
}

