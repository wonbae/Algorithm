#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C,N = 0;
    double sum = 0, avg = 0, count = 0;
    double result = 0;

    cin>>C;

    for(int i = 0; i < C; i++){
        cin>>N;

        int score[N];
        count = 0;
        sum = 0;

        for(int j = 0; j < N; j++){
            cin>>score[j];
        }
        for(int k = 0; k < N; k++){
            sum += score[k];
        }
        
        avg = (sum/N);

        for(int j = 0; j < N; j++){
            if(score[j] > avg){
                count++;
            }
        }
        result = double(count/N*100);
        cout<<fixed;
        cout.precision(3);
        cout<<result<<"%"<<"\n";
    }

    return 0;
}