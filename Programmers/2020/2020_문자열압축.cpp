#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int count = 1;
    string tmp = "";
    vector<string> v;
    
    for(int n = 1; n < s.length()/2; n++){
        for(int i = 0; i < s.length() - n; i++){
            v.push_back(s.substr(i,n));
            cout<<v[i]<<",";  
        }cout<<endl<<"============="<<endl;
        
    }
    
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == s[i + 1]){
            count++;
        }else{
            if(count == 1){
                tmp += s[i];
            }else{
                tmp += to_string(count) + s[i];    
                count = 1;
            }
        }
    }
    cout<<tmp<<", "<<tmp.length()<<endl;
    
    return 0;
}
