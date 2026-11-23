// Last updated: 23/11/2026, 10:30:48
1class ProductOfNumbers {
2public:
3    vector<int> pro;
4    ProductOfNumbers() { pro.clear(); }
5    // O(1)
6    void add(int num) {
7        if (num == 0)
8            pro.clear();
9        else {
10            if (pro.empty()) {
11                pro.push_back(num);
12            } else {
13                pro.push_back(pro.back() * num);
14            }
15        }
16    }
17
18    int getProduct(int k) {
19        int n = pro.size();
20        // k can be greater than n only if we encountered a zero before
21        if (k > n)
22            return 0;
23        // return product of all numbers in the current array
24        if (k == n)
25            return pro.back();
26        // product of last k numbers = product of n numbers/product of n-k-1
27        // numbers
28        return pro.back() / pro[n - k - 1];
29    }
30};
31
32/**
33 * Your ProductOfNumbers object will be instantiated and called as such:
34 * ProductOfNumbers* obj = new ProductOfNumbers();
35 * obj->add(num);
36 * int param_2 = obj->getProduct(k);
37 */