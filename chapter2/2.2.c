#include "../head/show.h"

int zeroNums1(int n) {
    int res = 0;
    for(int i = 1;i <= n;i++) {
	int j = i;
	while(j%5 == 0) {
	    res++;
	    j /= 5;
	}
    }
    return res;
}

int zeroNums2(int n) {
    int res = 0;
    while(n) {
	n /= 5;
	res += n;
    }
    return res;
}

int twoFactorNums1(int n) {
    int res = 0;
    while(n) {
	n >>= 1;
	res += n;
    }
    return res;
}
    
int twoFactorNums2(int n) {
    int res = 0,v = n;
    while(v) {
	v &= v-1;
	res++;
    }
    return n-res;
}

int main() {
    int n = 200000000;
    int start = clock();
    for(int i = n;i < n+5;i++)
	zeroNums1(i);
    cout << "time: " << clock() - start << endl;
    start = clock();
    for(int i = n;i < n+5;i++)
	zeroNums2(i);
    cout << "time: " << clock() - start << endl;
    start = clock();
    for(int i = n;i < n+1000;i++)
	twoFactorNums1(i);
    cout << "time: " << clock() - start << endl;
    start = clock();
    for(int i = n;i < n+1000;i++)
	twoFactorNums2(i);
    cout << "time: " << clock() - start << endl;
    start = clock();
    return 0;
}

