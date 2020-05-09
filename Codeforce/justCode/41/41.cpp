#include<iostream>
using namespace std;

int main(){
    int n, tmp, b = 1, i, cnt = 0;
    cin>>n;

    tmp = n;
    tmp--;
    while(tmp > 0){
        b++;
        tmp = tmp - b;
        if(tmp % b == 0){
            for(i = 1; i < b; i++){
                cout<<(tmp/b) + i<<" + ";
            }
            cout<<(tmp/b) + i<<" = "<<n<<"\n";
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}