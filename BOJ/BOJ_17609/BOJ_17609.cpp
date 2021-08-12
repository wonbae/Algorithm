#include<iostream>
#include<string.h>
using namespace std;

int lef = 0, rigt = 0;

bool is_Palindrome(string s){
    int l = s.length();
    for(int i = 0; i < l/2; i++){
        if(s[i] == s[l-1-i]) continue;
        else{
            lef = i;
            rigt = l-1-i;
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int T;
    cin>>T;
    string str;

    while(T--){
        cin>>str;
        int n = str.length();
        bool flag = true;
        bool sudo_flag = true;
        bool sudo_flag2 = true;

        if(!is_Palindrome(str)){
           flag = false; 
        }

        if(flag){   //palindrome 이라면
            cout<<0<<"\n";
        }else{
            int l = lef;
            int r = rigt;

            ++l;
            while(l < r){
                if(str[l++] == str[r--]) continue;
                else{
                    sudo_flag = false;
                    break;
                }
            }

            l = lef;
            r = rigt;

            --r;
            while(l < r){
                if(str[l++] == str[r--]) continue;
                else{
                    sudo_flag2 = false;
                    break;
                }
            }

            if(sudo_flag2 || sudo_flag) cout<<1<<"\n";
            else{
                cout<<2<<"\n";
            }
        }
    }
    return 0;
}

// #include<iostream>
// #include<string.h>
// using namespace std;

// int lef = 0, rigt = 0;

// bool is_Palindrome(string s){
//     int l = s.length();
//     for(int i = 0; i < l/2; i++){
//         if(s[i] == s[l-1-i]) continue;
//         else{
//             lef = i;
//             rigt = l-1-i;
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     ios_base::sync_with_stdio(false), cin.tie(NULL);
//     int T;
//     cin>>T;
//     string str;

//     while(T--){
//         cin>>str;
//         int n = str.length();
//         bool flag = true;
//         bool flag2 = true;

//         if(!is_Palindrome(str)){
//            flag = false; 
//         }

//         if(flag){   //palindrome 이라면
//             cout<<0<<"\n";
//         }else{
//             for(int i = 0; i < n; i++){
//                 string s = str.substr(0, i);
//                 string e = str.substr(i+1);
//                 string tmp = s + e;
//                 cout<<"s : "<<s<<", "<<"e : "<<e<<", "<<"tmp : "<<tmp<<"\n";
//                 if(is_Palindrome(tmp)){
//                     cout<<1<<"\n";
//                     flag2 = false;
//                     break;
//                 }
//             }
//             if(flag2){
//                 cout<<2<<"\n";
//             }
//         }
//     }
//     return 0;
// }