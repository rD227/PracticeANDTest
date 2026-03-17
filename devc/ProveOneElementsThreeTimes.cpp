#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

const double eps = 1e-6;
double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double binarySearch(double l, double r) {
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (f(l) * f(mid) <= 0)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main() {
    cin >> a >> b >> c >> d;
    double lastRoot = -1e9; // 初始化为极小值
    int count = 0;

    for (int i = -100; i < 100; i++) {
        double l = i, r = i + 1;
        if (fabs(f(l)) < eps) {
            if (count == 0 || fabs(l - lastRoot) > 1.0) {
                cout << fixed << setprecision(2) << l << " ";
                lastRoot = l;
                count++;
            }
            continue;
        }
        if (f(l) * f(r) < 0) {
            double root = binarySearch(l, r);
            if (count == 0 || fabs(root - lastRoot) > 1.0) {
                cout << fixed << setprecision(2) << root << " ";
                lastRoot = root;
                count++;
            }
        }
        if (count == 3)
            break;
    }
    return 0;
}
