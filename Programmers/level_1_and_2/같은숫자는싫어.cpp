#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int tmp = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == arr[i+1]){
            tmp = arr[i+1];
        }else if(arr[i] != arr[i+1]){
            tmp = arr[i];
            answer.push_back(tmp);
            tmp = arr[i+1];
        }else{
            tmp = arr[i+1];
        }
    }
    
    //방법 2
    // vector<int> answer;
    // int arr1[10]={0,};
    // for(int i =0; i<arr.size();i++) {
    //     if(answer.empty()) answer.push_back(arr[i]);
    //     else{
    //         if(answer.back()!=arr[i]) answer.push_back(arr[i]);
    //     }
    // }
    
    //방법 3
//     arr.erase(unique(arr.begin(), arr.end()),arr.end());

//     vector<int> answer = arr;
//     return answer;
    
    return answer;
}
