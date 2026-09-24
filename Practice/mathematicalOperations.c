/*
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <errno.h>


double firstEquationCalc(double);
double secEquationCalc(double);

int main(void) {
    double x = 3.3;
    while (1) {
        double const first_equation = firstEquationCalc(x);
        double const sec_equation = secEquationCalc(x);
        printf("First Equation result --> %.5lf\n", first_equation);
        printf("Second Equation result --> %.5lf\n", sec_equation);

        if (first_equation == EDOM || sec_equation == EDOM)
            printf("Calculation failed, the error message is --> %s\n", strerror(EDOM));

        printf("\nInsert the value to calculate by equations -->  ");

        if (scanf("%lf", &x) != 1) {
            printf("Invalid input.\n");
            break;
        }
    }
    return 0;
}

double firstEquationCalc(double x) {
    double root = x * x - 9;
    if (root < 0.0) return EDOM;
    double const numerator = (x * x) + 2 * x - 3 + (x + 1) * sqrt(root);
    double const denominator = (x * x) - 2 * x - 3 + (x - 1) * sqrt(root);
    return denominator == 0.0 ? EDOM : numerator / denominator;
}

double secEquationCalc(double x) {
    double const root = (x + 3) / (x - 3);
    if (root < 0.0) return EDOM;
    return (x - 3) == 0.0 ? EDOM : sqrt((x + 3) / (x - 3));
}
*/

