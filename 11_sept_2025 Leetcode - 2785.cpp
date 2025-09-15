class Solution {
public:
    string sortVowels(string s) {
        string t="";
        vector<char>v;
        for(auto it:s){
            if(it=='A'||it=='E'||it=='I'||it=='O'||it=='U'||it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                v.push_back(it);
            }
        }
        sort(v.begin(),v.end());
        int i=0;
        for(auto it:s){
            if(it=='A'||it=='E'||it=='I'||it=='O'||it=='U'||it=='a'||it=='e'||it=='i'||it=='o'||it=='u'){
                t+=v[i++];
            }
            else {
                t+=it;
            }
        }
        return t;
    }
};
