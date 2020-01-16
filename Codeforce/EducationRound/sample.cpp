// #include<bits/stdc++.h>
// using namespace std;

// #define SIZE 50

// int findBlockProp(int n, int m, int array[][SIZE]){
//     int ans = 0;
//     int cnt;
//     int visit[SIZE][SIZE] = {0,};
//     queue<pair<int, int> > q;
//     int dx[] = {0,1,0,-1};
//     int dy[] = {1,0,-1,0};

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(visit[i][j] == 0){
//                 q.push(make_pair(0,0));
//                 visit[0][0] = 1;
//                 cnt = 1;
//             }
            

//             while(!q.empty()){
//                 int x = q.front().first;
//                 int y = q.front().second;
//                 q.pop();

//                 int idx = 0;
//                 int nx = x + dx[idx];
//                 int ny = y + dy[idx];

//                 if(nx < 0 || nx >= n || ny < 0 || ny >= m){
//                     idx++;
//                 }

//                 if(visit[nx][ny] == 0 && array[nx][ny] == array[x][y]){
//                     q.push(make_pair(nx,ny));
//                     cnt++;
                        
//                 }
                
//             }
//         }
//     }
    


//     return ans;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); 

//     int n,m;
//     int array[SIZE][SIZE] = {0,};

//     cin>>n>>m;

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin>>array[i][j];
//         }
//     }

//     findBlockProp(n,m, array);

//     return 0;
// }

// // 5 5
// // 1 2 3 4 1
// // 1 2 1 3 1
// // 1 1 3 4 5
// // 1 2 3 4 5
// // 1 2 3 3 3