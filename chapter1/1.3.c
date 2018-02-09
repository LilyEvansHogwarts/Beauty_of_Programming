#include "../head/show.h"
#include "../head/generate.h"

void reverse(vector<int>& nums,int start,int end) {
    while(start < end) {
	int temp = nums[start];
	nums[start] = nums[end];
	nums[end] = temp;
	start++;
	end--;
    }
}


int prefixSort(vector<int>& nums) {
    int n = nums.size(),times = 0;
    int i = n-1;
    while(i > 0) {
	int j = 0,maxNum = INT_MIN,index = 0;
	while(j <= i) {
	    if(nums[j] > maxNum) {
		maxNum = nums[j];
		index = j;
	    }
	    j++;
	}
	if(i == index) {
	    i--;
	    continue;
	}
	reverse(nums,0,index);
	reverse(nums,0,i);
	times++;
	i--;
    }
    return times << 1;
}

int main() {
    vector<int> nums;
    generate(nums,10);
    cout << "nums: ";;
    show(nums);
    cout << prefixSort(nums) << endl;
    return 0;
}

