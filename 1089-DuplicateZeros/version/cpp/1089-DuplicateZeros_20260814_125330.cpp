// Last updated: 14/08/2026, 12:53:30
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i+1,0);
                arr.pop_back();
                i+=1;
            }
        }

    }
};