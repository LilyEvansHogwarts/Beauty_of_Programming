#include "../head/show.h"

int find1(vector<int>& ID,int N) {
    int candidate,nTimes = 0;
    for(int i = 0;i < N;i++) {
	if(nTimes == 0) {
	    candidate = ID[i];
	    nTimes++;
	} 
	else if(candidate == ID[i])
	    nTimes++;
	else
	    nTimes--;
    }
    return candidate;
}

//extend
vector<int> find2(vector<int>& ID,int N) {
    int candidate1 = 0,candidate2 = 1,candidate3 = 2,nTimes1 = 0,nTimes2 = 0,nTimes3 = 0;
    for(int i = 0;i < N;i++) {
	if(candidate1 == ID[i])
	    nTimes1++;
	else if(candidate2 == ID[i])
	    nTimes2++;
	else if(candidate3 == ID[i])
	    nTimes3++;
	else if(nTimes1 == 0) {
	    candidate1 = ID[i];
	    nTimes1++;
	} else if(nTimes2 == 0) {
	    candidate2 = ID[i];
	    nTimes2++;
	} else if(nTimes3 == 0) {
	    candidate3 = ID[i];
	    nTimes3++;
	} else {
	    nTimes1--;
	    nTimes2--;
	    nTimes3--;
	}
    }
    nTimes1 = 0;
    nTimes2 = 0;
    nTimes3 = 0;
    for(auto num:ID) {
	if(candidate1 == num)
	    nTimes1++;
	else if(candidate2 == num)
	    nTimes2++;
	else if(candidate3 == num)
	    nTimes3++;
    }
    vector<int> res;
    if(nTimes1 > N/4) res.push_back(candidate1);
    if(nTimes2 > N/4) res.push_back(candidate2);
    if(nTimes3 > N/4) res.push_back(candidate3);
    return res;
}

int main() {
    vector<int> nums = {1,2,2,3,4,2,52,2,2,2,4,4,4,2,2,2,5,5,2,6,3,4,2,2,2,2,2,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,6,6,1,1,1,1};
    cout << find1(nums,nums.size()) << endl;
    vector<int> res = find2(nums,nums.size());
    show(res);
    return 0;
}

