#include "../head/show.h"

int gcd(long long a,long long b) {
    if(a == b) return a;
    int aa = a%2,bb = b%2;
    if(!aa && !bb)
	return 2*gcd(a>>1,b>>1);
    else if(aa && !bb)
	return gcd(a,b>>1);
    else if(!aa && bb)
	return gcd(a>>1,b);
    else if(a > b)
	return gcd(a-b,b);
    else 
	return gcd(b-a,a);
}

long long pow(int a,int n) {
    long long count = 1;
    while(n--) count *= a;
    return count;
}

vector<long long> factorial(int a,int n,int b,int m) {
    long long nums1 = b+a*(pow(10,m)-1),nums2 = pow(10,n)*(pow(10,m)-1);
    long long k = gcd(nums1,nums2);
    vector<long long> res = {nums1/k,nums2/k};
    return res;
}


int main() {
    int start = clock();
    vector<long long> nums = factorial(2673,4,278292,6);
    cout << nums[0] << "\t" << nums[1] << endl;
    cout << clock()-start << endl;
    return 0;
}
