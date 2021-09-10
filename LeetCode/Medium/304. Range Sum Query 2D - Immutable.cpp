class NumMatrix {
public:
    
    vector<vector<long long>> vec;
    int n,m;
    
    NumMatrix(vector<vector<int>>& matrix) {
        m = int(matrix.size());
        n = int(matrix[0].size());
        
        vec.resize(m+1, vector<long long>(n+1,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vec[i+1][j+1] = matrix[i][j] 
                                + vec[i+1][j] 
                                + vec[i][j+1] 
                                - vec[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return int(vec[row2+1][col2+1] 
                   - vec[row2+1][col1] 
                   - vec[row1][col2+1] 
                   + vec[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */