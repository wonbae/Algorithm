#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int T = 0;
    cin>>T;
    
    for(int tc = 0; tc < 10; tc++){
        int data[100][100] = {0,};
        int x=0,y=0;

        //초기화
        //memset(data,0,sizeof(data));

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

        // for(int i = 0; i < 100; i++)
        // {
        //     for(int j = 0; j < 100; j++)
        //     {
        //         cout<<data[i][j];
        //     }
        //     cout<<endl;
        // }

        while(x >= 0)
        {
            x--;
            if(data[x][y-1] == 1){
                do{
                    y--;
                }while(data[x][y - 1] == 1);
            }
            else if(data[x][y+1] == 1){
                do{
                    y++;
                }while(data[x][y + 1] == 1);
            }
        }
        cout<<"#"<<T<<" "<<y+1<<endl;
        
    }
    return 0;
}