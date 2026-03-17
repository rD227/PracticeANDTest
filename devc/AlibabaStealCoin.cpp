#include <bits/stdc++.h>

using namespace std;

struct Heap {
    double m, v;
    double massValue;
};

int main() {
    int N, T;
    double sumValue = 0;
    cin >> N >> T;
    vector<Heap> heap(N);
    for (int i = 0; i < N; i++) {
        cin >> heap[i].m >> heap[i].v;
        heap[i].massValue = heap[i].v / heap[i].m;
    }
    sort(heap.begin(), heap.end(), [](const Heap &a, const Heap &b) {
        return a.massValue > b.massValue;
    });
    // 接下来，循环拿取，如果装不下就分割
    for (int i = 0; i < N; i++) {
        if (heap[i].m < T) {
            T = T - heap[i].m;
            if (T < 0)
                break;
            sumValue += heap[i].m * heap[i].massValue;
        } else if (heap[i].m >= T) {
            sumValue += heap[i].massValue * T;
            break;
        }
    }
    // cout << "N is " << N << " T is " << T << endl;
    cout << fixed << setprecision(2) << sumValue << endl;
}