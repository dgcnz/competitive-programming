#include <bits/stdc++.h>

using namespace std;

int main(void)
{

    int n, last, ai, ans = 1;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        if (i != 0 and ai != last)
            ans += 1;
        last = ai;
    }
    cout << ans << endl;

    return 0;
}
