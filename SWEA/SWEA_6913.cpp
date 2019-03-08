#include <iostream>
using namespace std;
int main(){
    int T,N=0,M=0,count[50]={0,},Max=0,same=0;
    int arr[100][100] = {0,};
    cin>>T;
    for(int tc = 1; tc <= T; tc++)
    {
        cin>>N>>M;
        same = 0;
        Max = 0;
        memset(count,0,sizeof(count));
    
        //값 초기화
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>arr[i][j];
            }
        }

        //
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(arr[i][j]){
                    count[i]++;
                }
            }
        }

        Max = count[0];
        for(int i = 1; i < N; i++){
            if(count[i] > Max){
                Max = count[i];
            }
        }

        for(int i = 0; i < N; i++){
            if(count[i] == Max){
                same++;
            }
        }

        cout<<"#"<<tc<<" "<<same<<" "<<Max<<endl;
    }



    return 0;
}