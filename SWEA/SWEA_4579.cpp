#include <iostream>

using namespace std;

int main() {
    int T;
    int Len;
    string str;
    bool flag;

    cin>>T;

    for(int test_case=1 ; test_case<=T ; ++test_case){
        str="";
        flag=true;

        cin>>str;

        Len = int(str.length());

        for(int k=0 ; k<Len/2 ;k++){
            if(str[k]=='*' || str[Len-k-1]=='*' ){
                break;
            }
            else if(str[k]==str[Len-k-1]){
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"#"<<test_case<<" "<<"Exist"<<endl;
        }
        else{
            cout<<"#"<<test_case<<" "<<"Not exist"<<endl;
        }
    }
    return 0;
}