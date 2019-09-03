#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int len = completion.size();
    for(int i = 0; i < len; i++){
        if(participant.at(i) != completion.at(i)){
            answer = participant.at(i);
            return participant.at(i);
        }
    }
    // 효율성 0점, 완전탐색 하지마셈.
    // for(int i = 0; i < participant.size(); i++){
    //     bool flag = true;
    //     for(int j = 0; j < completion.size(); j++){
    //             if(completion[j] == participant[i]){
    //                 completion[j] = "";
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //     if(flag){
    //         answer += participant[i];
    //     }
    // }
    
    answer = participant[participant.size()-1];
    return answer;
}
