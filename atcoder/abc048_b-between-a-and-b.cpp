#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    ll a, b, x, ap, bp;
    cin >> a >> b >> x;

    ap = (a + x - 1) / x;
    bp = b / x;

    cout << bp - ap + 1 << endl;

    return 0;
}
