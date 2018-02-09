#include "../head/show.h"
#include "../head/generate.h"

vector<int> floor1(vector<int>& person) {
    int n = person.size();
    int nFloor = 0,nMinFloor = INT_MAX,nTargetFloor;
    for(int i = 0;i < n;i++) {
	nFloor = 0;
	for(int j = 0;j < i;j++)
	    nFloor += person[j]*(i-j);
	for(int j = i+1;j < n;j++)
	    nFloor += person[j]*(j-i);
	if(nMinFloor > nFloor) {
	    nTargetFloor = i;
	    nMinFloor = nFloor;
	}
    }
    return vector<int>{nMinFloor,nTargetFloor};
}

vector<int> floor2(vector<int>& person) {
    int n = person.size();
    int N1,N2,N3,nFloor,nMinFloor = 0,nTargetFloor,i;
    for(N1 = 0,N2 = person[0],N3 = 0,i = 1;i < n;i++) {
	N3 += person[i];
	nMinFloor += person[i]*i;
    }
    for(int i = 1;i < n;i++) {
	if(N1+N2 < N3) {
	    nMinFloor += (N1+N2-N3);
	    nTargetFloor = i;
	    N1 += N2;
	    N2 = person[i];
	    N3 -= person[i];
	} else 
	    break;
    }
    return vector<int>{nMinFloor,nTargetFloor};
}

int main() {
    vector<int> person;
    generate(person,20);
    show(person);
    int start = clock();
    vector<int> res1 = floor1(person);
    cout << clock()-start << endl;
    show(res1);
    start = clock();
    vector<int> res2 = floor2(person);
    cout << clock()-start << endl;
    show(res2);
    return 0;
}
