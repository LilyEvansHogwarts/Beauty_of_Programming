#include "../head/show.h"

vector<vector<int>> generate(int n,int m) {
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int i = 0;i < n;i++) 
	for(int j = 0;j < m;j++) 
	    res[i][j] = rand()%100000;
    return res;
}

int maxSum1(vector<vector<int>>& nums,int n,int m) {
    int maxNum = INT_MIN;
    for(int i_min = 0;i_min < n;i_min++) {
	for(int i_max = i_min;i_max < n;i_max++) {
	    for(int j_min = 0;j_min < m;j_min++) {
		for(int j_max = j_min;j_max < m;j_max++) {
		    int sum = 0;
		    for(int k = i_min;k <= i_max;k++) 
			for(int p = j_min;p <= j_max;p++)
			    sum += nums[k][p];
		    maxNum = max(maxNum,sum);
		}
	    }
	}
    }
    return maxNum;
}

int maxSum2(vector<vector<int>>& nums,int n,int m) {
    vector<vector<int>> sum(n+1,vector<int>(m+1,0));
    int maxNum = INT_MIN;
    for(int i = 1;i <= n;i++) {
	for(int j = 1;j <= m;j++) {
	    sum[i][j] = sum[i-1][j]+sum[i][j-1]+nums[i-1][j-1]-sum[i-1][j-1];
	    maxNum = max(sum[i][j],maxNum);
	}
    }
    return maxNum;
}

int maxSum3(vector<vector<int>>& nums,int n,int m) {
    vector<int> sum1(m+1,0),sum2(m+1,0);
    int maxNum = INT_MIN;
    for(int i = 1;i <= n;i++) {
	for(int j = 1;j <= m;j++) {
	    sum2[j] = sum1[j]+sum2[j-1]+nums[i-1][j-1]-sum1[j-1];
	    maxNum = max(maxNum,sum2[j]);
	}
	swap(sum2,sum1);
    }
    return maxNum;
}
	
int maxSum4(vector<vector<int>>& nums,int n,int m) {
    int local = INT_MIN,global = INT_MIN,maxNum = INT_MIN;
    vector<int> sum(n,0);
    for(int i = 0;i < m;i++) {
	for(int j = i;j < m;j++) {
	    local = INT_MIN;
	    global = INT_MIN;
	    for(int k = 0;k < n;k++) {
		sum[k] += nums[k][j];
		local = sum[k]+max(local,0);
		global = max(local,global);
	    }
	    maxNum = max(maxNum,global);
	}
	for(int k = 0;k < n;k++)
	    sum[k] = 0;
    }
    return maxNum;
}

int main() {
    int n = 30,m = 30;
    vector<vector<int>> nums = generate(n,m);
    int start = clock();
    cout << maxSum1(nums,n,m) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum2(nums,n,m) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum3(nums,n,m) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << maxSum4(nums,n,m) << endl;
    cout << clock()-start << endl;
    return 0;
}


