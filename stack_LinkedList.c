/*
        Author: Ever_last.
        Date: 24/8/2019.

                                Implementation of stack using Linked_list

        this code have 8 function of full usage of stack

        Linked_list is not limited of size,that you can add Node as you wish the only Error
        will happen if you reach the end of memory of you computer(low memory fragmentation)

        replace sum function with yours to be implemented on each element of the stack
        notice : travers function start with top element(head)
*/


#include <stdio.h>
#include <stdlib.h>

typedef int Data_in;

typedef struct Node{
    int data;
    struct Node *Next;
}Node;

typedef struct Head{
    int size;
    struct Head * Top;
}Head;
//**********************************************************
//******************initialization of stack*****************
void Init_stack(Head *sptr){
    sptr->Top= NULL;
    sptr->size=0;
}
//**********************************************************
//**********************Push data to stack******************
int Push(Data_in e,Head *sptr){
    Node *temp= ( Node*)malloc(sizeof( Node*));
    temp->data=e;
    temp->Next=sptr->Top;
    sptr->Top=temp;
    sptr->size++;
    return 1;
}
//**********************************************************
//******************Pop the data of top*********************
int Pop(Head *sptr){
    Node *temp=( Node*)malloc(sizeof( Node *));
    int dommy;
    if(sptr->Top != NULL){
        dommy=sptr->Top->size;
        temp=sptr;
        sptr->size--;
        sptr->Top=sptr->Top->Top;


        free(temp);

        return dommy;
    }
    else{
        printf("Error:Empty stack\n");

        return -1;
    }




}
//**********************************************************
//*******************read data of top***********************
int Read(Head *sptr){
    return sptr->Top->size;
}
//**********************************************************
//**********************size of struct**********************
int Size(Head *sptr){
    return sptr->size;
}
//**********************************************************
//******************check stack if empty********************
int IsEmpty(Head * sptr){
    if(sptr->Top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//**********************************************************
//*******************clear data of stack********************
void Clear(Head * sptr){
    while(sptr->size!=0)
    {
        Pop(sptr);
    }
}
int main()
{
    Node s;
    int pushed_num,data,dommy;
    printf("Welcome to Stack implementation by Linked_list:\n");
    while(data != 0){
        printf("choose operation:\n(1)Initialization.\n(2)Push.\n(3)Pop.\n(4)Read_data_top.\n");
        printf("(5)Clear.\n(6)IsEmpty.\n(7)Size.\n(8)Travers.\n");
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
            if(dommy != -1){
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
           printf(" size %d \n",Size(&s));
        }
        else if (data == 8){
               // travers(&s,&sum);
        }
        else{
            printf("Try choose one of this numbers 1-9\n");

        }
    }

    return 0;
}
