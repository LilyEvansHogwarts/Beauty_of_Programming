#include "../head/show.h"

int maxSum1(vector<int>& nums,int n) {
    int maxNum = INT_MIN,sum = 0;
    for(int i = 0;i < n;i++) {
	for(int j = i;j < n;j++) {
	    sum = 0;
	    for(int k = i;k <= j;k++)
		sum += nums[k];
	    if(maxNum < sum) 
		maxNum = sum;
	}
    }
    return maxNum;
}

int maxSum2(vector<int>& nums,int n) {
    int maxNum = INT_MIN,sum = 0;
    for(int i = 0;i < n;i++) {
	sum = 0;
	for(int j = i;j < n;j++) {
	    sum += nums[j];
	    if(maxNum < sum) 
		maxNum = sum;
	}
    }
    return maxNum;
}

int maxSum3(vector<int>& nums,int n) {
    vector<int> start(n,0);
    vector<int> all(n,0);
    all[n-1] = nums[n-1];
    start[n-1] = nums[n-1];
    for(int i = n-2;i >= 0;i--) {
	start[i] = nums[i]+max(start[i+1],0);
	all[i] = max(all[i+1],start[i]);
    }
    return all[0];
}

int maxSum4(vector<int>& nums,int n) {
    int local = INT_MIN,all = INT_MIN;
    for(int i = 0;i < n;i++) {
	local = nums[i] + max(local,0);
	all = max(all,local);
    }
    return all;
}

int main() {
    vector<int> nums = {1,5,-7,2,5,2,5,-5,2,6,7,-4,3,6,2,4,5,3,-7,1,3,-3,2,3,-1,-3,-4,2,3,4,6,7,-3};
    int start = clock(),n = nums.size();
    cout << maxSum1(nums,n) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum2(nums,n) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum3(nums,n) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum4(nums,n) << endl;
    cout << clock()-start << endl;
    return 0;
}
