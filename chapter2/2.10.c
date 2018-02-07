#include "../head/show.h"

vector<int> maxAndMin1(vector<int>& nums) {
    vector<int> res(2,INT_MIN);
    res[1] = INT_MAX;
    for(auto num:nums) {
	res[0] = max(num,res[0]);
	res[1] = min(num,res[1]);
    }
    return res;
}

vector<int> maxAndMin2(vector<int>& nums) {
    vector<int> res(2,INT_MIN);
    res[1] = INT_MAX;
    int n = nums.size(),i = 0,temp;
    while(i+1 < n) {
	if(nums[i] < nums[i+1]) {
	    temp = nums[i+1];
	    nums[i+1] = nums[i];
	    nums[i] = temp;
	}
	i += 2;
    }
    for(int j = 0;j < n;j +=2)
	res[0] = max(res[0],nums[j]);
    for(int j = 1;j < n;j +=2)
	res[1] = min(res[1],nums[j]);
    return res;
}

vector<int> maxAndMin3(vector<int>& nums) {
    vector<int> res(2,INT_MIN);
    res[1] = INT_MAX;
    int n = nums.size(),i = 0;
    while(i+1 < n) {
	if(nums[i] < nums[i+1]) {
	    res[0] = max(res[0],nums[i+1]);
	    res[1] = min(res[1],nums[i]);
	} else {
	    res[0] = max(res[0],nums[i]);
	    res[1] = min(res[1],nums[i+1]);
	}
	i+=2;
    }
    if(i < n) {
	res[0] = max(res[0],nums[i]);
	res[1] = min(res[1],nums[i]);
    }
    return res;
}

vector<int> maxAndMin4(vector<int>& nums,int start,int end) {
    if(end-start <= 1) {
	if(nums[start] < nums[end])
	    return vector<int>{nums[end],nums[start]};
	else
	    return vector<int>{nums[start],nums[end]};
    }
    vector<int> l = maxAndMin4(nums,start,start+(end-start)/2);
    vector<int> r = maxAndMin4(nums,start+(end-start)/2+1,end);
    if(l[0] < r[0])
	l[0] = r[0];
    if(l[1] > r[1])
	l[1] = r[1];
    return l;
}

vector<int> maxAndMin4(vector<int>& nums) {
    return maxAndMin4(nums,0,nums.size()-1);
}
	
int main() {
    vector<int> nums = {83,4920,482,382,484,28204,28,3,5,23,234,2254,38292,4,5,54,23234,252};
    int start = clock();
    vector<int> res = maxAndMin1(nums);
    show(res);
    cout << "time: " << clock()-start << endl;
    start = clock();
    res = maxAndMin2(nums);
    show(res);
    cout << "time: " << clock()-start << endl;
    start = clock();
    res = maxAndMin3(nums);
    show(res);
    cout << "time: " << clock()-start << endl;
    start = clock();
    res = maxAndMin4(nums);
    show(res);
    cout << "time: " << clock()-start << endl;
    return 0;
}



