#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, h, ai, ans = 0;
    cin >> n >> h;

    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        ans += 1 + (ai > h);
    }
    cout << ans;
    return 0;
}
