// Last updated: 14/08/2026, 01:16:40
1/** 
2 * Forward declaration of guess API.
3 * @param  num   your guess
4 * @return 	     -1 if num is higher than the picked number
5 *			      1 if num is lower than the picked number
6 *               otherwise return 0
7 * int guess(int num);
8 */
9
10class Solution {
11public:
12    int guessNumber(int n) {
13        int lo=0,hi=n;
14
15        while(lo<=hi){
16            int mid=lo+(hi-lo)/2;
17            int val=guess(mid);
18
19            if(val==0)return mid;
20            else if(val==-1)hi=mid-1;
21            else lo=mid+1;
22        }
23        return -1;
24    }
25};