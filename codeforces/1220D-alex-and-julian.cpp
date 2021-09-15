#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/math/utils>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vector<ll> solve(vector<ll> b)
{
    int const BMAX = 60;

    vi cnt(BMAX);

    for (auto bi : b)
        cnt[max_power_two_exp(bi)]++;
    int e = max_element(all(cnt)) - cnt.begin();

    vector<ll> ans;
    for (auto bi : b)
        if (max_power_two_exp(bi) != e)
            ans.push_back(bi);

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> b(n);
    read(all(b));

    auto ans = solve(b);
    cout << ans.size() << endl;
    write(all(ans), " "), cout << endl;
    return 0;
}
