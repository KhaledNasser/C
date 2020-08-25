/*
        Author: Ever_last.
        Date: 24/8/2019.

                                Implementation of stack using Array

        this code have 9 function of full usage of stack

        Array limit is  0-MAX   change max if you got error of size

        replace sum function with yours to be implemented on each element of the stack
        notice : travers function start with top element
*/


#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef  int data_stack;                        //this to let user define the data type of stack

typedef struct stack {                          //create struct containing top which define th number and the top element
    data_stack entry[max];                      // entry array to hold data of stack
    int top;

}stack;
//**********************************************************
//******************initialization of stack*****************
void Init_stack(stack *sptr){
    sptr->top=0;
}
//**********************************************************
//**********************Push data to stack******************
int Push(data_stack e,stack *sptr){             //pushing is done by insert element to array and increase top by one
    if (sptr->top!=max){
        sptr->entry[sptr->top]=e;               //function return 1 in case of push happen without problem, and 0 in case of any error
        (sptr->top)++;
        return 1;
    }
    else{
       return 0;
    }
}
//**********************************************************
//*********************Full to check size of stack**********
int IsFull(stack *sptr){                          //full return 1 in case of not reach the maximum size of the stack
     if (sptr->top!=max)
        return 0;
     else
        return 1;
}
//**********************************************************
//******************Pop the data of top*********************
int Pop(stack *sptr){
    int dommy;                                    //delete the data of the first element by decrease the value of the top
    if(sptr->top !=0){
        dommy= sptr->entry[--(sptr->top)];          // the data is not lost but it is not considered
        return dommy;
    }
    else{
        return 0;
    }
}
//**********************************************************
//******************check stack if empty********************
int IsEmpty(stack *sptr){                       // if top equal zero then stack is like initialization
    return(sptr->top==0);                       //return 1 in case of empty
}
//**********************************************************
//*******************read data of top***********************
int Read(stack *sptr){                          //As top is the size of the stack and array index is starting of 0
    return (sptr->entry[(sptr->top)-1]);        //so here we print the value of (top-1)
}
//**********************************************************
//*******************clear data of stack********************
void Clear(stack *sptr){                        //clearing data is same as pop
    sptr->top=0;                                //we update the value of top ,but here we updated to be as initialization top=0
}
//**********************************************************
//**********************size of struct**********************
int Size( stack *sptr){
    return sptr->top;
}
//**********************************************************
//***************travers let user define his own function***
int travers( stack *sptr, void (*fptr)(data_stack e)){
    int i;                                        //here we just give the user the accessibility of each element of stack
    for((i=(sptr->top-1));i>=0;i--){              //this let user make his own function to be performed at each element
        (*fptr)(sptr->entry[i]);
    }
}
//**********************************************************
//*********************user function************************
void sum(data_stack e){                             // here replace sum with fun of yours
    static int sum1 = 0;
    sum1+=e;
    printf("fun %d\n",sum1);
}
//**********************************************************
int main()
{
    stack s;
    int pushed_num,data,dommy;
    printf("Welcome to Stack implementation by array:\n");
    while(data != 0){
        printf("choose operation:\n(1)Initialization.\n(2)Push.\n(3)Pop.\n(4)Read_data_top.\n");
        printf("(5)Clear.\n(6)IsEmpty.\n(7)IsFull.\n(8)Size.\n(9)Travers.\n");
        scanf("%d",&data);
        if(data ==1){
            Init_stack(&s);
        }
        else if (data ==2){
            printf("Enter data to pushed:\n");
            scanf("%d",&pushed_num);
            if(Push(pushed_num,&s)==1){
                printf("Done push\n");
            }
            else{
                printf("Error push");
            }
        }
        else if(data ==3){
            dommy=Pop(&s);
            if(dommy != 0){
                printf("%d Pop\n",dommy);
            }
            else{
                printf("Error Pop\n");
            }
        }
        else if (data ==4){
            printf("%d Read\n",Read(&s));
        }
        else if(data ==5){
            Clear(&s);
        }
        else if(data ==6){
            printf("%d empty\n",IsEmpty(&s));
        }
        else if(data ==7){
            printf("%d Full\n",IsFull(&s));
        }
        else if (data == 8){
            printf(" size %d \n",Size(&s));
        }
        else if (data == 9){
            travers(&s,&sum);
        }
        else{
            printf("Try choose one of this numbers 1-9\n");

        }
    }
    return 0;
}
