#include <iostream>
#include <string.h>

using namespace std;
int main(){

    int Palindrome_Len,len;
    char Teststr[8][8] = {0,};
    len = sizeof(Teststr[0]);
    int count = 0;
    bool flag = false;
    

    for(int tc = 1; tc <= 10; tc++){
        cin>>Palindrome_Len;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin>>Teststr[i][j];
            }
        }
        
        //Row
        count = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len - Palindrome_Len + 1; j++)
            {
                int left = j;
                int right = j + Palindrome_Len - 1;
                

                while(left <= right){
                    if(Teststr[i][left] == Teststr[i][right])
                    {
                        left++;
                        right--;
                        // count++;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                        
                    }
                }
                if(flag){
                    count++;
                    flag = false;
                }
            }
        }

        //Column
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len-Palindrome_Len+1; j++)
            {
                int top = j;
                int bottom = j + Palindrome_Len - 1;
                

                while(top <= bottom){
                    if(Teststr[top][i] == Teststr[bottom][i])
                    {
                        top++;
                        bottom--;
                        // count++;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                        
                    }
                }
                if(flag){
                    count++;
                    flag = false;
                }
                
            }
        }

        cout<<"#"<<tc<<" "<<count<<endl;
        

    }



    return 0;
}