#include<bits/stdc++.h>
using namespace std;

#define SIZE 30000

int solution(int x, int y, int x2, int y2){
    return abs(x - x2) + abs(y - y2);
}

int dist(int x, int y){
    return x > y ? abs(x - y) : abs(y - x);
}

bool desc(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    int N;

    cin>>T;

    while(T--){
        int score[SIZE][2] = {0,};
        vector<pair<int, int> > v; // <distance, index>

        int x, y;

        cin>>N;

        for(int i = 0; i < N; i++){
            cin>>x>>y;
            score[i][0] = x;
            score[i][1] = y;
            v.push_back(make_pair(dist(x,y), i));
        }

        sort(v.begin(), v.end(), desc);

        int idx = v[0].second;  // 제일 큰거의 score index
        int idx2 = v[1].second; //2번째로 큰거의 index

        // cout<<"index : "<<idx<<", "<<idx2<<"\n";
        // cout<<score[idx][0]<<", "<<score[idx][1]<<"\n";
        // cout<<score[idx2][0]<<", "<<score[idx2][1]<<"\n";

        int ans = solution(score[idx][0],score[idx][1], score[idx2][0], score[idx2][1]);  // 좌표 (x, y, x2, y2)

        cout<<ans<<"\n";

    }




    return 0;
}




// 10
// 1 1
// -9 10
// -6 1
// -7 -7
// -7 -16
// 2 -7
// 5 6
// 6 -3
// 7 10
// -3 9

// 5
// 0 -1000000
// 0 500000
// 0 0
// 0 -500000
// 0 1000000