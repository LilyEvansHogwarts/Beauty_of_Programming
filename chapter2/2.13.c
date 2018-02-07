#include "../head/show.h"

int maxMul1(vector<int>& nums) {
    int n = nums.size();
    vector<int> t(n,1);
    vector<int> s(n,1);
    for(int i = 0;i < n-1;i++)
	t[i+1] = t[i]*nums[i];
    for(int i = n-1;i > 0;i--)
	s[i-1] = s[i]*nums[i];
    int maxNum = INT_MIN,index = -1;
    for(int i = 0;i < n;i++) {
	if(maxNum < t[i]*s[i]) {
	    index = i;
	    maxNum = t[i]*s[i];
	}
    }
    return index;
}

int maxMul2(vector<int>& nums) {
    int n = nums.size();
    int zeroIndex = 0,negNum = 1,posNum = INT_MAX,negIndex = -1,posIndex = -1;
    for(int i = 0;i < n;i++) {
	if(nums[i] == 0) {
	    zeroIndex = i;
	    break;
	} else if(nums[i] < 0) {
	    negNum *= (-1);
	    if(negIndex < 0 || nums[i] < nums[negIndex])
		negIndex = i;
	} else if(nums[i] <= posNum)
	    posIndex = i;

    }
    if(zeroIndex >= 0) return zeroIndex;
    if(negNum < 0) return negIndex;
    return posIndex;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0,-1,-2,-3,-4};
    int start = clock();
    cout << maxMul1(nums) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxMul2(nums) << endl;
    cout << clock()-start << endl;
    return 0;
}
	
