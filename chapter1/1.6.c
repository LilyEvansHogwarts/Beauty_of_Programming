#include "../head/show.h"

int Cal1(int V,int T) {
    vector<vector<int>> opt(V+1,vector<int>(T+1,0));
    opt[0][T] = 0;
    for(int i = 1;i <= T;i++)
	opt[i][T] = INT_MIN;
    for(int j = T-1;j >= 0;j--) {
	for(int i = 0;i <= T;i++) {
	    opt[i][j] = INT_MIN;
	    for(int k = 0;k <= C[j];k++) {
		if(i < k*V[j])
		    break;
		int x = opt[i-k*V[j]][j+1];
		if(x != INT_MIN) {
		    x += k*H[j];
		    if(x > opt[i][j])
			opt[i][j] = x;
		}
	    }
	}
    }
    return opt[V][0];
}



int Cal2(int V,int type,vector<vector<int>>& opt) {
    if(type == T) {
	if(V == 0) return 0;
	else return INT_MIN;
    }
    if(V < 0) return INT_MIN;
    else if(V == 0) return 0;
    else if(opt[V][type] != -1)
	return opt[V][type];

    int ret = INT_MIN;
    for(int i = 0;i <= C[type];i++) {
	int temp = Cal(V-i*V[type],type+1);
	if(temp != INT_MIN) {
	    temp += i*H[type];
	    if(temp > res)
		res = temp;
	}
    }
    return opt[V][type] = res;
}


