// Last updated: 23/11/2026, 10:31:59
1class ProductOfNumbers {
2public:
3    vector<int> product={1};
4    int n=1;
5    ProductOfNumbers(){
6        product.reserve(40000);
7    }
8    
9    void add(int num) {
10        if (num==0) {
11            product={1};
12            n=1;
13        }
14        else{
15            product.push_back(product[n++-1]*num);
16        }
17    }
18    
19    int getProduct(int k) {
20        if (n<=k) return 0;
21        return product[n-1]/product[n-k-1];
22    }
23};
24
25/**
26 * Your ProductOfNumbers object will be instantiated and called as such:
27 * ProductOfNumbers* obj = new ProductOfNumbers();
28 * obj->add(num);
29 * int param_2 = obj->getProduct(k);
30 */