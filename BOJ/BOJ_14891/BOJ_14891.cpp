#include<bits/stdc++.h>
using namespace std;

int Gear[8][8] = {0,};

void Move(int gearindex, int dir);
void CheckNS(int index, int dir){
    int connect[4] = {0,};

    connect[index] = dir;

    for(int i = index; i < 3; i++){
        if(Gear[i][2] != Gear[i + 1][6]){
            connect[i + 1] = connect[i] * (-1);
        }
    }

    for(int i = index; i > 0; i--){
        if(Gear[i][6] != Gear[i - 1][2]){
            connect[i - 1] = connect[i] * (-1);
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(connect[i]){
            Move(i, connect[i]);
        }
    }
}

void Move(int index, int dir){

    if(dir == 1){    //시계방향
        int i, tmp = Gear[index][7];
        for(i = 7; i > 0; i--){
            Gear[index][i] = Gear[index][i - 1];
        }
        Gear[index][i] = tmp;
        
    }else{
        int i, tmp = Gear[index][0];
        for(i = 0; i < 7; i++){
            Gear[index][i] = Gear[index][i + 1];
        }
        Gear[index][i] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;
    
    int K;
    int dir;
    int gearindex;

    for(int i = 0; i < 4; i++){
        cin>>input;

        for(int j = 0; j < 8; j++){
            Gear[i][j] = input[j] - '0';
        }
    }

    cin>>K;

    for(int i = 0; i < K; i++){
        cin>>gearindex>>dir;

        CheckNS(gearindex - 1, dir);
    }

    int sum = 0;
    for(int i = 0; i < 4; i++){
        if(Gear[i][0] == 1){
            if(i + 1 == 1) sum += 1;
            else if(i + 1 == 2) sum += 2;
            else if(i + 1 == 3) sum += 4;
            else if(i + 1 == 4) sum += 8;   
        }
    }


    cout<<sum<<"\n";


    return 0;
}