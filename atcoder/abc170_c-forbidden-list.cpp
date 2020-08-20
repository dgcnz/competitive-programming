#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, n, y;
    cin >> x >> n;

    set<int> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> y;
        p.insert(y);
    }

    for (int i = 0; i < x + 1; ++i)
    {
        for (auto dir : {-1, +1})
        {
            y = x + dir * i;
            if (p.find(y) == p.end())
            {
                cout << y << endl;
                return 0;
            }
        }
    }

    return 0;
}
