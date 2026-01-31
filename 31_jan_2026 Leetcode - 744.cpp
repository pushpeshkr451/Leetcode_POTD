class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int tar=target-'a';
        int n=letters.size();

        for(int i=0;i<n;i++){
            int val=letters[i]-'a';
            if(val>tar)return letters[i];
        }

        return letters[0];
    }
};
