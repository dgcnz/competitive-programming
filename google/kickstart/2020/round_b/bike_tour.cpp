#include <iostream>

using namespace std;

const int NMAX = 100 + 10;

int n, h[NMAX];

int main(void)
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        int cnt = 0;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> h[i];

        for (int i = 1; i < n - 1; ++i)
        {
            if (h[i - 1] < h[i] and h[i] > h[i + 1])
                ++cnt;
        }

        cout << "Case #" << tc << ": " << cnt << endl;
    }

    return 0;
}
