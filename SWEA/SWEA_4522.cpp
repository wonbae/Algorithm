#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    int Len;
    string str;
    bool flag;

    cin>>T;

    for(int i=0 ; i<T ; i++){
        str="";
        flag=true;

        cin>>str;

        Len = int(str.length());

        for(int k=0 ; k<Len/2 ;k++){
            if(str[k]=='?' || str[Len-k-1]=='?' || str[k]==str[Len-k-1]){
                continue;
            }else{
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"#"<<i+1<<" "<<"Exist"<<endl;
        }
        else{
            cout<<"#"<<i+1<<" "<<"Not exist"<<endl;
        }
    }
    return 0;
}