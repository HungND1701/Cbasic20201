#include<stdio.h>

enum {SUCCESS,FAIL,MAX_ELEMENT=20};
// the phone book structure
typedef struct Student_t{
    char id[11];
    char name[20];
    int grade;
}Student;
int main(void){
    FILE *fp;
    Student arrstudent[MAX_ELEMENT];
    int i,n,irc;
    int reval=SUCCESS;
    printf("How many contacts do you want to enter (<20) ? ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("name: ");scanf("%s",arrstudent[i].name);
        printf("Id : ");scanf("%s",arrstudent[i].id);
        printf("grade: ");scanf("%d",&(arrstudent[i].grade));
    }
    if((fp=fopen("Student.dat","w+b"))==NULL){
        printf("Can not open %s.\n","Student.dat");
        reval=FAIL;
    }
    // write the entire array into the file 
    irc= fwrite(arrstudent,sizeof(Student),n,fp);
    printf("fwrite return code = %d \n",irc);
    fclose(fp);
    if((fp=fopen("Student.dat","rb"))==NULL){
        printf("Can not open %s.\n","Student.dat");
        reval=FAIL;
    }
    irc= fread(arrstudent,sizeof(Student),n,fp);
    printf("fread return code = %d\n",irc);
    for(i=0;i<n;i++){\
        printf("%s\t",arrstudent[i].name);
        printf("%s\t",arrstudent[i].id);
        printf("%d\n",arrstudent[i].grade);
    }
    fclose(fp);
    return reval;
}