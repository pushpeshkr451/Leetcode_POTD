// Last updated: 09/06/2026, 19:42:44
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int sc=0,cnt=0;
        
        for(int i=0;i<events.size();i++){
            if(cnt==10)break;

            if(events[i]=="W")cnt++;
            else if(events[i]=="WD"||events[i]=="NB")sc++;
            else sc+=stoi(events[i]);
        }

        return {sc,cnt};
    }
};