#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int checkEmpty()
{
   if (top == -1)
      return 1;
   else
      return 0;
}

int checkFull()
{
   if (top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek()
{
   return stack[top];
}

int pop()
{
   int data;

   if (!checkEmpty()){
      data = stack[top];
      top = top - 1;
      return data;
   }
   else{
      printf("stack empty.\n");
   }
}

int push(int data)
{
   if (!checkFull()){
      top = top + 1;
      stack[top] = data;
   }
   else{
      printf("Stack full\n");
   }
}

int main()
{
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Top of the stack: %d\n", peek());
   printf("value: \n");

   while (!checkEmpty()){
      int data = pop();
      printf("%d\n", data);
   }

   printf("Stack full: %s\n", checkFull() ? "true" : "false");
   printf("Stack empty: %s\n", checkEmpty() ? "true" : "false");

   return 0;
}