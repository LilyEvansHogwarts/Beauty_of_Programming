#include "../head/show.h"

int solve1(string& strA, int Astart,int Aend,string& strB,int Bstart,int Bend) {
    if(Astart > Aend) {
	if(Bstart > Bend) return 0;
	else return Bend-Bstart+1;
    }
    if(Bstart > Bend) return Aend-Astart+1;
    if(strA[Astart] == strB[Bstart]) 
	return solve1(strA,Astart+1,Aend,strB,Bstart+1,Bend);
    else {
	int t1 = solve1(strA,Astart+1,Aend,strB,Bstart,Bend);
	int t2 = solve1(strA,Astart,Aend,strB,Bstart+1,Bend);
	int t3 = solve1(strA,Astart+1,Aend,strB,Bstart+1,Bend);
	return min(min(t1,t2),t3)+1;
    }
}

int calculateStringDistance1(string& strA,string& strB) {
    int n1 = strA.size(),n2 = strB.size();
    return solve1(strA,0,n1-1,strB,0,n2-1);
}

int solve2(string& strA, int Astart,int Aend,string& strB,int Bstart,int Bend,vector<vector<int>>& res) {
    if(Astart > Aend) {
	if(Bstart > Bend) return 0;
	else return Bend-Bstart+1;
    }
    if(Bstart > Bend) return Aend-Astart+1;
    if(res[Astart][Bstart] >= 0) return res[Astart][Bstart];
    else if(strA[Astart] == strB[Bstart]) 
	return res[Astart][Bstart] = solve2(strA,Astart+1,Aend,strB,Bstart+1,Bend,res);
    else {
	int t1 = solve2(strA,Astart+1,Aend,strB,Bstart,Bend,res);
	int t2 = solve2(strA,Astart,Aend,strB,Bstart+1,Bend,res);
	int t3 = solve2(strA,Astart+1,Aend,strB,Bstart+1,Bend,res);
	return res[Astart][Bstart] =  min(min(t1,t2),t3)+1;
    }
}

int calculateStringDistance2(string& strA,string& strB) {
    int na = strA.size(),nb = strB.size();
    vector<vector<int>> res(na,vector<int>(nb,-1));
    return solve2(strA,0,na-1,strB,0,nb-1,res);
}

int calculateStringDistance3(string& strA,string& strB) {
    int n1 = strA.size(),n2 = strB.size();
    if(n1 == 0) return n2;
    if(n2 == 0) return n1;
    vector<vector<int>> res(n1+1,vector<int>(n2+1,0));
    for(int i = 0;i <= n1;i++) res[i][0] = i;
    for(int i = 0;i <= n2;i++) res[0][i] = i;
    for(int i = 1;i <= n1;i++) {
	for(int j = 1;j <= n2;j++) {
	    if(strA[i-1] == strB[j-1]) res[i][j] = res[i-1][j-1];
	    else res[i][j] = min(res[i-1][j-1],min(res[i-1][j],res[i][j-1]))+1;
	}
    }
    return res[n1][n2];
}

int main() {
    string A = "jfoscjsodifosi";
    string B = "anvmznxbviw";
    int na = A.size(),nb = B.size();
    int start = clock();
    cout << calculateStringDistance1(A,B) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << calculateStringDistance2(A,B) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << calculateStringDistance3(A,B) << endl;
    cout << clock()-start << endl;
    return 0;
}
