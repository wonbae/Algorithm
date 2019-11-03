#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int index;

bool defsort(string a, string b){   //내가 정의한 정렬 방식
    if(a.at(index) != b.at(index)){ //비교하는 string의 index가 다르면 오름차순
        return a.at(index) < b.at(index);
    }else{
        return a < b;   //같으면 순수 문자열의 오름차순
    }
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    index = n;
    
    sort(strings.begin(), strings.end(), defsort);  //defsort 방식으로 정렬
    
    answer = strings;
    
    return answer;
}
