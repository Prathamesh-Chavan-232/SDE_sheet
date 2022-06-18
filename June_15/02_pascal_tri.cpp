#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// constants
const int mod = (int)1e7;
const int N = 3e5, M = N;

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
    tr(it, c) cout << *it << ", ";
    cout << "}";
}

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

vector<vector<long long int>> printPascal(int n)
{
    vvl pascal(n);
    // Write your code here.
    pascal[0].pb(1);
    pascal[1].pb(1);
    pascal[1].pb(1);
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j <= pascal[i - 1].size(); ++j)
        {
            if (j - 1 < 0)
            {
                ll temp = 0 + pascal[i - 1][j];
                pascal[i].pb(temp);
            }
            else if (j == pascal[i - 1].size())
            {
                ll temp = 0 + pascal[i - 1][j - 1];
                pascal[i].pb(temp);
            }
            else
            {
                ll temp = pascal[i - 1][j - 1] + pascal[i - 1][j];
                pascal[i].pb(temp);
            }
        }
    }
    return pascal;
}

void solve()
{
    int n;
    cin >> n;
    vvl res = printPascal(n);
    for (vl row : res)
    {
        for (int el : row)
        {
            cout << el << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}