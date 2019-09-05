#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    
    string token = "";
    string answer = "";
    vector<int> arr;
    int min_value;
    int max_value;
    
    // for (stringstream sts(s); (sts >> token);)
    // {                                          
    //     arr.push_back(stoi(token));
    // }
    
    stringstream sts(s);
    while(sts >> token){        //문자열을 토큰으로 잘라서 //int형으로 형변환 해준뒤에 벡터 arr에 넣었다.
        arr.push_back(stoi(token));
    }
    
    min_value = arr[0];
    max_value = arr[1];
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < min_value) min_value = arr[i];
        if(arr[i] > max_value) max_value = arr[i];
    }
    
    // cout<<min_value<<max_value;
    // answer = min_value + " " + max_value;    //이러면 안됨, int 형을 string으로 바꿔줘야함.
    answer = to_string(min_value) + " " + to_string(max_value);
    return answer;
}
