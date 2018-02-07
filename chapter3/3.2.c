#include "../head/show.h"

vector<string> solve(vector<int>& number,vector<int>& total,vector<string>& c) {
    vector<string> res = {""};
    for(int i = 0;i < number.size();i++) {//c[number[i]]
	int n = res.size(),k = 0;
	while(k++ < n && total[number[i]] > 0) {
	    string t = res.back();
	    res.pop_back();
	    for(int j = 0;j < total[number[i]];j++)
		res.insert(res.begin(),t+c[number[i]][j]);
	}
    }
    return res;
}

vector<string> word(vector<int>& number) {
    vector<int> total = {0,0,3,3,3,3,3,4,3,4};
    vector<string> c = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    retun solve(number,total,c);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    vector<string> res = word(nums);
    cout << "res:\t" << res.size() << endl;
    return 0;
}
