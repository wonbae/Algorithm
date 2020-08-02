#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;

int compute(int n){
    usleep(1000000);
    return n*1000*n+20;
}

int main(){
    //input : 1 1 3 4 3 6 3
    clock_t start = (int)clock();

    string str;
    int num[100] = {0,};
    int check[100] = {0,};

    getline(cin, str);

    int index = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] - 48 >= 0 && str[i] - 48 <= 9){
            num[index] = str[i] - 48;
            
            if(check[num[index]] != 0){
                if(index == 0){
                    cout<<check[num[index]];    
                }else{
                    cout<<" "<<check[num[index]];
                }
                
            }else{
                check[num[index]] = compute(num[index]);
                if(index == 0){
                    cout<<check[num[index]];
                }else{
                    cout<<" "<<check[num[index]];
                }
            }

            index++;
        }else continue;
    }

    cout<<"\n Time : "<<(float)(clock() - start)<<", "<<(float)(clock() - start) / (CLOCKS_PER_SEC)<<"\n";

    return 0;
}