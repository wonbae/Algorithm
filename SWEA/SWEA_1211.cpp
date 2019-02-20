#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int map[101][101] = {0,};


int main(){
    int cnt = 0;
    int T,x,y,start_point;
    int min_count = INT_MAX;
    

    for(int tc = 0; tc < 10; tc++){
        cin>>T;

        memset(map, 0, sizeof(map));    //초기화

        for(int i = 0; i < 100; i++){   //TestCase입력
            for(int j = 0; j < 100; j++){
                cin>>map[i][j];
            }
        }
       
       
        for(int j = 0; j < 100; j++){      //출발점에 1 찾기
            if(map[0][j] == 1){
                x = 0;
                y = j;

                while(x < 99){  //map[][]의 index 0 ~ 99
                    
                    x++;

                    if(map[x][y+1] == 1){   //오른쪽
                        do{
                            y++;
                            cnt++;
                        }while(map[x][y+1] == 1);
                    }
                    else if(map[x][y-1] == 1){  //왼쪽
                        do{
                            y--;
                            cnt++;
                        }while(map[x][y-1] == 1);
                    }

                }

                // cout<<"Total : "<<x+count<<", X : "<<x<<", Y : "<<y<<", count : "<<count<<endl;

                if(min_count > (x+cnt)) //좌우로 움직인 cnt, 세로로 이동한 x의 총합이 이동경로
                {
                    min_count = (x+cnt);
                    start_point = j;
                }
                // cout<<"min_count : "<<min_count<<endl;
                // cout<<"start_point : "<<start_point<<endl;

                cnt = 0;
                // cout<<"========================"<<endl;
            }
        }

        cout<<"#"<<T<<" "<<start_point<<endl;
        min_count = INT_MAX, start_point = 0;   //초기화 중요
    }


    return 0;
}
