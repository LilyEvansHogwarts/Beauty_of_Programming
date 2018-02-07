#include "../head/show.h"
#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)
#define RSET(b,n) (b = ((LMASK & b) ^ n))
#define LSET(b,n) (b = ((RMASK & b) ^ (n << HALF_BITS_LENGTH)))
#define RGET(b) (RMASK & b)
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH)
#define GRIDW 3
#include<stdio.h>

void chess1() {
    unsigned char b;
    for(LSET(b,1);LGET(b) <= GRIDW * GRIDW;LSET(b,(LGET(b)+1)))
	for(RSET(b,1);RGET(b) <= GRIDW * GRIDW;RSET(b,(RGET(b)+1)))
	    if(LGET(b)%GRIDW != RGET(b)%GRIDW)
		printf("(A = %d, B = %d)", LGET(b), RGET(b));
    cout << endl;
}

void chess2() {
    int i = 81;
    while(i--) {
	if(i/9%3 == i%9%3)
	    continue;
	cout << "(A = " << i/9+1 << ", B = " << i%9+1 << ")";
    }
    cout << endl;
}
 
void chess3() {
    struct {
	unsigned char a:4;
	unsigned char b:4;
    } i;
    for(i.a = 1;i.a <= 9;i.a++)
	for(i.b = 1;i.b <= 9;i.b++)
	    if(i.a%3 != i.b%3)
		cout << "(A = " << int(i.a) << ", B = " << int(i.b) << ")";
    cout << endl;
}

int main() {
    chess1();
    chess2();
    chess3();
    return 0;
}


