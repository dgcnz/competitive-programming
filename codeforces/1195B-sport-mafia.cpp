#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n, k;
    cin >> n >> k;

    auto f = [=](ll m) { return (m * (m + 1)) / 2 - (n - m); };
    auto p = [=](ll m) { return f(m) >= k; };

    ll m = *binary_search01(itll(1), itll(n), p);
    cout << n - m << endl;

    return 0;
}
