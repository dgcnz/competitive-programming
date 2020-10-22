// https://github.com/papachristoumarios/IEEEXtreme11.0/blob/master/Counter/sol.py
#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()
#define iter(c, i) (c).begin() + i

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int n;
vi  a, p;

// IDEA:
// Given a subarray a[l...r], we may divide it in two parts:
// A prefix P that is not altered, and a complementary suffix S that will be.
//      initially subject to  a[l...r] = (P S)
//      then a'[l...r] = (P S') where S' is the altered version of S
//
// One may intuitively note that we want P to be as wide as possible since the
// later we make a change, the more elements the resulting array a' and the
// original a will have in common, thus making a' minimally lexicographically
// greater than a.
//
// Now, when does it become impossible to find a permutation of an array such
// that it is lexicographically greater? When is decreasingly sorted.
//
// So now we now that S must be a decreasing subarray preceded by an element
// that breaks that order.
//
// S = [s0] + [s1...sk], such that s0 < s1 and s1 > s2 > s3 > ... > sk
//
// Now, how can we find an S-permutation, S', such that S' is minimally greater
// than S?
//
// We note that s0' must be greater than s0, and the optimally way to choose s0'
// is such that it is also minimally greater than s0.
//
// We also note, that what follows to s0' will need to be a sorted array
// (increasingly) in order to minimize it's lexicographical distance to S.
//
// So, once we find s0', we know that's the exact same spot where s0 should be.
// (this might be a little hard to grasp, so reflect on this point)
//
// We note than in the case where |S| is odd, choosing any s0' will result in a
// permutation S' that differs completely from S, so the answer is |S|.
//
// However, in the case where |S| is even, we must deal with a special case.
// That is, the middle element of the decreasing array in S will remain at its
// position when sorted in increasing order unless it is s0'.
// So, if s0' is in the middle, the answer is |S| - 1, otherwise it's |S|.

int cost(int l, int r)
{
    if (p[r] < l) // A[l...r] is decreasing (no changes can be made)
        return 0;

    // a[p[r] + 1...r] is a decreasing array, and a[p[r]] < a[p[r] + 1]
    int len = r - p[r] + 1;
    // Smallest element bigger than a[p[r]]
    auto it = prev(upper_bound(
        iter(a, p[r] + 1), iter(a, r + 1), a[p[r]], greater<int>()));
    int  i = distance(a.begin(), it), mid = p[r] + len / 2;
    if (len % 2 == 0 and i != mid)
        return len - 1;
    else
        return len;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n;

    a.resize(n), p.resize(n);
    read_n(begin(a), n);

    // p[i]: holds the index previous to the position in which the last
    // decreasing sequence starts for a given index i

    int prv = -1;
    p[0]    = prv;
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] < a[i])
            prv = i - 1;
        p[i] = prv;
    }

    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r, l--, r--;
        cout << cost(l, r) << endl;
    }

    return 0;
}
