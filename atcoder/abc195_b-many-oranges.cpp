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

int ceil(int a, int b) { return (a + b - 1) / b; }

bool in_range(int l, int x, int r) { return l <= x and x <= r; }

ii solve(int a, int b, int w)
{
    w *= 1000;
    int mn = ceil(w, b), mx = w / a;
    if (in_range(a, w / mn, b) and in_range(a, ceil(w, mx), b))
        return {mn, mx};
    return {-1, -1};
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int a, b, w;
    cin >> a >> b >> w;
    auto [mn, mx] = solve(a, b, w);
    if (mn == -1)
        cout << "UNSATISFIABLE" << endl;
    else
        cout << mn << " " << mx << endl;
    return 0;
}
