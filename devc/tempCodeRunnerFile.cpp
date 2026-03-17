#include <bits/stdc++.h>

using namespace std;

struct CheesePlace {
    int x, y;
    bool hasBeFoundOrNot = 0;
};

CheesePlace p[20];
double preMakeDistance[20][20];
int line = -1;

/*double distace(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)-(y1-y2)*(y1-y2));
}*/

double distance(int i, int j) {
    return sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2));
}

double ans = DBL_MAX;

void dfs(int nowPlace, int eatHowManyCheese, double sumDistance) {
    if (sumDistance > ans) {
        return;
    }
    if (eatHowManyCheese == line) {
        ans = sumDistance;
        return;
    }

    for (int i = 1; i <= line; i++) {
        if (p[i].hasBeFoundOrNot == false) {
            p[i].hasBeFoundOrNot = true;
            dfs(i, eatHowManyCheese + 1,
                sumDistance + preMakeDistance[nowPlace][i]);
            p[i].hasBeFoundOrNot = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> line;
    for (int i = 1; i <= line; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].hasBeFoundOrNot = false;
    }
    p[0].x = 0, p[0].y = 0, p;
    for (int i = 0; i <= line; i++) {
        for (int j = 0; j <= line; j++) {
            preMakeDistance[i][j] = distance(i, j);
        }
    }
    dfs(0, 0, 0.0);
    cout << fixed << setprecision(2) << ans << '\n';
}