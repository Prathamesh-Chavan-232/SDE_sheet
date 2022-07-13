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
const int mod = 1'000'000'007;
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

        Approach 3 -
            1) Initially take the gap as (m+n)/2;
            2) Take as a pt1 = 0 and pt2 = gap.
            3) Run a loop while pt2 < m + n and whenever nums1[pt1] > nums1[pt2], swap those.
            4) After completion of the loop reduce the gap as gap = ceil(gap/2).
            5) Repeat the process until gap is 1,
               if gap is 1 dont do gap = ceil(gap/2) (it will always be 1) Instead exit the loop.

*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = m; i < n + m; i++)
        {
            nums1[i] = nums2[i - m];
        }
        debcon(nums1);
        int gap = ceil((m + n) / 2.0);
        int i = 0, j = i + gap;
        while (gap)
        {
            debug(gap);
            i = 0;
            j = i + gap;
            while (j < (m + n))
            {
                if (nums1[i] > nums1[j])
                {
                    debug(i, j, nums1[i], nums1[j]);
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }
            if (gap == 1)
                gap = 0;
            else
                gap = ceil(gap / 2.0);
        }
    }
};

class Solution1
{
public:
    void merge(vi &nums1, int m, vi &nums2, int n)
    {
        for (int i = m; i < n + m; i++)
        {
            nums1[i] = nums2[i - m];
        }
        debcon(nums1);
        int l = 0, mid = m, h = m + n;
        vi temp(h + 1);
        int i = 0, j = mid + 1, k = 0;
        while (i <= mid && j <= h) // Mergeing the elements in stored order
        {
            if (nums1[i] < nums1[j])
            {
                temp[k] = nums1[i++];
            }
            else
            {
                temp[k] = nums1[j++];
            }
            k++;
        }
        while (i <= mid) // if elements are remaining from left subarray
        {
            temp[k++] = nums1[i++];
        }
        while (j <= h) // if elements are remaining from right subarray
        {
            temp[k++] = nums1[j++];
        }
        for (int i = 0; i < (h + 1); i++) // storing sorted elements in orignal array again
        {
            nums1[i] = temp[i];
        }
    }
};
// Not the best approach, but O(1) space.
class Solution2
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        // code here
        int i, k;
        for (i = 0; i < n; i++)
        {
            // take first element from arr1
            // compare it with first element of second array
            // if condition match, then swap
            if (arr1[i] > arr2[0])
            {
                int temp = arr1[i];
                arr1[i] = arr2[0];
                arr2[0] = temp;
            }

            // then sort the second array
            // put the element in its correct position
            // so that next cycle can swap elements correctly
            int first = arr2[0];
            // insertion sort is used here
            for (k = 1; k < m && arr2[k] < first; k++)
            {
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
    }
};
// Using 3rd array
class Solution3
{
public:
    void insertAtindex(vector<int> &nums1, int value, int index)
    {
        int n = nums1.size();
        for (int i = n - 2; i >= index; --i)
        {
            nums1[i + 1] = nums1[i];
        }
        nums1[index] = value;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        vector<int> res(m + n);
        int i = 0, j = 0, k = 0;
        while ((i < m) && (j < n))
        {
            if (nums1[i] < nums2[j])
                res[k] = nums1[i++];
            else
                res[k] = nums2[j++];
            k++;
        }
        while (i < m)
        {
            res[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n)
        {
            res[k] = nums2[j];
            j++;
            k++;
        }
        nums1 = res;
    }
};

void code()
{
    Solution1 s;

    int m, n;
    cin >> m >> n;
    vi nums1(m + n), nums2(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> nums1[i];
    }
    for (int j = 0; j < n; ++j)
    {
        cin >> nums2[j];
    }
    debcon(nums1);
    debcon(nums2);
    s.merge(nums1, m, nums2, n);
    debcon(nums1);
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
