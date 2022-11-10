#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int N, lightout, pos = 0, time = 0, zero = -1, ans = 0;
    cin>>N;
    vector<int> v(N);

    for(int i = 0; i < N; i++){
        cin>>v[i];
    }
    cin>>lightout;
    
    while(time <= lightout){
        if(time == lightout){
            // cout<<"answer is : "<<pos<<"\n";
            if(v[pos - 1] != 0){
                ans = pos;
            }else{
                ans = -1;
            }
            break;
        }

        // pos = zero + 1;
        if(pos >= N){
            pos = zero + 1;
        }
        
        if(v[pos] != 0){
            v[pos] -= 1;
            if(v[pos] == 0){
                zero = pos;
                pos++;
            }else{
                pos++;
            }
            
        }else{
            zero = pos;
            pos++;
        }

        time++;

        // cout<<"\n ++++++ running ++++++\n";
        // for(int i = 0; i < N; i++){
        //     cout<<v[i]<<" ";
        // }cout<<endl;
    }
    

    cout<<ans<<"\n";
    return 0;
}