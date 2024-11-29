#include<iostream>
class NumberTheroy {
private:
    const long long mod1 = 1e9+7;
    const long long mod2 = 998244353;

    const long long mod = mod1;
public:
    inline long long add(const long long &a, const long long &b) {
        return (a+b) % mod;
    }

    inline long long mul(const long long &a, const long long &b) {
        return a*b%mod;
    }

    inline long long mul(const long long &a, const long long &b, const long long &c) {
        return mul(mul(a, b), c);
    }

    inline long long qpow(long long a, long long b) {
        long long ret = 1;
        while(b) {
            if(a&1) ret = mul(ret, a);
            a = mul(a, a);
            b>>=1;
        }
        return ret;
    }

private:
    const static int _upper = 1e6;
    long long fac[_upper+10];
    long long fac_inv[_upper+10];
    long long inv[_upper+10];

public:
    // 如果不需要组合数，就不需要初始化
    void init() {
        fac[0] = 1;
        for(int i = 1;i<=_upper;i++) fac[i] = mul(fac[i-1], i);
        fac_inv[_upper] = qpow(fac[_upper], mod-2);
        for(int i = _upper-1;i>=0;i--) {
            fac_inv[i] = mul(fac_inv[i+1], i+1);
            inv[i+1] = mul(fac_inv[i+1], fac[i]);
        }
    }
    long long C(long long a, long long b) {
        if(a<b) {
            std::cout<<"[number_theory] 1. invalid request"<<std::endl;
            exit(1);
        }
        if(a>_upper) {
            std::cout<<"[number_theory] 2. invalid number range"<<std::endl;
            exit(2);
        }
        return mul(fac[a], fac_inv[b], fac_inv[a-b]);
    }
};

NumberTheroy nt;