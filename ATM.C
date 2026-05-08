#include<stdio.h>
int main ()
{
    double amount = 2000.00, withdraw, deposit; 
    int choich, pin, i;

    while(pin != 12345){
        printf("Enter your pin\n");
        scanf("%d",&pin);

        if(pin!=12345){
            printf("PIN is incorrect!\n");
        }
    }while(1){
        printf("\n..... WELCOME TO THE ATM.....\n");
        printf("1.Check the balance\n");
        printf("2.whitheaw\n");
        printf("3.deposite\n");
        printf("4.Next\n");

        printf("Enter the choich ");
        scanf("%d",&choich);

        switch (choich)
        {
        case 1:
            printf("Your balance is %lf\n",amount);
            break;
        
        case 2:
            printf("PLEASE enter your value: ");
        scanf("%2lf",&withdraw);

        amount = amount - withdraw;

        if(amount <= 500){
            printf("withdraw is not possible");
        }else{
            printf("This is you cash. Thank you");
        }
        break;

        case 3:
            printf("Enter the amount to deposite:");
            scanf("%2lf",&deposit);

            amount = amount + deposit;

            break;
        case 4:
            printf("Thank you for using our ATM");

            break;
        
        default:
            printf("INVALID CHOICH !"); 
        }
        i=1;
    }while(!i);
        printf("Thank you so much\n");
    return 0;
}