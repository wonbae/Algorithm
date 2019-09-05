#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> log(record.size(),vector<string>(3));
	map<string,string> user;
    
    for(int i = 0; i < record.size(); i++){
        stringstream sts(record[i]);
        sts>>log[i][0]; //command
        sts>>log[i][1]; //id
        sts>>log[i][2]; //nickname
        if(log[i][0] == "Enter" || log[i][0] == "Change"){
            user[log[i][1]] = log[i][2];
        }
    }
    for(int i = 0; i < log.size(); i++){
        if(log[i][0] == "Enter"){
            answer.push_back(user[log[i][1]] + "님이 들어왔습니다.");
        }
        else if(log[i][0] == "Leave"){
            answer.push_back(user[log[i][1]] + "님이 나갔습니다.");
        }
    }
    
    
    return answer;
}
