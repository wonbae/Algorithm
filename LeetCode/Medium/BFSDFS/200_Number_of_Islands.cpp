class Solution {
    
public:
    int numIslands(vector<vector<char>>& grid) {
        //#1. 브루드포스, 24ms, 11MB
//         if(grid.size() == 0 || grid[0].size() == 0){
//             return 0;
//         }
        
//         int row = grid.size(), col = grid[0].size();
//         int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
//         int count = 0;
//         queue<pair<int,int>> q;
        
//         for(int i = 0; i < row; i++){
//             for(int j = 0; j < col; j++){
             
//                 if(grid[i][j] == '1'){
//                     ++count;
//                     q.push({i,j});
//                     grid[i][j] = '0';
                    
//                     while(!q.empty()){
//                         int x = q.front().first;    //q.front()[0];
//                         int y = q.front().second;   //q.front()[1];
                        
//                         q.pop();
                        
//                         for(int idx = 0; idx < 4; idx++){
//                            int nx = x + dx[idx];
//                            int ny = y + dy[idx];
                            
//                             if(0 <= nx && nx < row && 0 <= ny && ny < col && grid[nx][ny] == '1'){
//                                     grid[nx][ny] = '0';
//                                     q.push({nx,ny});
                                   
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return count;
        
        
        //#2. 16ms, 11MB
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        
        int row = grid.size(), col = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    count++;
                    BFS(i,j,grid);    
                }
                
            }
        }
        return count;
            
        
    }
    
    void BFS(int x, int y, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
        int row = grid.size(), col = grid[0].size();
        
        if(grid[x][y] == '1'){
            q.push({x,y});
            grid[x][y] = '0';
            
            while(!q.empty()){
                int nx = q.front().first;
                int ny = q.front().second;
                
                q.pop();
                
                for(int idx = 0; idx < 4; idx++){
                    int nox = nx + dx[idx];
                    int noy = ny + dy[idx];
                    
                    if(0 <= nox && nox < row && 0 <= noy && noy < col && grid[nox][noy] == '1'){
                        q.push({nox,noy});
                        grid[nox][noy] = '0';
                    }
                }
            }
        }
        
        
    }

    
};
