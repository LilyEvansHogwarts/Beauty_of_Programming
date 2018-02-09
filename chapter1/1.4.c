#include "../head/show.h"

vector<int> generate() {
    vector<int> res(5,0);
    for(int i = 0;i < 5;i++)
	res[i] = rand()%100;
    sort(res.begin(),res.end(),greater<int>());
    return res;
}

void solve(vector<int>& nums) {
    vector<int> res(5,0);
    res[4] = nums[4];
    res[3] = nums[3]-nums[4];
    res[2] = nums[2]-nums[3];
    res[1] = nums[1]-nums[2];
    res[0] = nums[0]-nums[1];
    cout << "money saved(greedy algorithm:)\n";
    cout << res[0] << "\t";
    cout << res[1] << "\t";
    cout << res[2] << "\t";
    cout << res[3] << "\t";
    cout << res[4] << endl;
    cout << 8*(res[4]*5*0.25+res[3]*4*0.2+res[2]*3*0.1+res[1]*2*0.05) << endl;
    int k = min(res[2],res[4]);
    res[3] += 2*k;
    res[2] -= k;
    res[4] -= k;
    cout << "money saved(greedy algorithm with minor change, supposed to get optimum solution):\n";
    cout << res[0] << "\t";
    cout << res[1] << "\t";
    cout << res[2] << "\t";
    cout << res[3] << "\t";
    cout << res[4] << endl;
    cout << 8*(res[4]*5*0.25+res[3]*4*0.2+res[2]*3*0.1+res[1]*2*0.05) << endl;
    return;
}

int main() {
    vector<int> nums = generate();
    show(nums);
    solve(nums);
    return 0;
}

