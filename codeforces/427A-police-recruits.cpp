#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, police = 0, ans = 0, event;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> event;
        if (event > 0)
            police += event;
        else if (event == -1 and police > 0)
            --police;
        else
            ++ans;
    }

    cout << ans << endl;

    return 0;
}
