#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double calculatePolygonArea(const vector<Point>& vertices) {
    int n = vertices.size();
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        area += (vertices[i].x * vertices[next].y - vertices[next].x * vertices[i].y);
    }

    return 0.5 * abs(area);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    vector<Point> vertices(n);

    for(int i = 0; i < n; i++){
        cin>>vertices[i].x>>vertices[i].y;
    }

    double area = calculatePolygonArea(vertices);

    cout << fixed << setprecision(1) << area << endl;

    return 0;
}
