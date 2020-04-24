#include <bits/stdc++.h>

using namespace std;
using si = set<int>;

int main(void)
{
    int  xi;
    char c;
    si   chosen, winners;

    for (int row = 0; row < 6; ++row)
    {
        for (int col = 1; col <= 10; ++col)
        {
            cin >> c;
            if (c == 'x')
                chosen.insert(10 * row + col);
        }
    }

    for (int row = 0; row < 6; ++row)
    {
        cin >> xi;
        winners.insert(xi);
    }

    cout << (chosen == winners ? "S" : "N") << endl;

    return 0;
}
