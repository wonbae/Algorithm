#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string word = "I love you";
    string word2;
    int len = word.length();
    int num,index;

    for(int i = 0; i < len; i++){
        if('a' <= word[i] && word[i] <= 'z'){
            num = word[i];
            // cout<<word[i]<<endl;

            
                index = num - 'a';
                // cout<<"index : "<<index<<endl;
                
                word2[i] = (25 - index) + 'a';
            
            
        }
        else if('A' <= word[i] && word[i] <= 'Z'){
            num = word[i];
            // cout<<word[i]<<endl;

            
                index = num - 'A';
                // cout<<"index : "<<index<<endl;
                
                word2[i] = (25 - index) + 'A';
            

        }
        else{
            // cout<<"sp"<<endl;
            word2[i] = 32;
        }
    }
    
    for(int i = 0; i < len; i++){
        cout<<word2[i]<<endl;
    }

}