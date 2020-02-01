#include<iostream>
#include<queue>

using namespace std;

#define SIZE 10

vector<vector<bool> > board;
int N;
int answer = 0;

bool isPossible(){


    return true;
}
int NQueen(int pos){

    if(pos == N){
        answer++;
        return 0;
    }

    for(int i = 0; i < N; i++){
        if(isPossible()){

        }
    }
    



    return 0;
}

int main(){
    int T;
    cin>>T;

    for(int tc = 1; tc <= T; tc++){

        cin>>N;

        board.resize(N+1);

        NQueen(0);
        

        cout<<"#"<<tc<<" "<<answer<<"\n";
    }




    return 0;
}