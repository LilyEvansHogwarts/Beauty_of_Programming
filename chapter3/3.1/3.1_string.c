#include "../../head/show.h"

bool solve1(string src,string des) {
    int n = src.size(),m = des.size();
    for(int i = 0;i < n;i++) {
	char t = src[n-1];
	for(int j = n-1;j > 0;j--)
	    src[j] = src[j-1];
	src[0] = t;
	if(des == string(src.begin(),src.begin()+m))
	    return true;
    }
    return false;
}

bool solve2(string src,string des) {
    string p = src + src;
    int n = p.size(),m = des.size(),i = 0;
    while(i < n-m) {
	if(p[i] == des[0] && des == string(p.begin()+i,p.begin()+m+i))
	    return true;
	i++;
    }
    return false;
}

int main() {
    string src = "josdofjsidfpoapsdjonpsocpozsjdnpoponposcdpoaspnodpascosdfshdifsj";
    string des = "pascosdfshdifsjjosdofjsidfpoa";
    int start = clock();
    cout << solve1(src,des) << endl;
    cout << "time: " << clock()-start << endl;
    start = clock();
    cout << solve2(src,des) << endl;
    cout << "time: " << clock()-start << endl;
    return 0;
}

