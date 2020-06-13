#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b)
{
    int ans = 0;

    // 1. make equal
    if (a < b)
        swap(a, b);

    int diff = a - b; // diff >= 0
    if (diff > b)
        return b;

    a -= 2 * diff;
    b -= diff;
    ans += diff;

    if (a == 0)
        return ans;

    // 2. compute remainder

    int rem = a % 3;
    int q   = a / 3;

    ans += 2 * q + (rem / 2);

    return ans;
}

int main(void)
{
    int t, a, b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
