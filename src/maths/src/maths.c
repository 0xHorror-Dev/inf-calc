#include <maths/maths.h>
#include <stdio.h>

static inline double abs(double a)
{
    // sign bit is zero
    unsigned long long mask = 0x7FFFFFFFFFFFFFFF;

    unsigned long long* pa = (unsigned long long*) & a;
    *pa &= mask;
    return a;
}

// summate a and b
extern double sum(double a, double b)
{
    return a+b;
}

// substract a and b
extern double sub(double a, double b)
{
    return a-b;
}

// mulityply a and b
extern double mul(double a, double b)
{
    return a*b;
}

// divide a and b
extern double div(double a, double b)
{
    return a/b;
}

// divide reminder a and b
extern double fmod(double a, double b)
{
    if (b == 0.0) 
    {
        fprintf(stderr, "divider is zero!");
        exit(-1);
    }

    return a - (long long)(a / b) * b;
}

extern unsigned long long factorial(unsigned long long a)
{
    long long res = 1;
    for (long long i = a; i > 0; i -= 1)
    {
        res *= a;
    }
    return res;
}

extern double sqrt(double a)
{
    // here i am using newton method which, approximates the value at each iteration
    double guess = a;
    double epsilon = 1e-7; // accuracy

    /*
    * guess * guess, it is approximates to x^2  
    * - x, i
    */
    while (abs(guess * guess - a) > epsilon)
    {
        guess = (guess + a / guess) / 2.0;
    }

    return guess;
}

extern long long pow(double a, unsigned long long n)
{
    if (a == 0) return 0;
    double result = 1;
    while (n > 0) {
        if (n % 2 != 0)
            result *= a;
        a *= a;
        n /= 2;
    }
    return result;
}

extern double sqrtn(double a, unsigned long long n)
{
    double low = 0, high = a, epsilon = 1e-7;
    
    if (a == 0) return 0;
    else if ((a < 0 && n % 2 == 0))
    {
        fprintf(stderr, "There is no even root of a negative number.");
        exit(-1);
    }
    else if (a < 0) 
    {
        low = a; 
        high = 0;
    }else {
        low = 0;
        high = a > 1 ? a : 1;
    }

    // using binary search 
    while (high - low > epsilon) {
        double mid = low + (high - low) / 2;
        double mid_pow = pow(mid, n);

        if (mid_pow < a)
            low = mid;  // changing lower border
        else
            high = mid; // changing higher border
    }

    return (low + high) / 2;
}

extern double GCD(double a, double b)
{
    while (b != 0) 
    {
        long long temp = b;
        b =  fmod(a,b);
        a = temp;
    }
    return a;
}

extern double log(double a, double n)
{
    if (a <= 0 || n <= 0 || n == 1)
    {
        fprintf(stderr, "incorrect input log%lf (%lf)", a, n);
        exit(-1);
    }
    return ln(a) / ln(n);
}

extern double log2(double a)
{
    return ln(a) / ln(2);
}

extern double ln(double a)
{
    if (a <= 0) return -1;
    double result = 0.0;
    double term = (a - 1) / (a + 1);
    double term_squared = term * term;
    double current_term = term;

    for (unsigned int n = 1; n < 1000000; n += 2) 
    {
        result += current_term / n;
        current_term *= term_squared; // Move to the next member of the row
    }

    return 2 * result; // return 2 * ln((x - 1) / (x + 1))
}

extern long long euler(long long a)
{
    long long result = a ;
    for (unsigned long long p = 2; p * p <= a; ++p) 
    {
        if (a % p == 0) {
            while (a % p == 0)
                a /= p;
            result -= result / p;
        }
    }
    // Если n имеет простой делитель больше sqrt(n)
    if (a > 1)
        result -= result / a;
    return result;
}
