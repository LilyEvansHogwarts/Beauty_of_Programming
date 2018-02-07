#include "../head/show.h"

void rightShift1(vector<int>& nums,int n,int k) {
    while(k--) {
	int t = nums[n-1];
	for(int i = n-1;i > 0;i--)
	    nums[i] = nums[i-1];
	nums[0] = t;
    }
}

void rightShift2(vector<int>& nums,int n,int k) {
    k %= n;
    while(k--) {
	int t = nums[n-1];
	for(int i = n-1;i > 0;i--)
	    nums[i] = nums[i-1];
	nums[0] = t;
    }
}

void reverse(vector<int>& nums,int start,int end) {
    while(start < end) {
	int temp = nums[end];
	nums[end] = nums[start];
	nums[start] = temp;
	start++;
	end--;
    }
}


void rightShift3(vector<int>& nums,int n,int k) {
    k %= n;
    reverse(nums,0,n-k-1);
    reverse(nums,n-k,n-1);
    reverse(nums,0,n-1);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12};
    int start = clock();
    rightShift1(nums,12,20);
    cout << clock()-start << endl;
    show(nums);
    start = clock();
    rightShift2(nums,12,20);
    cout << clock()-start << endl;
    show(nums);
    start = clock();
    rightShift3(nums,12,20);
    cout << clock()-start << endl;
    show(nums);
    return 0;
}
