//
// Created by kdongha on 2020/01/06.
//

#include <bits/stdc++.h>

int N;
struct Point {
    int x;
    int y;
};
Point point[100005];

bool compare(const Point &p1, const Point &p2) {
    long long int s = 1LL * (p1.x - point[0].x) * (p2.y - point[0].y) - 1LL * (p1.y - point[0].y) * (p2.x - point[0].x);
    if (s > 0) {
        return true;
    } else if (s < 0) {
        return false;
    } else if (p1.y != p2.y) {
        return p1.y < p2.y;
    } else {
        return p1.x < p2.x;
    }
}

void findPivot() {
    for (int i = 1; i < N; i++) {
        if (point[0].y > point[i].y) {
            Point temp = point[0];
            point[0] = point[i];
            point[i] = temp;
        } else if (point[0].y == point[i].y && point[0].x > point[i].x) {
            Point temp = point[0];
            point[0] = point[i];
            point[i] = temp;
        }
    }
}

long long int ccw(int p1, int p2, int p3) {
    return 1LL * point[p1].x * point[p2].y + 1LL * point[p2].x * point[p3].y + 1LL * point[p3].x * point[p1].y -
           1LL * point[p2].x * point[p1].y - 1LL * point[p3].x * point[p2].y - 1LL * point[p1].x * point[p3].y;
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> point[i].x >> point[i].y;
    }
    findPivot();
    std::sort(point + 1, point + N, compare);
    std::stack<int> s;
    s.push(0);
    s.push(1);
    for (int i = 2; i < N; i++) {
        while (s.size()>=2) {
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            if (ccw(v1, v2, i) > 0) {
                s.push(v2);
                break;
            }
        }
        s.push(i);
    }
    std::cout << s.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}