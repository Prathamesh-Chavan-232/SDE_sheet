#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " = " << x << "\n";
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cout << #x << " = "; \
    _print(x);           \
    cout << "\n";
#else
#define debcon(x)
#endif

// Function definitions
template <typename T>
void _print(T const &c) // print any STL container
{
    cout << "{";
    foreach (it, c)
        cout << *it << ", ";
    cout << "}";
}

// constants
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*  Approach -

*/
class Solution
{
public:
    void setZeros(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vpii pr;
        for (int i = 0; i < n; ++i)
        {
            bool flag = false;
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    debug(i);
                    debug(j);
                    pr.pb({i, j});
                }
            }
        }
        int sz = pr.size();

        for (int i = 0; i < sz; ++i)
        {
            int zero_i = pr[i].first, zero_j = pr[i].second;
            for (int row = 0; row < n; ++row)
            {
                matrix[row][zero_j] = 0;
            }
            for (int col = 0; col < m; ++col)
            {
                matrix[zero_i][col] = 0;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            debcon(matrix[i]);
        }
    }
};
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int n, m;
    cin >> n >> m;
    vvi matrix(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    setZeros(matrix);

#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}