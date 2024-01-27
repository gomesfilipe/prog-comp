#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Point {
    int x;
    int y;
} Point;

bool cmpEuclidianDistance(Point a, Point b) 
{
    return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}

int main() 
{
    int n;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points, points + n, cmpEuclidianDistance);
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
    return 0;
}