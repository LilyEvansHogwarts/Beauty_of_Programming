#include "../head/show.h"

int fib1(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib1(n-1)+fib1(n-2);
}

int fib2(int n,vector<int>& res) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    res[n] = res[n]?res[n]:(fib2(n-1,res)+fib2(n-2,res));
    return res[n];
}

float pow(float a,int n) {
    float count = 1;
    while(n--) count *= a;
    return count;
}

int fib3(int n) {
    float num = 2.23606798;
    return num/5*(pow((1+num)/2,n) - pow((1-num)/2,n));
}

struct matrix1 {
    int a;
    int b;
    matrix1(int x,int y):a(x),b(y) {}
};

struct matrix2 {
    int a00,a01,a10,a11;
    matrix2(int x1,int x2,int x3,int x4):a00(x1),a01(x2),a10(x3),a11(x4) {}
};

void show(matrix1 F) {
    cout << F.a << "\t" << F.b << endl;
}

void show(matrix2 F) {
    cout << F.a00 << "\t" << F.a01 << endl;
    cout << F.a10 << "\t" << F.a11 << endl;
}

matrix1 mul(matrix1 F1,matrix2 F2) {
    int aa = F1.a*F2.a00 + F1.b*F2.a10;
    int bb = F1.a*F2.a01 + F1.b*F2.a11;
    F1.a = aa;
    F1.b = bb;
    return F1;
}

matrix2 mul(matrix2 F1,matrix2 F2) {
    int a00,a01,a10,a11;
    a00 = F1.a00*F2.a00 + F1.a01*F2.a10;
    a01 = F1.a00*F2.a01 + F1.a01*F2.a11;
    a10 = F1.a10*F2.a00 + F1.a11*F2.a10;
    a11 = F1.a10*F2.a01 + F1.a11*F2.a11;
    F1.a00 = a00;
    F1.a01 = a01;
    F1.a10 = a10;
    F1.a11 = a11;
    return F1;
}

matrix2 pow(matrix2 F,int n) {
    matrix2 count(1,0,0,1);
    while(n--) count = mul(count,F);
    return count;
}

int fib4(int n) {
    matrix1 p(1,0);
    matrix2 q(1,1,1,0);
    matrix1 res = mul(p,pow(q,n-1));
    return res.a;
}

int main() {
    int n = 40;
    int start = clock();
    cout << fib1(n) << endl;
    cout << clock()-start << endl;
    vector<int> res(n+1,0);
    res[1] = 1;
    start = clock();
    cout << fib2(n,res) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << fib3(n) << endl;
    cout << clock()-start << endl;
    start = clock();
    cout << fib4(n) << endl;
    cout << clock()-start << endl;
    return 0;
}

