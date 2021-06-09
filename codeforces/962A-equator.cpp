#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
int solve(vector<ll> a)
{
    int        n = a.size();
    vector<ll> pa(n);
    partial_sum(all(a), begin(pa));
    return distance(begin(pa), lower_bound(all(pa), (pa.back() + 1) / 2));
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    read(all(a));
    cout << solve(a) + 1 << endl;
    return 0;
}
