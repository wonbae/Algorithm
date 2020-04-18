#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int n, int r, int c) {
   long long answer = 0;

   long long current_r = 1;
   long long current_c = 1;

   bool flag = false;
   for (int i = 1; i <= n * n; i++)
   {
      //cout << "(" << current_r << "," << current_c << ") -> " << i << "\n";
      if (current_r == r && current_c == c)
      {
         answer = i;
         break;
      }

      if (current_r == 1 && current_c == 1)
      {
         current_c++;
         flag = false;
      }
      else if (current_r == 1 || current_c == 1)
      {
         if (current_r == 1 && (current_c % 2 == 1))
         {
            if (current_c < n)
            {
               current_c++;
               flag = false;
            }
            else
            {
               current_r++;
               flag = false;
            }
         }
         else if (current_c == 1 && (current_r % 2 == 0))
         {
            if (current_r < n)
            {
               current_r++;
               flag = true;
            }
            else
            {
               current_c++;
               flag = true;
            }
         }
         else
         {
            if (flag == false)
            {
               if(current_r<n)
               {
                  current_c--;
                  current_r++;
               }
               else
               {
                  current_c++;
                  flag = true;
               }

            }
            else
            {
               if (current_c < n)
               {
                  current_c++;
                  current_r--;
               }
               else
               {
                  current_r++;
                  flag = false;
               }
            }
         }
      }
      else
      {
         if (flag == false)
         {
            if (current_r < n)
            {
               current_c--;
               current_r++;
            }
            else
            {
               current_c++;
               flag = true;
            }

         }
         else
         {
            if (current_c < n)
            {
               current_c++;
               current_r--;
            }
            else
            {
               current_r++;
               flag = false;
            }
         }
      }
   }

   return answer;
}

int main()
{
   cout << solution(5, 3, 2) << "\n";
   cout << solution(6, 5, 4) << "\n";
   cout << solution(10000000, 9999999, 9999999) << "\n";
   
}

