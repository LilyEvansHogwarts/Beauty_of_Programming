#include "../head/show.h"

int countInAInteger(int n) {
    int count = 0;
    while(n) {
	count += (n%10 == 1);
	n /= 10;
    }
    return count;
}


int oneNums1(int n) {
    int count = 0;
    for(int i = 1;i <= n;i++)
	count += countInAInteger(i);
    return count;
}

int oneNums2(int n) {
    int count = 0,iLowerNum = 0,iCurrNum = 0,iHigherNum = 0,iFactor = 1;
    while(n/iFactor != 0) {
	iLowerNum = n%iFactor;
	iHigherNum = n/(iFactor*10);
	iCurrNum = (n/iFactor)%10;
	switch(iCurrNum) {
	    case 0:
		count += iHigherNum * iFactor;
		break;
	    case 1:
		count += iHigherNum * iFactor + iLowerNum + 1;
		break;
	    default:
		count += (iHigherNum + 1) * iFactor;
		break;
	}
	iFactor *= 10;
    }
    return count;
}

//extend
int oneNums3(int n) {
    int count = 0,iLowerNum = 0,iCurrNum = 0,iHigherNum = 0,iFactor = 1;
    while(n/iFactor != 0) {
	iLowerNum = n%iFactor;
	iCurrNum = (n/iFactor)%2;
	iHigherNum = n/(iFactor<<1);
	if(iCurrNum == 0)
	    count += iHigherNum * iFactor;
	else 
	    count += iHigherNum * iFactor + iLowerNum + 1;
	iFactor <<= 1;
    }
    return count;
}




int main() {
    int start = clock(),n = 600000;
    cout << oneNums1(n) << endl;
    cout << clock() - start << endl;
    start = clock();
    cout << oneNums2(n) << endl;
    cout << clock() - start << endl;
    start = clock();
    cout << oneNums3(n) << endl;
    cout << clock() - start << endl;
    return 0;
}
