// Last updated: 23/11/2026, 10:34:22
1class ProductOfNumbers {
2public:
3vector<int>v;
4    ProductOfNumbers() {
5        
6    }
7    
8    void add(int num) {
9        v.push_back(num);
10
11    }
12    
13    int getProduct(int k) {
14        int ans=1;
15        int n=v.size();
16        while(k--){
17            ans*=v[n-1];
18            n--;
19        }
20        return ans;
21    }
22};
23
24/**
25 * Your ProductOfNumbers object will be instantiated and called as such:
26 * ProductOfNumbers* obj = new ProductOfNumbers();
27 * obj->add(num);
28 * int param_2 = obj->getProduct(k);
29 */