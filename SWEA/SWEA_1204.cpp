#include<iostream>
using namespace std;

int main(){
    int T;
    int num=0;
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>num;
        int max=0;
        int score=0;
        int index[101] = {0};
        for(int j = 0; j < 1000; j++){
            cin>>score;
            index[score]++;
        }

        for(int k = 0; k < 101; k++){
            if(max <= index[k]){
                max = index[k];
            }
        }
        
        cout<<"#"<<num<<" "<<max<<endl;
    }
    return 0;
}

#include <iostream>
 
using namespace std;
 
int main(void) {
 
    for(int t_case=0; t_case<10; t_case++) {
        int score[101] = {0}, temp, max=0, max_students=0;
 
        cin >> temp;
        
        for(int i=0; i<1000; i++) {
            cin >> temp;
            score[temp]++;
        }
 
        for(int i=0; i<101; i++) {
            if(score[i] >= max_students) {
                max = i;
                max_students = score[i];
            }
        }
 
        cout << "#" << t_case+1 << " " << max << "\n";
    }
 
    return 0;
}
