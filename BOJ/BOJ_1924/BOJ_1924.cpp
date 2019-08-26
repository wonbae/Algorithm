#include <iostream>
using namespace std;

int main(){
    int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    string day[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int month, numday;

    cin>>month>>numday;

    for(int i = 1; i < month; i++){
        numday += a[i];
    }
    cout<<day[numday % 7];

    return 0;
}