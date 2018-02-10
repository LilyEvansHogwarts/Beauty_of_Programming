#include "../../head/show.h"

//FILO
class maxStack {
public:
    void push(int x) {
	stackA.push(x);
	if(stackB.empty() || stackB.top() <= x)
	    stackB.push(x);
    }

    int pop() {
	if(stackA.empty()) return INT_MIN;
	if(stackA.top() == stackB.top())
	    stackB.pop();
	int res = stackA.top();
	stackA.pop();
	return res;
    }

    int Max() {
	if(stackB.empty()) return INT_MIN;
	return stackB.top();
    }

    bool empty() {
	return stackA.empty();
    }

private:
    stack<int> stackA;
    stack<int> stackB;
};

//FIFO
class maxQueue {
public:
    void push(int x) {
	stackB.push(x);
    }

    int pop() {
	if(stackA.empty() && stackB.empty())
	    return INT_MIN;
	if(stackA.empty()) {
	    while(!stackB.empty())
		stackA.push(stackB.pop());
	}
	return stackA.pop();
    }

    int Max() {
	return max(stackA.Max(),stackB.Max());
    }

    int empty() {
	return stackA.empty() && stackB.empty();
    }

private:
    maxStack stackA;
    maxStack stackB;
};

int main() {
    maxStack s;
    cout << "maxStack:" << endl;
    for(int i = 0;i < 10;i++) {
	int res = rand()%100;
	s.push(res);
	cout << res << " " << s.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 10;i++) 
	cout << s.pop() << " " << s.Max() << endl;
    maxQueue q;
    cout << "maxQueue:" << endl;
    for(int i = 0;i < 10;i++) {
	int res = rand()%100;
	q.push(res);
	cout << res << " " << q.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 10;i++)
	cout << q.pop() << " " << q.Max() << endl;
    return 0;
}
