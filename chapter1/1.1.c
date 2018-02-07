#include "../head/show.h"

/*solution1: 50% CPU occupy
int main() {
    int n = 4700; 
    while(true) {
	for(int i = 0;i < n;i++) ;
	sleep(0.01);//sleep() is for second in Linux, microsecond in windows
    }
    return 0;
}
*/

int main() {
    while(true) {
	cout << clock()/CLOCKS_PER_SECOND << endl;
    }
}

/*
int main(int argc,char* argv[]) {
    int n = atoi(argv[1]);
    int m = 4700*n/(100-n);
    while(true) {
	for(int i = 0;i < m;i++) ;
	sleep(0.01);
    }
    return 0;
}
*/
