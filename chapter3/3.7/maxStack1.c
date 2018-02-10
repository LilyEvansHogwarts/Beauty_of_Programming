#include "../../head/show.h"

const int stackSize = 256;

//FILO
class maxStack {
public:
    maxStack() {
	stackTop = -1;
	maxStackItemIndex = -1;
    }

    void push(int x) {
	stackTop++;
	stackItem[stackTop] = x;
	if(maxStackItemIndex == -1 || x >= stackItem[maxStackItemIndex]) {
	    linkNextMaxItem[stackTop] = maxStackItemIndex;
	    maxStackItemIndex = stackTop;
	} else 
	    linkNextMaxItem[stackTop] = -1;
    }

    int pop() {
	if(stackTop == -1) return INT_MIN;
	if(stackTop == maxStackItemIndex)
	    maxStackItemIndex = linkNextMaxItem[stackTop];
	int res = stackItem[stackTop];
	stackTop--;
	return res;
    }

    int Max() {
	if(maxStackItemIndex == -1) return INT_MIN;
	return stackItem[maxStackItemIndex];
    }

    bool empty() {
	return stackTop == -1;
    }

private:
    int stackTop;
    int maxStackItemIndex;
    int stackItem[stackSize];
    int linkNextMaxItem[stackSize];
};

int main() {
    maxStack s;
    for(int i = 0;i < 10;i++) {
	int res = rand()%100;
	s.push(res);
	cout << res << " " << s.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 10;i++) 
	cout << s.pop() << " " << s.Max() << endl;
    return 0;
}
