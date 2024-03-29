#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()


using namespace chrono;
auto t1 = high_resolution_clock::now();
fib = fibonacci(n);
auto t2 = high_resolution_clock::now();
duration<double, milli> diff = t2 - t1;
        
// beautify      
cout << setw(5) << n << "\t\t" << setw(9) << fib << "\t" << setw(7) << diff.count() << endl;


/*****User defined function*****/
const int N = 1e8;

void solve_problem() {
    vector<int> vec1(N);
    for(int i = 0; i < N; i++)
        vec1.push_back(i);
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(9);

    clock_t start, end;
    start = clock();
 
    int test = 1;
    //cin >> test;
    while(test--) solve_problem();
    
    end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken: " << time_taken << endl;

    return 0;
} 
