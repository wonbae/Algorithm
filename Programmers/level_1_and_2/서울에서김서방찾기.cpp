#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    for(int i = 0; i < seoul.size(); i++){
        if(seoul.at(i) == "Kim"){
            answer += to_string(i) + "에 있다";
        }
    }
    return answer;
}
