#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    //every element can use only one time
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    rep(i, 0, n) {
        rrep(j, k, a[i]) {
            if(!dp[j] && dp[j-a[i]] > 0)
                dp[j] = a[i];
        }
    }

    rep(i, 1, k+1) cout << dp[i] << ' ';
    cout << endl;

    int i = k;
    while(i != 0) {
        cout << dp[i] << " ";
        i -= dp[i];
    }
}


/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cout << fixed << showpoint;
    cout << setprecision(16);

    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    
