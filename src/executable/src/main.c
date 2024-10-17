#include <maths/maths.h>
#include <stdint.h>
#include <stdio.h>

void proceed_input();

#define DEFAULT_BINARY_OPERATION_OUTPUT_FMT "%lf %c %lf = %lf\n"
#define DEFAULT_BINARY_OPERATION_INPUT_FMT " %lf %lf"

int main()
{
    proceed_input();
    return 0;
}

void proceed_input()
{
    double a = 0, b = 0, res = 0;
    char c = 0;
    for (;;)
    {
        // %f %f 
        int sres = scanf_s(" %c", &c, 1);
        if (sres != 1)
        {
            fprintf(stderr, "failed to read values from console input!");
            continue;
        }
        switch (c)
        {
        case '*':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, mul(a, b));
            break;
        case '/':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, div(a, b));
            break;
        case '%':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, divr(a, b));
            break;
        case '+':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, sum(a, b));
            break;
        case '-':
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, sub(a, b));
            break;
        case '^':
        {
            sres = scanf_s(DEFAULT_BINARY_OPERATION_INPUT_FMT, &a, &b);
            if (sres != 2)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
            }
            printf(DEFAULT_BINARY_OPERATION_OUTPUT_FMT, a, c, b, pow(a,b));
        }
        case 'd': 
        {
            sres = scanf_s(" %lf", &a);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input!");
                continue;
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
                continue;
            }
            printf("sqrt^%lf(%lf) = %lf\n", b, a, sqrtn(a,b));
        }
        break;
        case '!':
        {
            unsigned long long fa = 0;
            sres = scanf_s(" %llu", &fa);
            if (sres != 1)
            {
                fprintf(stderr, "failed to read values from console input or value is real number!");
                continue;
            }
            printf("%llu\n", factorial(fa));
        }
            break;
        default:
            fprintf(stderr, "unknown operation!");
            break;
        }
    }
}