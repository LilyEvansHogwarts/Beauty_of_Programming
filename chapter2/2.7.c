#include "../head/show.h"

int gcd1(int x,int y) {
    return (!y)?x:gcd1(y,x%y);
}

int gcd2(int x,int y) {
    if(x < y)
	return gcd2(y,x);
    if(y == 0)
	return x;
    else
	return gcd2(x-y,y);
}

int gcd3(int x,int y) {
    if(x < y)
	return gcd3(y,x);
    if(y == 0)
	return x;
    else if(x%2) {
	if(y%2)
	    return gcd3(x-y,y);
	else
	    return gcd3(x,y>>1);
    } else {
	if(y%2)
	    return gcd3(x>>1,y);
	else
	    return gcd3(x>>1,y>>1);
    }
}

int main() {
    int x = 28927490,y = 72293729;
    int start = clock();
    cout << gcd1(x,y) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << gcd2(x,y) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << gcd3(x,y) << endl;
    cout << "time: " << clock()-start << endl;
    return 0;
}
