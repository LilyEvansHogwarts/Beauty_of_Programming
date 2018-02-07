#include "../head/show.h"

void twoSum1(vector<int>& nums,int target) {
    int n = nums.size();
    for(int i = 0;i < n;i++) {
	for(int j = i+1;j < n;j++) {
	    if(nums[i]+nums[j] == target) {
		cout << nums[i] << "\t" << nums[j] << endl;
		return;
	    }
	}
    }
}

void twoSum2(vector<int>& nums,int target) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i = 0;i < n;i++) {
	int t = target - nums[i],start = 0,end = n-1;
	while(start < end) {
	    int mid = start + (end-start)/2;
	    if(nums[mid] > t)
		end = mid-1;
	    else if(nums[mid] < t)
		start = mid+1;
	    else if(mid != i) {
		cout << nums[i] << "\t" << nums[mid] << endl;
		return;
	    }
	}
    }
}

void twoSum3(vector<int>& nums,int target) {
    int start = 0,end = nums.size()-1;
    sort(nums.begin(),nums.end());
    while(start < end) {
	int sum = nums[start]+nums[end];
	if(sum > target)
	    end--;
	else if(sum < target)
	    start++;
	else {
	    cout << nums[start] << "\t" << nums[end] << endl;
	    return;
	}
    }
}

int main() {
    vector<int> nums(30,0);
    for(int i = 0;i < 100;i++)
	nums[i] = rand()%100;
    int target = 88;
    int start = clock();
    twoSum1(nums,target);
    cout << "time: " << clock()-start << endl;
    start = clock();
    twoSum2(nums,target);
    cout << "time: " << clock()-start << endl;
    start = clock();
    twoSum3(nums,target);
    cout << "time: " << clock()-start << endl;
    return 0;
}
