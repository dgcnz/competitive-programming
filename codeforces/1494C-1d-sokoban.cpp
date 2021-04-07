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

int solve_half(vi a, vi b)
{
    int ans = 0;
    sort(all(a)), sort(all(b));
    for (auto bit = begin(b); bit != end(b); bit++)
    {
        // if there's a box at bit;
        if (auto it = lower_bound(all(a), *bit); it != end(a) and *it == *bit)
            ans++;
        if (auto it = upper_bound(all(a), *bit); it != begin(a))
        {
            // count how many boxes <= bi
            int k = distance(begin(a), it);
            // count how many
            int cur = distance(upper_bound(all(b), *bit - k), bit) + 1;
            ans     = max(ans, cur);
        }
    }
    return ans;
}

int solve(vi a, vi b)
{
    vi A[2], B[2];
    for (auto ai : a)
        A[ai > 0].push_back(abs(ai));
    for (auto bi : b)
        B[bi > 0].push_back(abs(bi));

    return solve_half(A[0], B[0]) + solve_half(A[1], B[1]);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vi a(n), b(m);
        for (auto &ai : a)
            cin >> ai;
        for (auto &bi : b)
            cin >> bi;

        cout << solve(a, b) << endl;
    }
    return 0;
}
