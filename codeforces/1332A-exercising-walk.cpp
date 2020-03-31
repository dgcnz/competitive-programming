#include <iostream>

using namespace std;

int l, r, d, u;     // moves
int x, y;           // starting positions
int x1, y1, x2, y2; // constrained area

inline bool contained(int val, int l1, int l2)
{
    return l1 <= val and val <= l2;
}

bool solve(void)
{
    int xf, yf;
    xf = x + (r - l);
    yf = y + (u - d);

    if (x1 == x2 and (l or r))
        return false;

    if (y1 == y2 and (d or u))
        return false;

    if (contained(xf, x1, x2) and contained(yf, y1, y2))
        return true;

    return false;
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> l >> r >> d >> u;
        cin >> x >> y;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
