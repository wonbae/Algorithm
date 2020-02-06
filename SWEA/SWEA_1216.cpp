#include <iostream>
#include <string.h>
using namespace std;

char map[100][100] = {0,};

int main(){
    int T,len = sizeof(map[0]);
    int Pelindrome_Len = 1, Max_Plen = INT_MIN;   //처음 찾을 펠린드롬 길이는 1, 펠린드롬들 중 가장 큰 길이 저장하는 max_Plen
    int left = 0, right = 0, top = 0, down = 0;
    bool flag = false;                            //진짜 펠린드롬인지 확인할 flag

    while(T <= 10){
        cin>>T;

        //초기화
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                cin>>map[i][j];
            }
        }

        //row
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len - Pelindrome_Len + 1 ; j++){
                left = j;
                // right = len - Pelindrome_Len + i;
                right = j + Pelindrome_Len - 1;

                while(left <= right)
                {
                    if(map[i][left] == map[i][right])
                    {
                        left++;
                        right--;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(Max_Plen < Pelindrome_Len){
                        Max_Plen = Pelindrome_Len;
                        Pelindrome_Len++;
                    }
                    
                    flag = false;
                }
            }
        }


        //column
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len - Pelindrome_Len + 1 ; j++){
                top = j;
                // right = len - Pelindrome_Len + i;
                down = j + Pelindrome_Len - 1;

                while(top <= down)
                {
                    if(map[top][i] == map[down][i])
                    {
                        top++;
                        down--;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    if(Max_Plen < Pelindrome_Len){
                        Max_Plen = Pelindrome_Len;
                        Pelindrome_Len++;
                    }
                    flag = false;
                }
            }
        }

        cout<<"#"<<T<<" "<<Max_Plen<<endl;
        T++;
    }
    return 0;
}