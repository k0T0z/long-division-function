#include <stdio.h>
using namespace std;
int long_division() {
    printf("\n  Author: Saif Salah El-deen Yahya\n"
           "\n  ID: 1901529\n"
           "\n  Section: 7\n"
           "\n  Department: General Electrical Engineering\n"
           "\n  CSE131 Project - Long Division for Polynomials Function\n");
    printf("\n                ************************  READ CAREFULLY ************************  \n\n"
           " --->  Polynomial Equations are Only Allowed To Be Entered in The Following Format  <---\n"
           "Enter Coefficient of Used Variable (Usually 'x') Followed Directly By the Power of That Variable Inside"
           " Parentheses\nFor Example:\n --->  5x^(2) - 7x^(1) + 3x^(Zero) Written as: 5(2) -7(1) 3(0)\n"
           " --->  x^(2) - x^(Zero) Written as: 1(2) -1(0)\n"
           "IMPORTANT NOTES:\n * First Example has 3 Terms While Second Example has 2 Terms and so on ... .\n"
           " * Spaces Between terms MUST Be Used. Example: 5(2)-7(1)3(Zero) Won't Be Recognised.\n"
           " * Order of Terms Doesn't Matter. Example: -7(1) 3(Zero) 5(2) is Allowed.\n");
    int degree,number_of_terms = 0,q;
    do {
        printf("\nDegree of Dividend (Numerator): ");
        scanf(" %d",&degree);
        if (degree < 0)
            printf("\n            --->  error  <---  \n"
                   "\n  --->  invalid degree, try again  <---  \n");
    } while (degree < 0);
    q = degree;
    do {
        printf("\nNumber of terms of Dividend (Numerator): ");
        scanf(" %d",&number_of_terms);
        if (number_of_terms < 0)
            printf("\n                --->  error  <---  \n"
                   "\n  --->  invalid number of terms, try again  <---  \n");
    } while (number_of_terms < 0);
    if (number_of_terms > (degree+1)) {
        printf("\n             --->  error  <---  \n"
               "\n  --->  number of terms is too large  <---  \n");
        return -4;
    }
    double dividend_coefficients[degree+1];
    for (int i = 0 ; i < degree+1 ; i++)
        dividend_coefficients[i] = 0;
    printf("\nDividend (Numerator) Polynomial: ");
    for (int i = 0 ; i < number_of_terms ; i++) {
        double x=0;int y=-1;
        scanf("%lf(%d)",&x,&y);
        if (y > degree || y < 0) {
            printf("\n                                        --->  error  <---  \n"
                   "\n  --->  'maximum degree exceeded'  OR  'index error'  OR  'not enough number of terms'  <---  \n");
            return -2;
        }
        if (x == 0) {
            printf("\n             --->  error  <---  \n"
                   "\n  --->  coefficient cannot be zero  <---  \n");
            return -5;
        }
        if (dividend_coefficients[y] != 0) {
            printf("\n                  --->  error  <---  \n"
                   "\n  --->  double coefficients of x^(%d) exists  <---  \n",y);
            return -3;
        }
        dividend_coefficients[y] = x;
    }
    do {
        printf("\nDegree of Divisor (Denominator): ");
        scanf(" %d",&degree);
        if (degree < 0)
            printf("\n            --->  error  <---  \n"
                   "\n  --->  invalid degree, try again  <---  \n");
    } while (degree < 0);
    if (degree > q) {
        printf("\n     --->  degree of numerator less than that of denominator  <---  \n"
               "\n  --->  Dividend (numerator) / Divisor (denominator) = Remainder <---  \n");
        return -1;
    }
    do {
        printf("\nNumber of terms of Divisor (Denominator): ");
        scanf(" %d",&number_of_terms);
        if (number_of_terms < 0)
            printf("\n                --->  error  <---  \n"
                   "\n  --->  invalid number of terms, try again  <---  \n");
    } while (number_of_terms < 0);
    if (number_of_terms > (degree+1)) {
        printf("\n             --->  error  <---  \n"
               "\n  --->  number of terms is too large  <---  \n");
        return -4;
    }
    double divisor_coefficients[degree+1];
    for (int i = 0 ; i < degree+1 ; i++)
        divisor_coefficients[i] = 0;
    printf("\nDivisor (Denominator) Polynomial: ");
    for (int i = 0 ; i < number_of_terms ; i++) {
        double x=0;int y=-1;
        scanf("%lf(%d)",&x,&y);
        if (y > degree || y < 0) {
            printf("\n                                        --->  error  <---  \n"
                   "\n  --->  'maximum degree exceeded'  OR  'index error'  OR  'not enough number of terms'  <---  \n");
            return -2;
        }
        if (x == 0) {
            printf("\n             --->  error  <---  \n"
                   "\n  --->  coefficient cannot be zero  <---  \n");
            return -5;
        }
        if (divisor_coefficients[y] != 0) {
            printf("\n                  --->  error  <---  \n"
                   "\n  --->  double coefficients of x^(%d) exists  <---  \n",y);
            return -3;
        }
        divisor_coefficients[y] = x;
    }
    double results[q+1];
    for (int i = 0 ; i < q+1 ; i++)
        results[i] = 0;

    for (int i = q,j = degree ; i >= j ; i--) {
        if (dividend_coefficients[i] == 0)
            continue;
        double helper[q+1];
        for (int k = 0 ; k < q+1 ; k++) {
            helper[k] = 0;
        }
        results[i-j] = dividend_coefficients[i] / divisor_coefficients[j];
        for (int p = 0 ; p < degree+1 ; p++) {
            if (divisor_coefficients[j-p] == 0)
                continue;
            helper[i-p] = results[i-j] * divisor_coefficients[j-p];
        }
        for (int y = 0 ; y < q+1 ; y++) {
            dividend_coefficients[i-y] -= helper[i-y];
        }
    }
    printf("\n\nLong Division Result: ");
    for (int i = 0 ; i < q+1 ; i++) {
        if (results[q-i] == 0)
            continue;
        printf("%0.1lf(%d) ",results[q-i],q-i);
    }
    if (dividend_coefficients[0] == 0)
        printf("\n");
    for (int i = 0 ; i < q+1 ; i++) {
        if (dividend_coefficients[i] != 0) {
            printf("( ");
            for (int s = 0 ; s < q+1 ; s++) {
                if (dividend_coefficients[q-s] == 0)
                    continue;
                printf("%0.1lf(%d) ",dividend_coefficients[q-s],q-s);
            }
            printf("/ ( ");
            for (int s = 0 ; s < degree+1 ; s++) {
                if (divisor_coefficients[degree-s] == 0)
                    continue;
                printf("%0.1lf(%d) ",divisor_coefficients[degree-s],degree-s);
            }
            printf(") )\n");
            break;
        }
    }
}
int main() {
    long_division();
    return 0;
}