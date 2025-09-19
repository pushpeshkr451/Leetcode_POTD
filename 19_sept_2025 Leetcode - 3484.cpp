class Spreadsheet {
public:
 unordered_map<string, int> mp; 
    bool is(const string& s) {
        for (char ch : s) {
            if (!isdigit(ch)) return false;
        }
        return true;
    }
    int get( string& s) {
        if (is(s)) {
            return stoi(s); 
        }
        return mp.count(s) ? mp[s] : 0; 
    }
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
         formula = formula.substr(1);
         int p = formula.find('+');
        string a = formula.substr(0, p);
        string b = formula.substr(p + 1);
        return get(a)+get(b);

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
