#include <iostream>
#include <algorithm>
#define LIMIT 100
using namespace std;

int arr[LIMIT][LIMIT] = {0,};
int main(){

    for(int tc = 0; tc < 10; tc++){
        int T = 0;
        cin>>T;
        int sum[LIMIT*2+2] = {0,};
        int count = 0;
        
        //초기화
        for(int i = 0; i<LIMIT; i++){
            for(int j = 0; j<LIMIT; j++){
                cin>>arr[i][j];
            }
            
        }
        
        //row sum
        for(int i = 0; i<LIMIT; i++){
            for(int j = 0; j<LIMIT; j++){
                sum[count] += arr[i][j];    
            }
            count++;
        }

        //col sum
        for(int i = 0; i<LIMIT; i++){
            for(int j = 0; j<LIMIT; j++){
                sum[count] += arr[j][i];    
            }
            count++;
        }


        // 대각선 sum        
        for(int i = 0; i<LIMIT; i++){
            sum[count] += arr[i][i];  
            sum[count+1] += arr[i][99-i]; 
        }



        
        sort(sum, sum+(LIMIT*2+2));
        
        // result = sum[count+1];
        
        cout<<"#"<<T<<" "<<sum[count+1]<<endl;
    }
}
