#include <stdio.h>
#include <conio.h>
// structure to store customer record
struct record
{
    int id;
    char name[40];
    int balance;
    char address[40];
    char status[10];
};
void main()
{
    //array to read 24 customer records
    struct record rec[24];
    //file pointer to handle file operations 
    FILE *fp;
    int i;
    //opening file in write mode
    fp=fopen("record.txt","r");
    //checking if file opened successfully
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    //reading input from the file
    for (i = 0; i < 24; i++)
    {
        fscanf(fp,"%d %s %d %s %s",&rec[i].id,&rec[i].name,&rec[i].balance,&rec[i].address,&rec[i].status);
    }
    //closing the file after writing 
    fclose(fp);
    //variables to track highest and lowest balance
    int maxIndex = 0;
    int minIndex = 0;
    //loop to find highest and lowest balance
    for (i = 1; i < 24; i++)
    {
        if (rec[i].balance > rec[maxIndex].balance)
        {
            maxIndex = i;
        }

        if (rec[i].balance < rec[minIndex].balance)
        {
            minIndex = i;
        }
    }
    //displaying highest balance account
    printf("\n--- Highest Balance Account ---\n");
    printf("ID      : %d\n", rec[maxIndex].id);
    printf("Name    : %s\n", rec[maxIndex].name);
    printf("Balance : %d\n", rec[maxIndex].balance);
    printf("Address : %s\n", rec[maxIndex].address);
    printf("Status  : %s\n", rec[maxIndex].status);
    //displaying lowest balance account 
    printf("\n--- Lowest Balance Account ---\n");
    printf("ID      : %d\n", rec[minIndex].id);
    printf("Name    : %s\n", rec[minIndex].name);
    printf("Balance : %d\n", rec[minIndex].balance);
    printf("Address : %s\n", rec[minIndex].address);
    printf("Status  : %s\n", rec[minIndex].status);
    getch();
}