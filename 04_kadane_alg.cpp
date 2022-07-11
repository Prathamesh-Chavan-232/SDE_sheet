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
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Container input tools
void inVec(vector<int> &v)
{
    string s;
    getline(cin, s);
    int num = 0, sign = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == ']')
            continue;
        if (s[i] == '-')
            sign = -1;
        else if (s[i] == ',' || s[i] == ' ')
            v.push_back(num), num = 0;
        else
        {
            num = num * 10 + (s[i] - '0');
            num *= sign;
            sign = 1;
        }
    }
    v.push_back(num);
}

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// STL vector / set (of any type) debugger
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1000000007;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vpii graph[N]; // For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    topic -
    Status -
    Date -
*/
/*  Approach -

        Brute force - Calculate the sum of every subarray & compute the maximum sum.

                | _ | _ | _ | _ | _ |  -> suppose this the array
                  0   1   2   3   4
        start -> i, j
                 iterate i through the array & for every i, iterate j through the array
                 and calculate sum += a[j] (so sum = a[0], a[0] + a[1], a[0] + a[1] + a[2]... and so on)

        Optimal - Kadane's algorithm
                1) Logic of the algorithm is the keep calculating the sum of the subarray which yeilds us a positive sum

                2) If a sum is positive even tho its subarray has -ve numbers
                   we keep calculating and comparing it with maxSum

                3) if the sum is negative. we change it to 0

                4) This way we will definitely go through the required subarray & set the maxSum which wont be affected when the sum decreases.

                5) This algorithm's main task is finding the starting point of the subarray because after that
                   we will definitely calculate maximum sum once even if we also iterate through extra elements later.

                6) Because this algorithm is focused only on finding positive sum. 
                   It doesn't work on array all negative arrays.
                
                7) If the array contains all non-positive numbers, then the solution is the largest negative number 
                   (or the empty subarray, if it is permitted)
*/

// Kadane's algorithm -> demands atleast 1 positive element in the array.
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        int maxSum = nums[0];
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            debug(sum, maxSum);
            if (sum < 0)
                sum = 0;
            debug(sum);
        }
        return maxSum;
    }
};

// Brute force approach - O(n^2) -> TLE on leetcode
class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                debug(sum);
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
void code()
{
    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        Solution s;
        vi arr;
        inVec(arr);
        int res = s.maxSubArray(arr); // store return value
        cout << res << "\n";
    }
}
int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    code();

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}