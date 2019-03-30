Last login: Fri Mar 29 02:05:18 on ttys001
~ master ✗ 63d ✖ △ ◒ ➜
~ master ✗ 63d ✖ △ ◒ ➜ cd git_algorithm/Algorithm
Algorithm master 19h4m ➜ ls
BOJ        LeetCode   Programers README.md  SWEA
Algorithm master 19h4m ➜ cd LeetCode
class Solution {
LeetCode master 19h4m ➜ ls
Easy   Medium
LeetCode master 19h4m ➜ cd Easy
Easy master 19h4m ➜ ls
104_Maximum_Depth_of_Binary_Tree.cpp
136_Single_Number.cpp
461_Hamming_distance.cpp
617_Merge_Two_Binary_Trees.cpp
657_Robot_Return_to_Origin.cpp
728_Self_Dividing_Numbers.cpp
771_Jewels_and_Stones.cpp
804_Unique_Morse_Code_Words.cpp
832_Flipping.cpp
905_Sort_Array_By_Parity.cpp
942_DI_String_Match.cpp
961_N-Repeated_Element_in_Size_2N_Array.cpp
977_Squares_of_a_Sorted_Array.cpp
977_Squares_of_a_Sorted_Array.py
Top_100_Liked
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        int sum = 0;


        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};
~
~
~
~
~
~
~
-- INSERT --
