#include<iostream>
#include "../head/show.h"
using namespace std;

int oneNums1(int v) {
    int num = 0;
    while(v) {
	if(v%2) num++;
	v /= 2;
    }
    return num;
}

int oneNums2(int v) {
    int num = 0;
    while(v) {
	num += v & 1;
	v >>= 1;
    }
    return num;
}

int oneNums3(int v) {
    int num = 0;
    while(v) {
	v &= v-1;
	num++;
    }
    return num;
}

int main() {
    int n = 262144;
    int start = clock();
    for(int i = 1;i <= n;i++)
	oneNums1(i);
    cout << clock() - start << endl;
    start = clock();
    for(int i = 1;i <= n;i++)
	oneNums2(i);
    cout << clock() - start << endl;
    start = clock();
    for(int i = 1;i <= n;i++)
	oneNums3(i);
    cout << clock() - start << endl;
    return 0;
}
