#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int inf = 1e9;
int mod = 1e9+7;
const int N = 1e5+5;
int timer = 0;
vector<int> g[N];
int in[N], low[N], used[N];
set<int> apoint;    //avoiding multiple points

void dfs(int u, int p = -1) {
    used[u] = 1;
    in[u] = low[u] = ++timer;
    int child_cnt = 0;
    
    for(int v: g[u]) {
        if(v == p) 
            continue;
        if(used[v]) {
            //this is back edge 
            low[u] = min(low[u], in[v]);
        } else {
            //this is tree edge
            dfs(v, u);

            //why in bridge algo in[u] < low[v]
            if(in[u] <= low[v] && p != -1) 
                apoint.insert(u);
            low[u] = min(low[u], low[v]);
            child_cnt++;
        }
    }

    if(p == -1 && child_cnt > 1)
        apoint.insert(u);
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    print(apoint.size());
}   
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 
