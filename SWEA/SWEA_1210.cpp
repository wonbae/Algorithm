#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int T = 0;
    int data[101][101] = {0,};

    for(int tc = 0; tc < 10; tc++){
        cin>>T;
        int x,y;
        
        //초기화
        memset(data,0,sizeof(data));

        //test_case 받기
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                cin>>data[i][j];
                if (data[i][j] == 2){
                    x = i;
                    y = j;
                }
            }
            
        }

        //탐색
        while(x >= 0)
        {
            x--;
            //왼쪽
            if(data[x][y-1] == 1){
                do{
                    y--;
                }while(data[x][y - 1] == 1);
            }
            //오른쪽
            else if(data[x][y+1] == 1){
                do{
                    y++;
                }while(data[x][y + 1] == 1);
            }
        }
        cout<<"#"<<T<<" "<<y<<endl;
        
    }
    return 0;
}