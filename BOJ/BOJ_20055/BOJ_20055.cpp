#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K, Time;

struct rinfo{
    int negu;
    int human;
    rinfo(){
        negu = 0; human = 0;
    }
    rinfo(int a, int b){
        negu = a;
        human = b;
    }
};

struct rinfo rail[2][201];

void print_negu(){
    cout<<"\n -- negudo -- \n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cout<<rail[i][j].negu<<" ";
        }cout<<"\n";
    }
    return ;
}
void print_robot(){
    cout<<"\n -- robot -- \n";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cout<<rail[i][j].human<<" ";
        }cout<<"\n";
    }
}

void init(){
    // cout<<"\n\n ----- init -----\n";
    int a, b = 0;
    for(int i = 0; i < 2*N; i++){
        cin>>a;
        if(i < N){
            rail[0][i].negu = a;
            rail[0][i].human = 0;
            b++;
        }else{
            b--;
            rail[1][b].negu = a;
            rail[1][b].human = 0;
        }
    }

    // print_negu();
    // print_robot();
    return ;
}

bool stop(){
    int cnt = 0;

    // print_negu();
    // print_robot();

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            if(rail[i][j].negu == 0) cnt++;
            if(cnt >= K) return true;
        }
    }
    if(cnt >= K) return true;
    // cout<<"\n\n ----- NOT stop -----\n";
    return false;
}

void move(){
    // cout<<"\n\n +++++ move +++++\n";
    rinfo tmp = rail[0][N - 1];
    rinfo tmp2 = rail[1][0];

    for(int i = N - 1; i > 0; i--){
        rail[0][i] = rail[0][i - 1];
    }rail[0][0] = tmp2;

    for(int i = 0; i < N - 1; i++){
        rail[1][i] = rail[1][i + 1];
    }rail[1][N - 1] = tmp;

    if(rail[0][N - 1].human){
        rail[0][N - 1].human = 0;
    }
    // print_negu();
    // print_robot();

    return ;
}

bool isrobot(){
    for(int i = 0; i < N; i++){
        if(rail[0][i].human){
            // cout<<"\n\n ----- 로봇 있음 -----\n";
            return true;
        }
    }
    // cout<<"\n\n ----- 로봇 없음 -----\n";
    return false;
}

void addrobot(){
    // cout<<"\n\n <===== add robot =====>\n";
    if(rail[0][0].negu >= 1){
        rail[0][0].human = 1;
        rail[0][0].negu -= 1;
        // print_negu();
        // print_robot();
    }
    
    
    return ;
}

void robot_move(){
    // cout<<"\n\n %%%%%%%%% move robot ********** \n";
    for(int i = N - 2; i >= 0; i--){
        if(rail[0][i].human){
            if(rail[0][i + 1].human == 0 && rail[0][i + 1].negu >= 1){
                rail[0][i + 1].human = 1;
                rail[0][i + 1].negu -= 1;
                rail[0][i].human = 0;
            }
        }
    }
    if(rail[0][N - 1].human){
        rail[0][N - 1].human = 0;
    }
    // print_negu();
    // print_robot();
    
    addrobot();
}

void solve(){
    init();
    Time = 1;

    while(1){
        move();

        if(isrobot()){
            robot_move();
        }else{
            addrobot();
        }

        if(stop()){
            break;
        }
        Time++;
    }
    
    return ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;

    solve();
    cout<<Time<<"\n";
    return 0;
}