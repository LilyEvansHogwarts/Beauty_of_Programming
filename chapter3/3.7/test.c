#include "maxQueue.h"
#include "maxStack1.h"
using namespace std;

int main() {
    maxQueue s;
    cout << "maxQueue:" << endl;
    for(int i = 0;i < 32;i++) {
	int res = rand()%100;
	s.push(res);
	cout << res << " " << s.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 32;i++) 
	cout << s.pop() << " " << s.Max() << endl;
    maxStack1 st;
    cout << "maxStack1:" << endl;
    for(int i = 0;i < 32;i++) {
	int res = rand()%100;
	st.push(res);
	cout << res << " " << st.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 32;i++) 
	cout << st.pop() << " " << st.Max() << endl;
    maxStack2 stt;
    cout << "maxStack2:" << endl;
    for(int i = 0;i < 32;i++) {
	int res = rand()%100;
	stt.push(res);
	cout << res << " " << stt.Max() << endl;
    }
    cout << endl;
    for(int i = 0;i < 32;i++)
	cout << stt.pop() << " " << stt.Max() << endl;
    return 0;
}
