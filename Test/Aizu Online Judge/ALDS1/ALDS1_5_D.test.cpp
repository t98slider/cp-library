#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include <bits/stdc++.h>
#include "../../../DataStructure/fenwick_tree.hpp"

template <class T> struct fenwick_tree {
    using U = T;

    public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

    private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n), ca;
    for(auto &&v : a) std::cin >> v;
    ca = a;
    sort(ca.begin(), ca.end());
    ca.erase(std::unique(ca.begin(), ca.end()), ca.end());
    int m = ca.size();
    fenwick_tree<int> fw(m);
    long long ans = 0;
    for(auto &&v : a){
        v = std::distance(ca.begin(), std::lower_bound(ca.begin(), ca.end(), v));
        ans += fw.sum(v + 1, m);
        fw.add(v, 1);
    }
    std::cout << ans << '\n';
}
