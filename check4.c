#include <stdio.h>
#include <conio.h>  
#include <string.h> 
//structure to store customer record
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
    FILE *fp;
    int i;
    //opening file in read mode 
    fp = fopen("record.txt", "r");
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
    //closing the file after reading 
    fclose(fp);
    //Counting total active accounts 
    int activeCount = 0;
    for (i = 0; i < 24; i++)
    {
        if (strcmp(rec[i].status, "active") == 0)
        {
            activeCount++;
        }
    }
    printf("\nTotal Active Accounts: %d\n", activeCount);
    getch(); 
}