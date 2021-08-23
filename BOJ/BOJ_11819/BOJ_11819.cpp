#include <cstdio> 
using ull = unsigned long long; 

ull A, B, C; 
ull mul(ull a, ull b) 
{ 
    ull sum = 0; 
    while (a > 0) 
    { 
        if (a & 1) sum += b, sum %= C; 
        a >>= 1, a %= C; 
        b <<= 1, b %= C; 
    } 
    return sum % C; 
} 

ull pow(ull base, ull exp) { 
    if (base == 1) 
        return 1; 
    ull ans = 1; 
    while (exp) { 
        if (exp & 1) 
        { 
            ans = mul(ans, base), 
            ans %= C; 
        } 
        base = mul(base, base), base %= C; 
        exp >>= 1, exp % C; 
    } 
    return ans % C; 
} 

int main() 
{ 
    scanf("%lld %lld %lld", &A, &B, &C); 
    printf("%lld\n", pow(A, B) % C); 
    return 0; 
}
