
#include <iostream>
#include <queue> 
#include <stack>


using namespace std;

int main(){
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    s.push(1);
    s.push(2);
    s.push(3);
    for(int i = 0; i < 3; ++i){
        cout << q.front() << endl;
        q.pop();
    }
    cout << "s turn" << endl;
    for(int i = 0; i < 3; ++i){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}

// 1
// 2
// 3
// s turn
// 3
// 2
// 1

