#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(vector<int>& nums,int start,int end) {
    int pos = rand()%(end-start+1)+start,temp = nums[end];
    nums[end] = nums[pos];
    nums[pos] = temp;
    int i = start-1,j = start;
    while(j <= end) {
	if(nums[j] <= nums[end]) {
	    temp = nums[++i];
	    nums[i] = nums[j];
	    nums[j] = temp;
	}
	j++;
    }
    return i;
}

void quicksort(vector<int>& nums,int start,int end) {
    if(start < end) {
	int q = partition(nums,start,end);
	quicksort(nums,start,q-1);
	quicksort(nums,q+1,end);
    }
}

void quicksort(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return;
    return quicksort(nums,0,n-1);
}

