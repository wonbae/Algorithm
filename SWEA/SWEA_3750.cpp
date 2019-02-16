//#include <iostream>
//using namespace std;
//
//int DigitSum(int num){
//    int sum=0;
//
//    while(num>0) {
//        sum += num % 10;
//        num = num / 10;
////        cout<<"sum: "<<sum<<" num : "<<num<<endl;
//    }
//    return sum;
//}
//int Count(int num){
//    int count=0;
//    while(num>0){
//        num/=10;
//        count++;
//    }
////    cout<<"count :"<<count<<endl;
//
//    return count;
//}
//int main(int argc, char** argv) {
//    int num;
//    int result;
//    int T;
//    cin>>T;
//    for(int test_case=1;test_case<=T;++test_case) {
//        cin >> num;
//
//        result = DigitSum(num);
//        if(Count(result)!=1){
//            cout<<"#"<<test_case<<" "<<DigitSum(result)<<endl;
//        }else{
//            cout<<"#"<<test_case<<" "<<result<<endl;
//        }
//    }
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
////int DigitSum(int num){
////    int sum=0;
////
////    while(num>0) {
////        sum += num % 10;
////        num = num / 10;
//////        cout<<"sum: "<<sum<<" num : "<<num<<endl;
////    }
////    return sum;
////}
//int Count(int num){
//    int count=0;
//    while(num>0){
//        num/=10;
//        count++;
//    }
////    cout<<"count :"<<count<<endl;
//
//    return count;
//}
//int main(int argc, char** argv) {
//    double num;
//    int result;
//    int T;
//
//    cin>>T;
//    for(int test_case=1;test_case<=T;++test_case) {
//        cin >> num;
//        int sum=0;
//        int num2 = int(num);
//
//        while(num2>10) {
//            sum += num2 % 10;
//            num2 = num2 / 10;
////            cout<<"sum: "<<sum<<" num : "<<num2<<endl;
//        }
//
//        result = sum;
//
//        if(Count(result)!=1){
//            while(result>0) {
//                sum=0;
//                sum += result % 10;
//                result = result / 10;
//            }
//            cout<<"#"<<test_case<<" "<<sum<<endl;
//        }else{
//            cout<<"#"<<test_case<<" "<<result<<endl;
//        }
//    }
//
//    return 0;
//}


#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int T;
    int result=0;
    cin>>T;

    for(int t=1;t<=T;t++){
        long long num;
        scanf("%lld", &num);

        if(num>10) {
            while (num >= 10) {
                result = 0;
                while (num != 0) {
                    result += num % 10;
                    num /= 10;
                }
                num = result;
            }
        }
        else{
            result=num;
        }
//        cout<<"#"<<t<<" "<<num<<endl;
        printf("#%d %d\n",t,result);
    }
    return 0;
}