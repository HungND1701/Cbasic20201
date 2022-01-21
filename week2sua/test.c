#include<stdio.h>
#include<stdlib.h>
 
struct Date
{
 int d;
 int m;
 int y;
};
 
struct Date m_date = {16, 9, 1989};
 
void main()
{
    FILE *fp = NULL;
    int n_byte;
    struct Date date;
 
    //openning file to writting
    fp = fopen("data.dat","w");
    if(fp == NULL)
        printf("\nError in openning file");
    else
    {
        //ghi struct date xuong file data.dat
        if(fwrite(&m_date, sizeof(m_date), 1, fp) != 1)
        printf("Error in writting");
        fclose(fp);
    }
 
    //openning file to read
    fp = fopen("data.dat","r");
 
    if(fp == NULL)
        printf("\nError in openning file");
    else
    {
        if(fread(&date, sizeof(date), 1, fp) != 1)
        printf("\nError in reading ");
        else
        {
            printf("\ndd/mm/yyyy = %.2d/%.2d/%.4d", date.d, date.m, date.y);
        }
        fclose(fp);
    }
    getchar();
}