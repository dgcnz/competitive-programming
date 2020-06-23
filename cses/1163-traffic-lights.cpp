#include <bits/stdc++.h>

// source:
// https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/traffic-lights.cpp

using namespace std;
using si  = set<int>;
using msi = multiset<int>;

int main(void)
{
    int x, n, point, left, right;
    cin >> x >> n;

    si  points  = {0, x};
    msi lengths = {x};

    while (n--)
    {
        cin >> point;
        // find the position to insert the current point
        auto it = points.upper_bound(point);

        // [left, right] : the range in which the point is being inserted
        left  = *prev(it);
        right = *it;

        // remove that range from lengths
        lengths.erase(lengths.find(right - left));
        // add new lengths
        lengths.insert(point - left);
        lengths.insert(right - point);

        // insert the new point
        points.insert(it, point);

        // output the largest length
        cout << *lengths.rbegin() << " ";
    }
    return 0;
}
