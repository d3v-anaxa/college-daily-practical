#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void menu(); // prototype declaration

int main()
{
  float operand1, operand2;
  int operator;
  char choice;

  do
  {
    menu();
    printf("Enter Choice [1-5] : ");
    scanf("%d", &operator);
    if (operator> 5 || operator<1)
    {
      printf("INVALID CHOICE\n");
    }
    else
    {
      printf("Enter first operand : ");
      scanf("%f", &operand1);
      printf("Enter second operand : ");
      scanf("%f", &operand2);

      switch (operator)
      {
      case 1:
        printf("%.2f + %.2f = %.2f\n", operand1, operand2, operand1 + operand2);
        break;
      case 2:
        printf("%.2f - %.2f = %.2f\n", operand1, operand2, operand1 - operand2);
        break;
      case 3:
        printf("%.2f * %.2f = %.2f\n", operand1, operand2, operand1 * operand2);
        break;
      case 4:
        printf("%.2f / %.2f = %.2f\n", operand1, operand2, operand1 / operand2);
        break;
      case 5:
        printf("[PROGRAM CLOSED]\n");
        exit(EXIT_SUCCESS);
        break;
      }
    }
    printf("You still want to continue? [y/n] : \n");
    choice = getchar();
  } while ((choice = getchar()) == 'y');
  printf("[PROGRAM EXITED]\n");
}

void menu()
{
  printf("+-CALCULATOR----------->\n");
  printf("| 1. ADDITION\n");
  printf("| 2. SUBTRACTION\n");
  printf("| 3. MULTIPLICATION\n");
  printf("| 4. DIVISION\n");
  printf("| 5. EXIT\n");
  printf("+--------------------->\n");
}
