// Last updated: 09/06/2026, 19:42:49
class Solution {
public:
    string trafficSignal(int nums) {
        if(nums==0)return "Green";
        else if(nums==30)return "Orange";
        else if(nums>30 && nums<=90)return "Red";
        else return "Invalid";
    }
};