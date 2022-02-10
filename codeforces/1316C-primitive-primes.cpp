#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n), b(m);
    read(all(a));
    read(all(b));

    auto not_divisible_by_p = [&](int x) { return x % p != 0; };

    auto it_a = find_if(all(a), not_divisible_by_p);
    auto it_b = find_if(all(b), not_divisible_by_p);

    int i = distance(a.begin(), it_a);
    int j = distance(b.begin(), it_b);
    cout << i + j << endl;

    return 0;
}
