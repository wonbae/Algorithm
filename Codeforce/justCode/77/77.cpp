#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int a[1000001];
    for(int i = 0; i < 1000000; i++){
        a[i] = i + 1;
    }

    for(int i = 0; i < 1000000; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}