#include <iostream>
using namespace std;

int main(){
    int N, max = -1000000, min = 1000000;
    int input;

    cin>>N;

    for(int i = 0; i < N; i++){
        
        cin>>input;

        max = (input > max) ? input : max;
        min = (input < min) ? input : min;
        // if(input < min){
        //     min = input;
        // }else if(input > max){
        //     max = input;
        // }
    }
    cout<<min<<" "<<max<<endl;

    return 0;
}