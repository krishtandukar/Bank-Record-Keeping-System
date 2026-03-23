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
    fp = fopen("record.txt", "w");
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
    //Displaying customers with balance less than 1000 
    printf("\n--- Customers with Balance < 1000 ---\n");
    int found = 0;
    for (i = 0; i < 24; i++)
    {
        if (rec[i].balance < 1000)
        {
            printf("ID: %d, Name: %s, Balance: %d, Address: %s, Status: %s\n", rec[i].id, rec[i].name, rec[i].balance, rec[i].address, rec[i].status);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No customers have balance less than 1000.\n");
    }
    getch(); 
}