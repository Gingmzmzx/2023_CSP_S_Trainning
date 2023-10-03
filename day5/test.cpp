#include <bits/stdc++.h>
using namespace std;

// 快速读取
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

// 随机数生成
class Random{
    public:
        int rand(int l, int r){
            return l + rand() % (r - l + 1);
        }
        int rand(int r){
            return rand(0, r);
        }
        int rand(){
            return rand(0x7fffffff);
        }
        void set_seed(int seed){
            srand(seed);
        }
        void set_seed(){
            srand(time(0));
        }
};

// 不使用加减乘除符号实现加减乘除运算
class Math{
    public:
        int add(int a, int b){
            int sum = 0, carry = 0;
            do{
                sum = a ^ b;
                carry = (a & b) << 1;
                a = sum;
                b = carry;
            }while(b != 0);
            return a;
        }
        int sub(int a, int b){
            return add(a, add(~b, 1));
        }
        int mul(int a, int b){
            int sum = 0;
            while(b != 0){
                if(b & 1){
                    sum = add(sum, a);
                }
                a <<= 1;
                b >>= 1;
            }
            return sum;
        }
        int div(int a, int b){
            int sum = 0;
            while(a >= b){
                a = sub(a, b);
                sum = add(sum, 1);
            }
            return sum;
        }
};
    
int main(){
    Math math;
    Random random;
    random.set_seed();
    cout << random.rand() <<endl;
    cout << math.add(random.rand(0, 100), random.rand(0, 100)) << endl;
    cout << math.sub(random.rand(0, 100), random.rand(0, 100)) << endl;
    cout << math.mul(random.rand(0, 100), random.rand(0, 100)) << endl;
    cout << math.div(random.rand(0, 100), random.rand(0, 100)) << endl;

    return 0;
}