#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int solve(vi f, int k)
{
    sort(all(f), greater<int>());

    int n = f.size(), i = 0, ans = 0;
    while (i < n)
    {
        ans += 2 * (f[i] - 1);
        i += k;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi f(n);
    for (auto &fi : f)
        cin >> fi;

    cout << solve(f, k) << endl;
    return 0;
}
