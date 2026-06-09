// Last updated: 09/06/2026, 19:45:19
class Solution {
public:
string convertToBase(long long num, int base) {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";

    if (num == 0) return "0";

    while (num > 0) {
        result = digits[num % base] + result;
        num /= base;
    }

    return result;
}

    string concatHex36(int n) {
        string a = convertToBase(n*n,16);
        string b = convertToBase(n*n*n,36);

        return a+b;
    }
};