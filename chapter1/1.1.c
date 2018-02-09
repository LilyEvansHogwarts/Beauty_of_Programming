#include "../head/show.h"
#include<ctime>
#include<math.h>

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

/*
int main() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts); //from UTC1970-1-1 0:0:0 to present
    cout << ts.tv_sec*1000 + ts.tv_nsec/1000000 << endl;
    clock_gettime(CLOCK_MONOTONIC, &ts); //start point of the system to present
    cout << ts.tv_sec*1000 + ts.tv_nsec/1000000 << endl;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts); // start point of the process to present
    cout << ts.tv_sec*1000 + ts.tv_nsec/1000000 << endl;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts); //thread 
    cout << ts.tv_sec*1000 + ts.tv_nsec/1000000 << endl;
    return 0;
}
*/

/* solution 2: enter the percentage
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

unsigned long GetTickCount() {
    struct timespec ts;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    return ts.tv_sec*1000 + ts.tv_nsec/1000000;
}

/* solution 3: sine
int main() {
    const double SPLIT = 0.01;
    const int COUNT = 200;
    const double PI = 3.14159265;
    const int INTERVAL = 300;

    unsigned long  busySpan[COUNT];
    unsigned long  idleSpan[COUNT];
    int half = INTERVAL/2;
    double radian = 0.0;
    for(int i = 0;i < COUNT;i++) {
	busySpan[i] = (unsigned long )(half+(sin(PI*radian)*half));
	idleSpan[i] = INTERVAL - busySpan[i];
	radian += SPLIT;
    }
    unsigned long  startTime = 0;
    int j = 0;
    while(true) {
	j %= COUNT;
	startTime = GetTickCount();
	while(GetTickCount() - startTime <= busySpan[j]) ;
	sleep(idleSpan[j]);
	j++;
    }
    return 0;
}
*/
