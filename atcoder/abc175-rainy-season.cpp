#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (auto c : s)
    {
        if (c == 'R')
            ++cnt;
        else
        {
            ans = max(cnt, ans);
            cnt = 0;
        }
    }
    ans = max(cnt, ans);

    cout << ans << endl;

    return 0;
}
