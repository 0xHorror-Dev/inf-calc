#ifndef _INF_CALC_MATHS_H_
#define _INF_CALC_MATHS_H_

// summate a and b
extern double sum(double a, double b);
// substract a and b
extern double sub(double a, double b);
// mulityply a and b
extern double mul(double a, double b);
// divide a and b
extern double div(double a, double b);
// divide reminder a and b
extern double divr(double a, double b);
extern unsigned long long factorial(unsigned long long a);

extern double pow(double a, unsigned long long n);

extern double sqrt(double a);
extern double sqrtn(double n, unsigned long long a);

extern double GCD(double a, double b);

extern double log(double a, double n);
extern double log2(double a);
extern double ln(double a);

extern long long euler(long long x);

#endif
