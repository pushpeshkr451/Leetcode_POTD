// Last updated: 09/06/2026, 19:45:18
class Solution {
public:
    vector<bool> sieve(int maxN) {
        vector<bool> isPrime(maxN + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxN; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int maxFreq = 0;

        for (int num : nums) {
            freqMap[num]++;
            maxFreq = max(maxFreq, freqMap[num]);
        }

        // Build sieve up to maxFreq
        vector<bool> isPrime = sieve(maxFreq);

        for (auto& [num, freq] : freqMap) {
            if (isPrime[freq]) {
                return true;
            }
        }

        return false;
    }
};
