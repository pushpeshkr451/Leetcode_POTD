// Last updated: 14/08/2026, 12:46:37
1class Solution {
2public:
3    vector<int> sortArrayByParity(vector<int>& nums) {
4        int i =0;
5        int j = nums.size()-1;
6
7        while(i<=j){
8            if(nums[i]%2 ==0 ){
9                i++ ;
10            }
11            else if(nums[j]%2 !=0){
12                j-- ;
13            }
14            else{
15                swap(nums[i],nums[j]);
16                i++;
17                j--;
18            }
19           
20        }
21        
22        return nums ;
23    }
24};