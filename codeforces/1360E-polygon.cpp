#include <iostream>

using namespace std;

const int NMAX = 50;

int  n;
bool bomb[NMAX][NMAX];

bool valid(int i, int j)
{
    if (i == n - 1 or j == n - 1)
        return true;
    return bomb[i + 1][j] or bomb[i][j + 1];
}

bool board_possible(void)
{
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (bomb[i][j] and not valid(i, j))
                return false;
        }
    }
    return true;
}

int main(void)
{
    char c;
    int  t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> c;
                bomb[i][j] = c == '1';
            }
        }

        cout << (board_possible() ? "YES" : "NO") << endl;
    }

    return 0;
}
