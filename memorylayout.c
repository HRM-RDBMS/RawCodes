/*print out the mormory locations of BSS, Stack, Variable on stack, Heap and etc
Name:Disha Bundela
Reg No:1947211
Date:1/9/2020
*/
#include <stdio.h>

//GLOBAL VARIABLES            //All global variable gets stored in the data segment
const float pi=3.14;         //It will be stored in read only block of initialized data segment
int factorial_no=6;          //Initialized data segment    



int factorial(int n)              //Arguments passed to the function used to store in stack segment
{
	 static int fact=1;            //Initialized local static variable will be stored in the initialized data segment
     int i;                        //local variable of function will be stored in stack segment
	 if (n < 0)
     {
        printf("Error! Factorial of a negative number doesn't exist.");             //Code segment
     }
     else
     {
        for (i = 1; i <= n; ++i) 
        {
            fact *= i;
        }
    }
    return fact;                  //Return addresses are always stored in the stack segment
}

int main()
{
    char *pStr = malloc(sizeof(char)*4);              //heap will manage memory management functions like malloc, calloc and free
    
    int n = 10;                    //local variable of function will be stored in stack segment
    int ans;                       //local variable of function will be stored in stack segment
    ans=factorial(n);
   
 	printf("\nAddress of variables in Stack \n");
    printf("\n n    : %p", &n);   
    printf("\n ans    : %p", &ans);   
    
    printf("\nAddress of variables in heap \n");
    printf("\n pStr    : %p", &pStr);   
    
    
	return 0;
}
