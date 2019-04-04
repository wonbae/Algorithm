class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size() , col = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    count++;
                    BFS(i,j,grid);
                }
            }
        }
        return count;
        
    }
private:
    void BFS(int x, int y, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        bool visited[grid.size()][grid.size()]; // 방문했는지를 표시하는 지도
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        q.push({x,y});
        visited[x][y] = true;
        
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < grid.size() && 0 <= ny && ny < grid[0].size()){
                    if(visited[nx][ny] == false && grid[nx][ny] == 1){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            
        }   
    }
    
};
