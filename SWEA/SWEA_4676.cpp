#include <iostream>
#include <string.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    int check[20];
    for(int tc = 1; tc <= T; tc++){

        int pos =0, a = 0, h = 0;
        string buf;

        memset(check, 0, sizeof(check));

        cin>>buf>>h;

        //
        for(int i=0; i < h; i++){
            cin>>pos;
            if(pos >= buf.length()){
                a++;
            }else{
                check[pos]++;
            }
        }

        //출력
        for(int i=0; i < buf.length(); i++){
            for(int k=0; k < check[i]; k++){
                cout<<"-";
            }
            cout<<buf[i];
        }

        for(int j = 0; j < a; j++){
            cout<<"-";
        }

    }
    return 0;
}


//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int t;
//
//
//int main(){
//    int check[20];
//    ios_base::sync_with_stdio(false);
//
//    cin>>t;
//
//    for(int tc = 1; tc <= t; tc++){
//        memset(check, 0, sizeof(check));
//
//        string buf;
//        int x, h, a = 0;
//
//        cin >> buf >> h;
//
//        //하이픈 위치 기억
//        for(int i = 0; i < h; i++){
//            cin>>x;
//            if(x >= buf.length()){
//                a++;
//            }
//            else{
//                check[x]++;
//                cout<<check[i]<<endl;
//            }
//        }
//
//        cout << "#" << tc << " ";
//        //문자열 및 하이픈 출력
//        for(int i = 0; i < buf.length(); i++){
//            for(int j = 0; j < check[i]; j++){
//                cout << "-";
//            }
//            cout << buf[i];
//        }
//        for(int i = 0; i < a; i++){
//            cout<<"-";
//        }
//        cout << "\n";
//    }
//    return 0;
//}