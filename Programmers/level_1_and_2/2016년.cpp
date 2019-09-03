#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    string day[] = {"FRI","SAT","SUN", "MON","TUE","WED","THU"};
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    for(int i = 0; i < a-1; i++){
        b += month[i];
        cout<<b<<endl;
    }
    
    answer = day[(b-1)%7];
    
    
    return answer;
}
