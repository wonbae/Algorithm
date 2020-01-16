#include<bits/stdc++.h>
using namespace std;

//내림차순 정렬

bool cmp(char a, char b)
{

    if (a > b){
        return true;
    }

    return false;

}

 
int main(void)

{

        string N;

        cin >> N;

        long long sum = 0;

        bool zero = false;

        for (int i = 0; i < N.size(); i++)

        {

                 sum += (N[i] - '0');

                 if (!(N[i]-'0'))

                         zero = true;

        }
        //합이 3의 배수가 아니거나 0이 없다면

        if (sum % 3 || !zero)

                 cout << -1 << "\n";

        else

        {

                 sort(N.begin(), N.end(), cmp);

                 cout << N << "\n";

        }

        return 0;

}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int num;
//     int result = -1;

//     cin>>num;

//     vector<int> v; 
    
//     while(true){
//         if(num == 0) break;
//         v.push_back(num % 10);
//         num /= 10;
//     }

//     int m = 0;
//     int tmp = 0;

//     do{
//         tmp = 0;
// 		for(int i = 0; i < v.size(); i++){
// 			tmp += v[i] * pow(10, v.size() - 1 - i);
//             // cout<<v[i]<<"\n";
            
// 		}
//         // cout<<tmp<<"\n";
// 		// cout<<"\n";

//         if(tmp >= num && tmp % 30 == 0){
//             result = 0;
//             tmp = max(tmp, m);
//         }else{
//             result = -1;
//         }

// 	}while(next_permutation(v.begin(),v.end()));

//     if(result < 0){
//         cout<<result<<"\n";
//     }else{
//         cout<<tmp<<"\n";
//     }
//     return 0;
// }