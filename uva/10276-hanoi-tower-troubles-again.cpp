#include <cmath>
#include <iostream>

using namespace std;

const int NMAX = 50;

int  pegs[NMAX + 1];
int  top[NMAX + 1];
bool vis[NMAX + 1];

bool isps(int x)
{
    if (x < 0)
        return false;
    int root(round(sqrt(x)));
    return x == root * root;
}

void precompute(void)
{
    int x = 1;

    while (true)
    {
        int peg;
        for (peg = 1; peg <= NMAX; ++peg)
        {
            if (top[peg] == 0 or isps(x + top[peg]))
            {
                if (not vis[peg])
                    pegs[peg - 1] = x - 1;
                vis[peg] = true;
                top[peg] = x;
                break;
            }
        }
        if (peg > NMAX)
        {
            pegs[peg - 1] = x - 1;
            return;
        }
        ++x;
    }
}

int main(void)
{
    int t, n;
    precompute();

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << pegs[n] << endl;
    }

    return 0;
}
