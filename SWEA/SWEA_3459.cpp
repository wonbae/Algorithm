#include <iostream>
using namespace std;

int main() {
    int T;
    long int N;
    bool turn;

    cin>>T;
    for(int t_case=1;t_case<=T; t_case++){
        cin>>N;

        turn = true;//Alice, false(Bob)
        long int sub =1;

        while(N>0){
            N-=sub;
            if(turn){
                sub*=4;
            }
            turn = !turn;
        }
        if(turn){
            cout<<"#"<<t_case<<" "<<"Alice"<<endl;
        }else{
            cout<<"#"<<t_case<<" "<<"Bob"<<endl;
        }

    }
    return 0;
}