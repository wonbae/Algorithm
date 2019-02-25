#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str;
    int T;
    int Len;
    int result;
    cin>>T;
    
    for(int i=0;i<T;i++){
        str="";
        Len=0;
        result=0;
        
        cin>>str;
        Len = int(str.length());
        
        for(int k=0;k<Len/2;k++){
            if(str[k]==str[Len-k-1]){
                result = 1;
            }
            else{
                result = 0;
            }
        }
        cout<<"#"<<i+1<<" "<<result<<endl;
    }
    return 0;
}
