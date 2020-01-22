// 어렵노.. 다시보자... 빠끄..

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str = "", result = "";
    bool odd = false, even = false;  //odd - 홀수, even - 짝수
    int alphabet[26] = {0,};

    cin>>str;

    int len = str.length();

    if(len % 2 == 0){
        even = true;
    }else{
        odd = true;
    }

    for(int i = 0; i < len; i++){
        alphabet[str[i] - 'A']++;
    }

    int oddcount = 0;
    int mid = -1;

    for(int i = 0; i < 26; i++){
        if(even){
            if(alphabet[i] % 2 == 0){
                continue;
            }else{
                oddcount++;
                break;
            }
        }
        else if(odd){
            if(alphabet[i] % 2 == 1){
                oddcount++;
                mid = i;
            }
        }
        
    }

    // 길이가 홀수인데 홀수개인 알파벳이 없을 때, 혹은 더 많거나, 길이가 짝수인데 홀수개의 알파벳이 있을 때 중지
    if((odd && oddcount != 1) || (even && oddcount)){   
        cout<<"I'm Sorry Hansoo"<<"\n";
        return 0;
    }

    //앞에 반
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < alphabet[i] / 2; j++){
            result += (char)i + 'A';
        }
    }

    //길이가 홀수면 가운데꺼
    if(mid > -1) result += (char)mid + 'A';

    //뒤에 반
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < alphabet[i] / 2; j++){
            result += (char)i + 'A';
        }
    }


    cout<<result<<"\n";

    return 0;
}





// <처음 시도방법..>
// 배열 index로 순열을 만들려고 했는데... 최대 크기가 50이다 그러면 50! 펙토리얼... ㅎㄷㄷ 안될짓이다

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     string str = "";
//     string result = "";
//     vector<int> v;
//     bool flag = true;
    

//     cin>>str;

//     int len = str.length();

//     for(int i = 0; i < len; i++){
//         v.push_back(i);
//     }

//     do{
//         for(int i = 0; i < v.size() / 2; i++){
//             if(str[v[i]] == str[v[len - 1 - i]]){
//                 flag = true;
//                 continue;
//             }else{
//                 flag = false;
//                 break;
//             }
//         }

//         if(flag){
//             for(int i = 0; i < v.size(); i++){
//                 result += str[v[i]];
//             }
//             break;
//         }
        

//     }while(next_permutation(v.begin(), v.end()));

//     if(!flag){
//         cout<<"I'm Sorry Hansoo"<<"\n";
//     }

//     cout<<result<<"\n";

//     return 0;
// }