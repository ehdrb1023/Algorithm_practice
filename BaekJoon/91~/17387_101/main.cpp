#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll res = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (res > 0) 
        return 1;
    if (res < 0) 
        return -1;
    return 0;
}

bool isIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    int abc = ccw(x1, y1, x2, y2, x3, y3);
    int abd = ccw(x1, y1, x2, y2, x4, y4);
    int cda = ccw(x3, y3, x4, y4, x1, y1);
    int cdb = ccw(x3, y3, x4, y4, x2, y2);

    if (abc * abd <= 0 && cda * cdb <= 0) {
        if (abc * abd == 0 && cda * cdb == 0) {
            if (make_pair(x1, y1) > make_pair(x2, y2)) { 
                swap(x1, x2); swap(y1, y2);
            }
            if (make_pair(x3, y3) > make_pair(x4, y4)) {
                swap(x3, x4); swap(y3, y4);
            }
            return make_pair(x3, y3) <= make_pair(x2, y2) && make_pair(x1, y1) <= make_pair(x4, y4);
        }
        return true;
    }
    return false;
}

int main() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << (isIntersect(x1, y1, x2, y2, x3, y3, x4, y4) ? 1 : 0) << endl;
    return 0;
}