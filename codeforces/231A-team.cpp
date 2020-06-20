#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int  n, cnt, ans = 0;
    bool sure;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < 3; ++j)
        {
            cin >> sure;
            cnt += sure;
        }
        if (cnt >= 2)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
