#include <iostream>
using namespace std;

int sum = 1;
int Power(int n, int m)
{
    if(m == 0){
        return sum;
    }
    else{
        sum *= n;
    }
    return Power(n,m-1);
}

int main(){
    int T;
    int result;
    int N,M;

    for(int tc = 1; tc <= 10; tc++){
        cin>>T;

        cin>>N>>M;

        result = Power(N,M);




        cout<<"#"<<tc<<" "<<result<<endl;
        sum = 1;
    }


    return 0;
}