#include <iostream>
using namespace std;

int main(){
    int T, input;
    cin>>T;
    
    for(int tc = 1; tc <= T; ++tc){
        cin>>input;
        int res = 0;
        int tmp = 0;
        bool check[10] = {false};


        while(1){
            tmp = input % 10;
            check[tmp] = true;

            if(input / 10 == 0){
                break;
            }
            else{
                input = input / 10;

            }
        }

        for(int i = 0; i < 10; ++i){
            if(check[i] == true){
                res++;
            }
        }
        

        cout<<"#"<<tc<<" "<<res<<endl;
    }
    return 0;
}