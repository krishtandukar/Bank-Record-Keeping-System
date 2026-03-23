#include<stdio.h>
#include<conio.h>
struct record
{
    int id;
    char name[40];
    int balance;
    char address[40];
    char status[40];
};
void main()
{   
    //creating object of customers
    struct record rec[24];
    //to access the file we make a file pointer 
    FILE *fp;
    //opening a file 
    fp=fopen("record.txt","w");
    int i;
    //writing details to the file 
    printf("Enter details of Customers : \n");
    for(i=0;i<24;i++)
    {
        printf("For customer no. %d : \n",i+1);
        printf("Id=");
        scanf("%d",&rec[i].id);
        printf("Name=");
        scanf("%s",&rec[i].name);
        printf("Balance");
        scanf("%d",&rec[i].balance);
        printf("Address=");
        scanf("%s",&rec[i].address);
        printf("Status=");
        scanf("%s",&rec[i].status);
        //writing whole line to the file
        fprintf(fp,"%d %s %d %s %s\n",rec[i].id,rec[i].name,rec[i].balance,rec[i].address,rec[i].status);
    }
    //closing the file
    fclose(fp);
    getch();
}