/*find the value of x and y for the equation ax + by = gcd(a, b)*/


/*************Extended euclidean algorithm*************/
int gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }

    int x1, y1, d;
    d = gcd(b, a%b, x1, y1);
    x = y1;
    y = x1-y1*(a/b);
    
    return d;
}
