#include "maxStack2.h"

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
    maxStack2 stackA;
    maxStack2 stackB;
};

