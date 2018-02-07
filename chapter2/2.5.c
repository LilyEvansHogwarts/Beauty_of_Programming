#include "../head/show.h"

//quicksort
void find(vector<int>& nums,int start,int end,int k) {
    if(end-start+1 <= k) return;
    int pos = rand()%(end-start+1)+start,temp = nums[end];
    nums[end] = nums[pos];
    nums[pos] = temp;
    int i = start-1,j = start;
    while(j <= end) {
	if(nums[j] <= nums[end]) {
	    i++;
	    temp = nums[j];
	    nums[j] = nums[i];
	    nums[i] = temp;
	}
	j++;
    }
    if(end-i+1 < k) 
	return find(nums,start,i-1,k+i-end-1);
    else if(end-i > k)
	return find(nums,i+1,end,k);
    else return;
}

vector<int> kLargestNums1(vector<int>& nums, int k) {
    int n = nums.size();
    find(nums,0,n-1,k);
    return vector<int>(nums.begin()+n-k,nums.end());
}

//max-heap
vector<int> kLargestNums2(vector<int>& nums,int k) {
    vector<int> heap(k,INT_MIN);
    int n = nums.size();
    for(int i = 0;i < n;i++) {
	int p = 0;
	while(p < k) {
	    if(

    
int main() {
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    vector<int> res = kLargestNums(nums,5);
    show(res);
}


