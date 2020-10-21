#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1 - 위, 2 - 아래, 3 - 왼쪽, 4 - 오른쪽
struct dinfo{
    int U;
    int D;
    int L;
    int R;
    dinfo(int a, int b, int c, int d){
        U = a;
        D = b;
        L = c;
        R = d;
    }
};

struct shark{
    int r;
    int c;
    int smell;
    int dir;
    int sknum;
    shark(int a, int b, int s, int d, int sn){
        r = a;
        c = b;
        smell = s;
        dir = d;
        sknum = sn;
    }
};

const int dir[5][2] = {   {0, 0},
                    {-1, 0}, 
                    {1, 0}, 
                    {0, -1},
                    {0, 1} };

int Map[21][21];
int visit[21][21];
int N, M, K;
vector<dinfo> sd[401];
vector<int> order(401);
vector<shark> s;
vector<pair<int, int> > rc;

int TIME = 0;

int onlyOne(){
    bool flag = false;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visit[i][j] == 0) continue;
            else{
                if(visit[i][j] == 1) flag = true;
                else flag = false;
            }
        }
    }
    if(TIME > 1000 && !flag) return -1;
    return flag;
}

void move(){
    queue<shark> q;
    for(int i = 1; i <= M; i++){
        q.push(shark(rc[i].first, rc[i].second, K, order[i], i));
    }

    for(int i = 0; i < M; i++){
        cout<<q.front().sknum<<", ";
        q.pop();
    }

    int t = q.size();
    while(t--){
        TIME++;
    }
    
}

void solve(){
    while(1){
        if(onlyOne() == 1){
            cout<<TIME<<"\n";
            return ;
        }else if(onlyOne() == -1){
            cout<<-1<<"\n";
            return ;
        }else{
            move();
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);   // 1 - 위, 2 - 아래, 3 - 왼쪽, 4 - 오른쪽
    cin.tie(NULL);
    int a, b, c, d;
    cin>>N>>M>>K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>Map[i][j];
            if(Map[i][j] != 0) rc.push_back(make_pair(i, j));
        }
    }
    order.resize(M+1);
    for(int i = 1; i <= M; i++){
        cin>>order[i];
    }

    int sharkNum = 1;
    for(int i = 0; i < 4*M; i++){
        cin>>a>>b>>c>>d;
        sd[sharkNum].push_back(dinfo(a, b, c, d));
        if((i+1) % 4 == 0) sharkNum++;
    }

    // for(int i = 1; i <= M; i++){
    //     for(int j = 0; j < sd[i].size(); j++){
    //         cout<<sd[i][j].U<<", "<<sd[i][j].D<<", "<<sd[i][j].L<<", "<<sd[i][j].R<<"\n";
    //     }
    //     cout<<"\n";
    // }
    solve();

    return 0;
}