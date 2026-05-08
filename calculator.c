#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double a, b, result;

    printf("=== Scientific Calculator ===\n");

    while (1) {
        printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n");
        printf("5.Power\n6.Square Root\n7.Sin\n8.Cos\n9.Log\n0.Exit\n");

        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Calculator Closed.\n");
            break;
        }

        switch (choice) {

        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a + b;
            printf("Result = %.2lf\n", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a - b;
            printf("Result = %.2lf\n", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            result = a * b;
            printf("Result = %.2lf\n", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);

            if (b != 0)
                printf("Result = %.2lf\n", a / b);
            else
                printf("Cannot divide by zero!\n");

            break;

        case 5:
            printf("Enter base and power: ");
            scanf("%lf %lf", &a, &b);
            result = pow(a, b);
            printf("Result = %.2lf\n", result);
            break;

        case 6:
            printf("Enter number: ");
            scanf("%lf", &a);
            result = sqrt(a);
            printf("Result = %.2lf\n", result);
            break;

        case 7:
            printf("Enter angle in radians: ");
            scanf("%lf", &a);
            result = sin(a);
            printf("Result = %.2lf\n", result);
            break;

        case 8:
            printf("Enter angle in radians: ");
            scanf("%lf", &a);
            result = cos(a);
            printf("Result = %.2lf\n", result);
            break;

        case 9:
            printf("Enter number: ");
            scanf("%lf", &a);
            result = log(a);
            printf("Result = %.2lf\n", result);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}