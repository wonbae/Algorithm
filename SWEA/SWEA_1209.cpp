// #include <iostream>
// #include <algorithm>
// #define LIMIT 100
// using namespace std;

// int arr[LIMIT][LIMIT] = {0,};
// int main(){

//     for(int tc = 0; tc < 10; tc++){
//         int sum[LIMIT*2+2] = {0,};
//         int count = 0;
        
//         //초기화
//         for(int i = 0; i<LIMIT; i++){
//             for(int j = 0; j<LIMIT; j++){
//                 cin>>arr[i][j];
//             }
            
//         }
        
//         //row sum
//         for(int i = 0; i<LIMIT; i++){
//             for(int j = 0; j<LIMIT; j++){
//                 sum[count] += arr[i][j];    
//             }
//             count++;
//         }

//         //col sum
//         for(int i = 0; i<LIMIT; i++){
//             for(int j = 0; j<LIMIT; j++){
//                 sum[count] += arr[j][i];    
//             }
//             count++;
//         }


//         // 대각선 sum        
//         for(int i = 0; i<LIMIT; i++){
//             sum[count] += arr[i][i];  
//             sum[count+1] += arr[i][99-i]; 
//         }



        
//         sort(sum, sum+(LIMIT*2+2));
        
//         // result = sum[count+1];
        
//         cout<<"#"<<tc+1<<" "<<sum[count+1]<<endl;
//     }
// }



#include <iostream>
#include <algorithm>
#define ARR 100
using namespace std;
int box[ARR][ARR] = {0,};
int main(){
    int tc;
    while(cin>>tc){
        int sum[ARR*2+2] = {0,};
        int cnt = 0;
        //input
        for(int i = 0; i<ARR; i++){
            for(int j = 0; j<ARR; j++){
                cin>>box[i][j];
                sum[cnt] += box[i][j];  //row sum
            }
            cnt++;
        }//input end
        
        for(int j = 0; j<ARR; j++){
            for(int i = 0; i<ARR; i++){
                sum[cnt] += box[i][j];  //col sum
            }
            cnt++;
        }
        
        for(int i = 0; i<ARR; i++){
            sum[cnt] += box[i][i];  //(i, i) sum
            sum[cnt+1] += box[i][99-i];    //(i, 100-i) sum
        }
        
        sort(sum, sum+(ARR*2+2));
        
        
        cout<<"#"<<tc<<" "<<sum[cnt+1]<<"\n";
    }
}


