#include<iostream>
#include<string>
#include<vector>

using namespace std;

int max(int a, int b){
    return a > b? a : b;
}

int solution(vector<int> estimates, int k){
    int answer = 0;
    int sum = 0;

    for(int i = 0; i < estimates.size() - k + 1; i++){
        sum = 0;
        for(int j = i; j < i + k; j++){
            sum += estimates[j];
        }
        answer = max(sum, answer);
    }


    return answer;
}

int main(){
    vector<int> v;
    vector<int> v2;
    v.push_back(5);
    v.push_back(1);
    v.push_back(9);
    v.push_back(8);
    v.push_back(10);
    v.push_back(5);

    v2.push_back(10);
    v2.push_back(1);
    v2.push_back(10);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(4);
    v2.push_back(3);
    v2.push_back(10);

    cout<<solution(v, 3)<<"\n";
    cout<<solution(v2, 6)<<"\n";
    return 0;
}