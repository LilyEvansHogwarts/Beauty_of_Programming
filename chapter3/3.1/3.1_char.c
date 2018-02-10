#include "../../head/show.h"

bool solve1(char *src,char *des) {
    int n = strlen(src);
    for(int i = 0;i < n;i++) {
	char t = src[n-1];
	for(int j = n-1;j > 0;j--)
	    src[j] = src[j-1];
	src[0] = t;
	if(strstr(src,des))
	    return true;
    }
    return false;
}

bool solve2(char *src,char *des) {
    int n = strlen(src);
    char *addr = (char*)malloc(n);
    strcpy(addr,src);
    strcat(src,addr);
    char *p = strstr(src,des);
    return p != NULL;
}

//to debug
int main() {
    char src[] = "shifsodosknosninsjdisjdnssosndsidjmsonzgtyauq";
    char des[] = "sidjmsonzgtyauqshifsodosk";
    int start = clock();
    cout << solve1(src,des) << endl;
    cout << "time: " << clock()-start << endl;   
    char src1[] = "shifsodosknosninsjdisjdnssosndsidjmsonzgtyauq";
    char des1[] = "sidjmsonzgtyauqshifsodosk";
    start = clock();
    cout << solve2(src1,des1) << endl;
    cout << "time: " << clock()-start << endl;
    return 0;
}
