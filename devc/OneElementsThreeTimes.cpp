#include <bits/stdc++.h>

using namespace std;

double f(double x);
double binarySearch(double begin, double end);

const double eps = 1e-6;
double a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    int count = 0;
    double lastRoot = 1.0e-9;
    for (double i = -100; i <= 100; i++) {
        double begin = i, end = i + 1;
        if (fabs(f(begin)) < eps) {
            if (lastRoot == 1.0e-9 || begin - lastRoot >= 1.0) {
                cout << fixed << setprecision(2) << begin << " ";
                lastRoot = begin;
                count++;
            }
            continue;
        }
        if (f(begin) * f(end) < 0) {
            double mid = binarySearch(begin, end);
            if (count == 0 || fabs(mid - lastRoot) > 1.0) {
                cout << fixed << setprecision(2) << mid << " ";
                lastRoot = mid;
                count++;
            }
        }
        if (count == 3) {
            break;
        }
    }
    return 0;
}
double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double binarySearch(double begin, double end) {
    double mid = -1;
    while (end - begin > eps) {
        mid = (begin + end) / 2.0;
        if (f(begin) * f(mid) < 0) {
            end = mid;
        } else {
            begin = mid;
        }
    }
    return mid;
}