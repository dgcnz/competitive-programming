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

bool in_range(int l, int x, int r) { return l <= x and x <= r; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int v, t, s, d;
    cin >> v >> t >> s >> d;

    if (in_range(v * t, d, v * s))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
