#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
int get_min(int a, int b, int c)
{
    return (a > b) ? ((b < c) ? c : b) : ((a < c) ? a : c);
}

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    int raw = board.size();
    int col = board[0].size();
    
    int map[1000][1000] = {0,};
    
    for(int i = 0; i < raw; i++){
        for(int j = 0; j < col; j++){
            map[i][j] = board[i][j];
        }
    }
    int tmp, max = 0;
    for(int i = 1; i < raw; i++){
        for(int j = 1; j < col; j++){
            if(map[i][j] == 1){
                tmp = get_min(map[i-1][j], map[i - 1][j - 1], map[i][j - 1]);
                map[i][j] = tmp + 1;
                if(map[i][j] > max){
                    max = map[i][j];
                    answer = max*max;
                }
            }else{
                continue;
            }
        }
    }
    // for(int i = 0; i < raw; i++){
    //     for(int j = 0; j < col; j++){
    //         cout<<map[i][j];
    //     }cout<<endl;
    // }
    if(max == 0){
        return 1;
    }else{
        return max*max;
    }
    
    return answer;
}
