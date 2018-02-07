#include "../head/show.h"

bool solve1(char *src,char *des) {
    int n = strlen(src);
    for(int i = 0;i < n;i++) {
	char t = src[n-1];
	for(int i = 1;i < n;i++)
	    src[i] = src[i-1];
	src[0] = t;
	if(strstr(src,des) == 0)
	    return true;
    }
    return false;
}

bool solve2(char *src,char *des) {
    strcat(src,src);
    return strstr(src,des) == 0;
}

int main() {
    char src[] = "shifsodosknosninsjdisjdnssosndsidjmsonzgtyauq";
    char des[] = "sidjmsonzgtyauqshifsodosk";
    int start = clock();
    cout << solve1(src,des) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << solve2(src,des) << endl;
    cout << clock()-start << endl;
    return 0;
}
