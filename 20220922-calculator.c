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
    printf("Enter first operand : ");
    scanf("%f", &operand1);
    printf("Enter second operand : ");
    scanf("%f", &operand2);

    switch (operator)
    {
    case 1:
      printf("%f + %f = %f\n", operand1, operand2, operand1 + operand2);
      break;
    case 2:
      printf("%f - %f = %f\n", operand1, operand2, operand1 - operand2);
      break;
    case 3:
      printf("%f * %f = %f\n", operand1, operand2, operand1 * operand2);
      break;
    case 4:
      printf("%f / %f = %f\n", operand1, operand2, operand1 / operand2);
      break;
    case 5:
      printf("[PROGRAM CLOSED]\n");
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("Invalid Choice\n");
      main();
      break;
    }
    printf("You still want to continue? [y/n] : \n");
    choice = getchar();
  } while ((choice = getchar()) == 'y');
  printf("Program Exit");
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