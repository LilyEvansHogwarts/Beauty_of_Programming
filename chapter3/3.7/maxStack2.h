#include<stack>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

//FILO
class maxStack2 {
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

    
