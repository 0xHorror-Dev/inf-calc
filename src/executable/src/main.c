#include <maths/maths.h>
#include <stdint.h>
#include <stdio.h>

#define DEFAULT_BINARY_OPERATION_OUTPUT_FMT "%lf %c %lf = %lf\n"
#define DEFAULT_BINARY_OPERATION_INPUT_FMT " %lf %lf"

int main()
{
    double a = 0, b = 0, res = 0;
    char c = 0;
    {
        printf("operations table:\nsum - '+' \t sub - '-'\n"
               "mul - '*' \t div - '/'\n"
               "fmod - '%' \t factorial - '!'\n"
               "sqrt - 'd' \t pow - '^'\n"
               "sqrtn - 's' \t GCD - 'G'\n"
               "log - 'l' \t log2 - '2'\n"
               "ln - 'n' \t euler - 'e'\n"
        );
        printf("enter operation:");
        int sres = scanf_s(" %c", &c, 1);
        if (sres != 1)
        {
            fprintf(stderr, "failed to read values from console input!");
            return -1;
        }
        printf("enter operands:");
        switch (c)
        {
        case '*':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, mul(a, b));
            break;
        case '/':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, div(a, b));
            break;
        case '%':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, fmod(a, b));
            break;
        case '+':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, sum(a, b));
            break;
        case '-':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, sub(a, b));
            break;
        case '^':
        {
            unsigned long long n = 0;
            sres = scanf_s("%lf %llu", &a, &n);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;;
            }
            printf("%lf ^ %llu = %ll", a, n, pow(a, n));
        }
            break;
        case 'd':
        {
            sres = scanf_s(" %lf", &a);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("sqrt(%lf) = %lf\n", a, sqrt(a));
        }
            break;
        case 's':
        {
            sres = scanf_s(" %lf %lf", &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("sqrt^%lf(%lf) = %lf\n", b, a, sqrtn(a, b));
        }
        break;
        case 'G':
        {
            sres = scanf_s(" %lf %lf", &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("GCD(%lf,%lf) = %lf\n", a, b, GCD(a, b));
        }
        break;
        case 'l':
            sres = scanf_s(" %lf %lf", &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("log%lf(%lf) = %lf\n", b, a, log(a, b));
            break;
        case '2':
            sres = scanf_s(" %lf", &a);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("log2(%lf) = %lf\n", a, log2(a));
            break;
        case 'n':
            sres = scanf_s(" %lf", &a);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("ln(%lf) = %lf\n", a, log(a, 10));
            break;
        case 'e':
        {
            unsigned long long n;
            sres = scanf_s(" %llu", &n);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input!");
                return -1;
            }
            printf("euler(%llu) = %llu\n", n, euler(n));
        }
            break;
        case '!':
        {
            unsigned long long fa = 0;
            sres = scanf_s(" %llu", &fa);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input or value is real number!");
                return -1;
            }
            printf("%llu\n", factorial(fa));
        }
        break;
        default:
            fprintf(stderr, "unknown operation!");
            break;
        }
    }
    return 0;
}

