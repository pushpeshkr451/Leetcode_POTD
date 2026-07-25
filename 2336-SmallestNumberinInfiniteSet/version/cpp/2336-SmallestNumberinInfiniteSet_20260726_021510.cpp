// Last updated: 26/07/2026, 02:15:10
1class SmallestInfiniteSet {
2public:
3    int curr;
4    priority_queue<int, vector<int>, greater<int>> pq;
5    unordered_set<int> st;
6
7    SmallestInfiniteSet() {
8        curr = 1;
9    }
10
11    int popSmallest() {
12        if (!pq.empty()) {
13            int x = pq.top();
14            pq.pop();
15            st.erase(x);
16            return x;
17        }
18
19        return curr++;
20    }
21
22    void addBack(int num) {
23        if (num < curr && !st.count(num)) {
24            pq.push(num);
25            st.insert(num);
26        }
27    }
28};
29
30/**
31 * Your SmallestInfiniteSet object will be instantiated and called as such:
32 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
33 * int param_1 = obj->popSmallest();
34 * obj->addBack(num);
35 */