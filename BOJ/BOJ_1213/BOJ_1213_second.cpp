








//++++++++++++++++++++++++++++++++++++++++++++++

// next_permutate로 깰끔하게 풀었다 생각했는데 시간초과..
// #include<bits/stdc++.h>
// using namespace std;

// bool checkPalindrome(string s){
//     for(int i = 0; i < s.length()/2; i++){
//         if(s[i] != s[s.length()-1-i]){
//             return false;
//         }
//     }
//     return true;
// }

// int main(){
//     ios_base::sync_with_stdio(0), cin.tie(NULL);
//     string str;
//     cin>>str;
//     vector<string> v;
//     sort(str.begin(), str.end());
//     do{
//         if(checkPalindrome(str)){
//             v.push_back(str);
//             break;
//         }
//     }while(next_permutation(str.begin(), str.end()));
//     if(v.empty())
//         cout<<"I'm Sorry Hansoo";
//     else{
//         // sort(v.begin(), v.end());
//         cout<<v[0];
//     }
//     return 0;
// }