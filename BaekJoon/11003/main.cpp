#include <iostream>
#include <deque> 
using namespace std;

typedef pair<int, int> Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    deque<Node> mydeque;

    for(int i = 0; i < N; i++) {
        int now;
        cin >> now;
        while(mydeque.size() && mydeque.back().first > now) {
            mydeque.pop_back();
        }

        mydeque.push_back(Node(now, i));

        // i가 늘어날수록 맨 앞에 있는 Node의 index는 무조건 꼬박꼬박 걸러지기 때문에 맨 앞에 있는 수만 걸러도 괜찮음.
        if(mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }

        cout << mydeque.front().first << ' ';


    }
}