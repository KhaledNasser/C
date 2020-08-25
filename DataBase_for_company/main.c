/* NANOARROW company database
*  AUTHER: Khaled Nasser
* THIS CODE IS NOT COMPLET ,NEED MODIFY FUNCTION
* AND HAVE A PROBLEM THAT HE MAKE AN OPERATION FOR EACH TIME IT OPENS AND CLOSE
* LAST EDIT: 18/8/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>      // for is digit

#include <unistd.h>    //to delete the end of file
#include <sys/types.h>


#define debug 0          // 1 to get in the debug mode


bool check(int i,char check_data[]);
void ADD();
void LOAD(int pointer_c);
void SEARCH(int pointer_c,char wired[50],int wro);
void MODIFY();
void DELET(int pointer_c,int length );



int main()
{
    char data;
    FILE * fp;
/*                       TYRING TO MAKE IT LIKE STRUCT BUT DID NOT WORK

    FILE * file;
    file = fopen("DATABASE.txt","r+");

    char container[500];
    int size=0;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee


    while(!feof(file))
    {
        fgets ( container, 500, file );

        #if debug
            puts(container);
            printf("f1\n");
        #endif                      // debug
        size= strlen(container);
        #if debug
            printf(" %d %d f2\n",size);
        #endif // debug
    }
    fclose(file);
*/
    while(1){                       // this section for user interface
        main1:

        printf("/--------------Welcome to NanoArrow company--------------\\ \nselect your operation than press enter:\n\n");
        printf("h-help.\n\n1-ADD.\n2-LOAD.\n3-SEARCH.\n4-MODIFY.\n5-DELETE.\n6-SAVE.\n7-SORT.\nq-QUIT.\n/------------------------------------------\\ \n\n");

        scanf(" %c",&data);


        if (data == 'q')               // this option is the exit door
        {
            printf("closing program\n");

            break;
        }


        else if(data == 'h'){                                        //help section is for helping go through program
            printf("opening document help\n/*****SOF****\\ \n");     // this option have the all description of the program
            fp = fopen("help.txt","r");
            while(1) {
               char c = fgetc(fp);
                if( feof(fp) ) {
                    break ;
                    }
                printf("%c", c);
                }
                printf("\n/*****EOF****\\ \n\n");
            fclose(fp);
        }


        else{
            switch(data){
                case '1':                       // add function
                    ADD();
                    printf(" /********DONE ADD**********\ \n");
                    #if debug
                    printf("yeeeeeees\n");
                    #endif                      // debug
                    goto main1;
                    break;
                case '2':                       // LOAD function
                    LOAD(0);

                    printf(" /********DONE LOAD**********\ \n");
                    goto main1;
                    break;
                case '3':                       // SEARCH function
                    SEARCH(0,' ',0);
                    printf(" /********DONE SEARCH**********\ \n");
                    goto main1;
                    break;
                 case '4':                      // MODIFY function
                    MODIFY(0,' ',0,0);
                    printf(" /********DONE MODIFY**********\ \n");

                    goto main1;
                    break;
                 case '5':                      // DELETE function
                    DELETE (0,' ',0);
                    printf(" /********DONE DELETE**********\ \n");
                    goto main1;
                    break;
                 case '6':                      // MODIFY function
                    SHIFT(5,11);
                    break;
                 case '7':                      // SORT function
                    DELET(16,11);
                    break;
                 default :                      // invalid char
                    printf("your input is not a valid operation,try to choose a correct operation\n\n");
                    goto main1;
                    break;
            }
        }
    fclose(fp);
    printf("woooo");
    }
 return 0;
}


void ADD ()
{
    char c;

    FILE * fp;
    FILE * fd;
    fp = fopen("DATABASE.txt","a");

    int i,numDigit;
    char add_data[50];

    int num;



    for(i=0;i<5;i++){
        switch(i){
            case 0:                     //name of employee field #1 the max_length of name is 30 char
                alpha:
                printf("NAME alphabets only :");
                scanf(" %s",add_data);

                if(check(i, add_data)){
                    fprintf(fp,"\"");
                    fprintf(fp,"%s",add_data);
                    fprintf(fp,"\,");
                    printf("done_nam\n");
                }
                else{
                    printf("ERROR: write a correct string consist only of alphabets, try again\n");
                    goto alpha;
                }

                break;
            case 1:                     //number of the employee field #2 the max length is size of int
                number:
                printf("NUMBER  ten digit without zero :");
                scanf(" %s",add_data);

                if(check(i, add_data)){
                    fprintf(fp,"%s",add_data);
                    fprintf(fp,"\,");
                    printf("done_num\n");
                }
                else{
                    printf("ERROR: write a correct string consist only of alphabets, try again\n");
                    goto number;
                }
                break;
            case 2:                     //e_mail of employee field #3
                E:
                printf("E_MAIL make sure it is valid mail:");
                scanf(" %s",add_data);

                if(check(i, add_data)){
                    fprintf(fp,"%s",add_data);
                    fprintf(fp,"\,");
                    printf("done_e\n");
                }
                else{printf("ERROR: write a correct string consist only of alphabets");
                    goto E;
                }
                break;
            case 3:                        // DAe of Birth of employee
                B:
                printf("DATE OF BIRTH syntax dd/mm/yyyy:");
                int dd,mm,yyyy;
                scanf("%d/%d/%d",&dd,&mm,&yyyy);

                if (yyyy%4 == 0) {printf("/**********leap year*********\ \n");}

                if(dd<=0 || dd>31){
                        printf("Error:days are not in the limit of month\n");
                        goto B;
                }
                else if( dd==29 && mm !=2){
                        printf("Error:days are not in the limit of month\n");
                        goto B;
                }
                else if(dd==30 &&(mm !=4 || mm !=6 || mm !=9 ||mm !=11 ))
                {
                         printf("Error:days are not in the limit of month\n");
                         goto B;
                }
                else if(dd ==31 &&(mm !=1 || mm!=3 || mm !=5 || mm!=7 || mm !=8 || mm !=10 || mm !=12 ))
                {
                         printf("Error:days are not in the limit of month\n");
                         goto B;
                }
                else{
                        fprintf(fp,"%d/%d/%d",dd,mm,yyyy);
                        fprintf(fp,"\,");
                        printf("done_doB\n");
                }
                break;
            case 4:                         //get job title
                J:
                printf("\nJOB TITLE make sure it listed below: \n\n");

                /*****print the content of the file*****/
                fd = fopen("job_title.txt","r");
                while(1) {
                    c = fgetc(fd);
                    if( feof(fd) ) {
                        break ;
                        }
                    printf("%c", c);
                    }
                printf("\n");
                fclose(fd);
                /**********/

                scanf(" %s",add_data);

                if(check(i, add_data)){
                    fprintf(fp,"%s",add_data);
                    printf("done_jt\n");
                }
                else{
                        printf("\nERROR: your job title is not found in company data base\n");
                        goto J;
                }
                break;
        }
    }
    fprintf(fp,"\"");
    fclose(fp);
}


bool check(int i,char check_data[]){
    int j,alphabet=0,t=0;                         //t is just to fix in the array size problem in job_title
    bool flag=false;

    char container[500];
    int size=0, pointer_c=0,x,y,counter =0,flg;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee

    FILE * fd;
    fd = fopen("job_title.txt","r");

    switch(i){
        case 0:                                 //here we check that names are valid
            for (j=0; check_data[j]!= '\0'; j++)
            {
                // check for alphabets
                if (isalpha(check_data[j]) != 0) {
                    alphabet++;
                }
            }
            if (alphabet == strlen(check_data)) {return true;}
            else {return false;}
            break;

        case 1:                                 //here we check that number are valid
            for (j=0; check_data[j]!= '\0'; j++)
            {
                // check for alphabets
                if (isdigit(check_data[j]) != 0) {
                    alphabet++;
                }
            }
            if (alphabet == strlen(check_data) && alphabet == 11) {return true;}
            else {return false;}
            break;

        case 2:                                 //here we check that e_mails are valid
            for (j=0; check_data[j]!= '\0'; j++)
            {
                if(check_data[j] == '@'){
                        flag=true;
                }
                // check for alphabets
                if ( isdigit(check_data[j]) != 0 && flag == true ) {
                        alphabet++;
                        flag=false;
                }
            }
            if (alphabet) {return false;}
            else {return true;}
            break;
        case 4:


             while(!feof(fd))
            {
                fgets ( container, 500, fd );
                #if debug
                puts(container);
                printf("f1\n");
                #endif                      // debug
                size= strlen(container);
                #if debug
                printf(" %d f2\n",size);
                #endif                      // debug
                x=0;
                pointer_c=0;

                char buffer [500];
                flg=0;
                while (container[pointer_c] != '.'){
                    buffer[x]=container[pointer_c];
                    x++;
                    pointer_c++;
                }
                for(t=0;t<pointer_c;t++)
                {
                    if (buffer[t] == check_data[t])
                    {
                        flg++;
                    }
                    #if debug
                    printf("%d %c %d %c %d fs \n",t,buffer[t],pointer_c,check_data[t],flg);
                    #endif
                }
                if(flg == pointer_c) {
                    flg=0;
                    return true;
                }
            }
            fclose(fd);
            return false;
            break;
    }
}


void LOAD(int pointer_c){
    FILE * fload;
    FILE * fp;

    fp = fopen("DATABASE.txt","a");
    fload = fopen("load.txt","r+");

    char container[500];
    int size=0,x,y,t,c =0,flg;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee


             while(!feof(fload))
            {
                fgets ( container, 500, fload );
                puts(container);
                #if debug
                puts(container);
                printf("f1\n");
                #endif                      // debug
                size= strlen(container);
                #if debug
                printf(" %d %d f2\n",size,pointer_c);
                #endif // debug
                                   // debug
            }
            fclose(fload);
            y=0;
           // while(!feof(fload))
           // {

                char buffer [30];
                #if debug
                printf("g1\n");
                #endif // debug
                flg=0;
                if(container[pointer_c] == '"' || pointer_c>0) {
                    while (container[pointer_c] != '"') pointer_c++;
                    #if debug
                    printf("g2\n");
                    #endif // debug
                    fprintf(fp,"\"");
                    pointer_c++;
                    for(t=0;t<5;t++){
                        if(container[pointer_c] != '"')
                        {
                            x=0;
                            while ((container[pointer_c] != ',' )&& (container[pointer_c] != '"')){
                                if(container[pointer_c] != ' ' ){
                                    buffer[x]=container[pointer_c];
                                    x++;
                                }

                                pointer_c++;
                            }
                            for(c=0;c<x;c++){
                            fprintf(fp,"%c",buffer[c]);
                            printf("%c  fb \n",buffer[c]);
                            }
                            #if debug
                            printf("%s  %d f0\n",buffer,x);
                            #endif // debug
                            if( container[pointer_c] == '"') {fprintf(fp,"\"");}
                            else {fprintf(fp,"\,");}
                            for(c=0;c<x;c++){
                            buffer[c]=' ';
                            }
                            pointer_c++;
                        }
                    }
                    #if debug
                    printf("g3\n");
                    printf("%d  %d f11 \n",pointer_c,size);
                    #endif // debug
                    if(pointer_c <size){
                        LOAD(pointer_c);
                        #if debug
                        printf("g4\n");
                        #endif // debug

                    }
                }
}



void SEARCH(int pointer_c,char wired[50],int wro){
    FILE * fload;
    fload = fopen("DATABASE.txt","r+");

    char container[500];
    int size=0,x,y,t=0,c =0,flg;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee

    int hur;
    char add_data[50];

    if(pointer_c ==0){

        printf("NAME:");
        scanf("%s",add_data);
        if(!check(0,add_data)){
            printf("ERROR: write a correct string consist only of alphabets");
            SEARCH(0,' ',wro);
        }
    }
    else{
        strcpy(add_data,wired);
    }
    #if debug
    printf("f1\n");
    #endif // debug
    while(!feof(fload))
        {
            fgets ( container, 500, fload );
            size= strlen(container);
            #if debug
            printf(" %d %d f2\n",size,pointer_c);
            #endif // debug
        }
    fclose(fload);
    y=0;
    char buffer [30];
    flg=0;
    if(container[pointer_c] == '"' || pointer_c>0) {
        while (container[pointer_c] != '"') pointer_c++;
            #if debug
            printf("f2\n");
            #endif // debug
            pointer_c++;
            hur=0;
            for(t=0;t<5;t++){
                #if debug
                printf("f3\n");
                #endif // debug
                if(container[pointer_c] != '"')
                    {

                        x=0;
                        while ((container[pointer_c] != ',' )&& (container[pointer_c] != '"')){
                            if(container[pointer_c] != ' ' )
                                buffer[x]=container[pointer_c];
                            x++;
                            pointer_c++;
                        }

                        if(t==0){
                        for(y=0;y<strlen(add_data);y++){
                                if(add_data[y]==buffer[y]) flg++;
                                #if debug
                                printf("%c %c %d foo \n",add_data[y],buffer[y],flg);
                                #endif // debug
                        if(flg==strlen(add_data) && x == strlen(add_data)){
                            printf("DATA FOUND: \n");
                            hur=2;}
                        }

                        flg=0;
                        #if debug
                        printf("%s  %d  %s %d %d f0\n",buffer,x,add_data,strlen(add_data),strcmp(add_data,buffer));
                        #endif // debug
                        }
                        else{
                            #if debug
                            printf("i am here but now\n");
                            printf("%d   fr\n",hur );
                            #endif // debug
                            if(hur ==2){
                                    if(t==1){ printf("NUMBER:%s \n",buffer);}
                                    else if (t==2) {printf("E_MAIL:%s \n",buffer);}
                                    else if (t==3) {printf("DATE_OF_BIRTH:%s \n",buffer);}
                                    else{printf("JOB_TITLE:%s \n",buffer);

                                    }
                                //printf("%s   \n",buffer);
                                 wro++;
                            }
                        }
                        for(c=0;c<30;c++){
                            buffer[c]=' ';
                        }

                        pointer_c++;
                    }
                }
                #if debug
                printf("f4 \n");
                printf("%d  %d f11 \n",pointer_c,size);
                #endif // debug
                if(pointer_c <size){
                    SEARCH(pointer_c,add_data,wro);
                    #if debug
                    printf("f5\n");
                    #endif // debug

                }
                if(wro==4 && hur==2) {
                        #if debug
                        printf("/****************SEARCH DONE***************\  \n");
                        #endif
                        wro=0;
                }
        }
}


void MODIFY(int pointer_c,char wired[50],int wro,int num){      //not completed yet
    FILE * fload;

    fload = fopen("DATABASE.txt","r+");


    char container[500];
    int size=0,x,y,t=0,c =0,flg;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee

    int hur;
    char add_data[50];


    char mody[11];

    if(pointer_c ==0){

        printf("NAME:");
        scanf("%s",add_data);
        if(!check(0,add_data)){
            printf("ERROR: write a correct string consist only of alphabets\n");
            MODIFY(0,' ',wro,0);
        }
        printf("choose number of field to modify:\n1-NUMBER\n2-E_MAIL\n3-JOB_TITLE\n");
        scanf(" %d",&num);
        #if debug
        printf("%d f1 \n",num);
        #endif // debug
        if (!(num ==1 ||num ==2 || num ==3)){
            printf("ERROR: not a valid choice\n");
            MODIFY(0,' ',wro,0);
        }
    }
    else{
        strcpy(add_data,wired);
    }
    #if debug
    printf("f1\n");
    printf("%d f6 \n",num);
    #endif // debug
    while(!feof(fload))
        {
            fgets ( container, 500, fload );
            size= strlen(container);
            #if debug
            printf(" %d %d f2\n",size,pointer_c);
            #endif // debug
        }

    y=0;
    char buffer [30];
    flg=0;
    #if debug
    printf("%d f7 \n",num);
    #endif // debug

    if(container[pointer_c] == '"' || pointer_c>0) {
        while (container[pointer_c] != '"') pointer_c++;
            #if debug
            printf("f2\n");
            #endif // debug
            pointer_c++;
            hur=0;
            for(t=0;t<5;t++){
                #if debug
                printf("f3\n");
                #endif // debug
                if(container[pointer_c] != '"')
                    {
                        #if debug
                        printf("%d f8 \n",num);
                        #endif // debug
                        x=0;
                        while ((container[pointer_c] != ',' )&& (container[pointer_c] != '"')){
                            if(container[pointer_c] != ' ' ){
                                buffer[x]=container[pointer_c];
                                x++;
                                }
                            pointer_c++;
                        }

                        if(t==0){
                                #if debug
                                printf("%d f9 \n",num);
                                #endif // debug
                        for(y=0;y<strlen(add_data);y++){
                                if(add_data[y]==buffer[y]) flg++;
                                #if debug
                                printf("%c %c %d foo \n",add_data[y],buffer[y],flg);
                                #endif // debug
                        if(flg==strlen(add_data) && x == strlen(add_data)){
                            printf("DATA FOUND: \n");
                            hur=2;}
                        }

                        flg=0;
                        #if debug
                        printf("%s  %d  %s %d %d f0\n",buffer,x,add_data,strlen(add_data),strcmp(add_data,buffer));
                        #endif // debug
                        }
                        else{
                            #if debug
                            printf("i am here but now\n");
                            printf("%d   fr\n",hur );
                            #endif // debug
                            if(hur ==2){
                                    printf("%d fa \n",num);
                                    if(t==1 && num == 1){
                                            printf("new_number:");
                                            scanf("%s",mody);
                                            printf("%s %d fss\n",mody,pointer_c);
                                            if(check(1,mody)){
                                                fseek(fload, pointer_c-11, SEEK_SET);
                                                for(c=0;c<11;c++){
                                                    fprintf(fload,"%c",mody[c]);
                                                }
                                            }
                                            printf("NUMBER:%s \n",mody);
                                    }
                                    else if (t==2 && num ==2) {
                                            printf("new_email:");
                                            scanf("%s",mody);
                                            printf("%s %d %s %d fss \n",mody,pointer_c,buffer,strlen(buffer));
                                            if(check(2,mody)){
                                                DELET(pointer_c+x,x);
                                                //SHIFT(pointer_c+1,x);
                                                fclose(fload);
                                                puts(container);
                                                fseek(fload,(pointer_c+1)-strlen(buffer), SEEK_SET);
                                                printf("%s %d y1 \n",buffer,x);
                                               // fprintf(fload," %c",mody[0]);
                                            }
                                            printf("E_MAIL:%s \n",mody);
                                    }
                                    else if (t==3) {printf("DATE_OF_BIRTH:%s \n",buffer);}
                                    else{printf("JOB_TITLE:%s \n",buffer);

                                    }
                                //printf("%s   \n",buffer);
                                 wro++;
                            }
                        }
                        for(c=0;c<x;c++){
                            buffer[c]=' ';
                        }

                        pointer_c++;
                    }
                }
                #if debug
                printf("f4 \n");
                printf("%d  %d f11 \n",pointer_c,size);
                #endif // debug
                if(pointer_c <size){
                    MODIFY(pointer_c,add_data,wro,num);
                    #if debug
                    printf("f5\n");
                    #endif // debug

                }
                if(wro==4 && hur==2) {
                        #if debug
                        printf("/****************MODIFY DONE***************\  \n");
                        #endif
                        wro=0;
                }
        }
 fclose(fload);
}

void DELETE (int pointer_c,char wired[50],int wro)
{
    FILE * fload;
    fload = fopen("DATABASE.txt","r+");

    char container[500];
    int size=0,x,m,y,t=0,c =0,flg,acc=0;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee

    int hur;
    char add_data[50];

    if(pointer_c ==0){

        printf("NAME:");
        scanf("%s",add_data);
        if(!check(0,add_data)){
            printf("ERROR: write a correct string consist only of alphabets");
            SEARCH(0,' ',wro);
        }
    }
    else{
        strcpy(add_data,wired);
    }
    #if debug
    printf("f1\n");
    #endif // debug
    while(!feof(fload))
        {
            fgets ( container, 500, fload );
            size= strlen(container);
            #if debug
            printf(" %d %d f2\n",size,pointer_c);
            #endif // debug
        }
    //fclose(fload);
    y=0;
    char buffer [30];
    flg=0;
    if(container[pointer_c] == '"' || pointer_c>0) {
        while (container[pointer_c] != '"') pointer_c++;
            #if debug
            printf("f2\n");
            #endif // debug
            pointer_c++;
            hur=0;
            m=0;
            for(t=0;t<5;t++){
                #if debug
                printf("f3\n");
                #endif // debug
                if(container[pointer_c] != '"')
                    {

                        x=0;
                        while ((container[pointer_c] != ',' )&& (container[pointer_c] != '"')){
                            if(container[pointer_c] != ' ' ){
                                buffer[x]=container[pointer_c];
                                x++;}

                            pointer_c++;
                        }

                        if(t==0){
                        for(y=0;y<strlen(add_data);y++){
                                if(add_data[y]==buffer[y]) flg++;
                                #if debug
                                printf("%c %c %d foo \n",add_data[y],buffer[y],flg);
                                #endif // debug
                        if(flg==strlen(add_data) && x == strlen(add_data)){
                            printf("DATA FOUND: \n");
                            hur=2;
                            acc+=x;
                            m= pointer_c-(x+1);

                            }
                        }

                        flg=0;
                        #if debug
                        printf("%s  %d  %s %d %d f0\n",buffer,x,add_data,strlen(add_data),strcmp(add_data,buffer));
                        #endif // debug
                        }
                        else{
                            #if debug
                            printf("i am here but now\n");
                            printf("%d   fr\n",hur );
                            #endif // debug
                            if(hur ==2){
                                    acc+=x;
                                    printf(" %d %d %d f2\n",size,pointer_c,acc);
                                    if(t==4){

                                        fseek(fload,m, SEEK_SET);
                                      /*for (c=0;c<5;c++)
                                        printf("%d %c %d %c %d f3\n",m,container[m],pointer_c,container[pointer_c],c);*/
                                        if(pointer_c+1==size){
                                            fseek(fload,-(acc+6),SEEK_END);
                                            int position = ftell(fload);
                                            ftruncate(fileno(fload), position);
                                        }
                                        else{
                                            for(c=pointer_c+1;c<size;c++){
                                                fprintf(fload,"%c",container[c]);
                                            }
                                            fseek(fload,-(acc+6),SEEK_END);
                                            int position = ftell(fload);
                                            ftruncate(fileno(fload), position);
                                        }

                                        }
                                    }

                                 wro++;
                            }
                            //printf("%d %s %d f4\n",x,buffer,acc);

                        }
                        for(c=0;c<30;c++){
                            buffer[c]=' ';
                        }

                        pointer_c++;
                    }
                }
                #if debug
                printf("f4 \n");
                printf("%d  %d f11 \n",pointer_c,size);
                #endif // debug
                if(pointer_c <size){
                    DELETE(pointer_c,add_data,wro);
                    #if debug
                    printf("f5\n");
                    #endif // debug

                }
                if(wro==4 && hur==2) {
                        #if debug
                        printf("/****************DELETE DONE***************\  \n");
                        #endif
                        wro=0;
                }
                fclose(fload);
    }



void DELET(int pointer_c,int length)        //file start,start pointer ,length
{
    FILE * fload;
    fload = fopen("DATABASE.txt","r+");


    char container[500];
    int size=0,x,y,t=0,c =0,flg;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee


    while(!feof(fload))
    {
        fgets ( container, 500, fload );
        size= strlen(container);
        #if debug
            printf(" %d %d f2\n",size,pointer_c);
        #endif // debug
    }
    fseek(fload,pointer_c-length, SEEK_SET);
    printf(" %d %d f2\n",size,pointer_c);
    for(c=pointer_c+1;c<size;c++){

            fprintf(fload,"%c",container[c]);
           // printf("%d %c fs\n ",length,container[c]);
           /* if(c == size-length) {
                    //fseek(fload,length, SEEK_END);
                    fprintf(fload,"\0");
                    printf("%d %c f3\n ",length,container[c]);
                    fclose(fload);
            }*/

    }

    fseek(fload,-(length+1),SEEK_END);
    int position = ftell(fload);
    ftruncate(fileno(fload), position);


fclose(fload);

}
void SHIFT(int pointer_c,int length ){

    FILE * fload;
    fload = fopen("DATABASE.txt","r+");


    char container[500];
    int size=0,x=0,t=0,c =0;              // size define the size of file,pointer_c in the file,x in array,y in the array,counter for each field of the employee


    while(!feof(fload))
    {
        fgets ( container, 500, fload );
        size= strlen(container);
        //#if debug
            printf(" %d %d f2\n",size,pointer_c);
       // #endif // debug
    }

    fseek(fload,0, SEEK_END);
    for(c=0;c<(length-1);c++){          //length -1, this one for the place of \0
        fprintf(fload,"E");
    }
    fprintf(fload,"\0");
    printf(" %d f3 \n",size);

    for(t=size;t>(pointer_c-1);t--){
        fseek(fload,-x, SEEK_END);
        fprintf(fload,"%c",container[t]);
        x++;
        printf(" %c f4 \n",container[t]);
    }
    fprintf(fload,"\,");
    printf("f5 \n");

    fclose(fload);
}
