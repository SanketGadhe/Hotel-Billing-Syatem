#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>


// void gotoxy( int x,int y)
// {
//     coord.X=x;
//     coord.Y=y;
//     SetConsoleCursorPosition(GetStdHandel(STD_OUTPUT_HANDEL),coord);
// }
int main(){
    system("cls");
    FILE *fp,*ft;
    char another,choice;
    struct emp{
        char name[40];
        int age;
        float bs; 
    } e;
   
    char empname[40];
    long int recsize;
  fp=fopen("EMP.DAT","rb+");
  if (fp==NULL){
      fp=fopen("EMP.DAT","wb+");
      if(fp==NULL){
          printf("Cannot Open File");
          exit(1);
      }
  }
  recsize=sizeof(e);
  while(1){
 //  system("cls");
     //gotoxy(30,10);
      printf("\n\t\t\t\t\t\t1.Add Records\n");
     //gotoxy(30,12);
      printf("\n\t\t\t\t\t\t2.List Records\n");
     //gotoxy(30,14);
      printf("\n\t\t\t\t\t\t3.Modify Records\n");
    // gotoxy(30,16);
      printf("\n\t\t\t\t\t\t4.Delete Records\n");
     //gotoxy(30,18);
      printf("\n\t\t\t\t\t\t0.Exit\n");
     //gotoxy(30,20);
      printf("\n\t\t\t\t\t\tYour choice");
      fflush(stdin);
      choice=getch();
      switch(choice)
      {
          case '1':
          fseek(fp,0,SEEK_END);
          another='Y';
          while(another=='Y'){
              printf("\nEnter name,age and basic salary:");
              scanf("%s %d %f ",e.name,&e.age,&e.bs);
              fwrite(&e,recsize,1,fp);
              printf("Add another Information(Y/N):");
              fflush(stdin);
             another=getch();
          }
          break;
          case '2':
          rewind(fp);
          while(fread(&e,recsize,1,fp)==1)
              printf("\n %s %d %f",e.name,e.age,e.bs);
          break;
          case '3':
          another='Y';
          while(another=='Y'){
          printf("\nEnter the person name to modify information: ");
          scanf("%s",empname);
         
          rewind(fp);
          while(fread(&e,recsize,1,fp)==1){
          if(strcmp(e.name,empname)==0){
                  printf("\nEnter new name,age and basic salary: ");
                  scanf("%s %d %f",e.name,&e.age,&e.bs);
                fseek(fp,-recsize,SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;

          }
          }
          printf("\nmodify another records(Y/N):");
          fflush(stdin);
          another=getch();
          }
          break;
          case '4':
          another='Y';
          while(another=='Y'){
              printf("\nEnter Employee Name to delete:");
              scanf("%s",empname);
             
                  ft=fopen("TEMP.DAT","wb");
                  rewind(fp);
                  while(fread(&e,recsize,1,fp)==1){
                  if(strcmp(e.name,empname)!=0)
                  fwrite(&e,recsize,1,ft);  
                  
              }
              fclose(fp);
              fclose(ft);
              remove("EMP.DAT");
              rename("TEMP.DAT","EMP.DAT");
              fp=fopen("EMP.DAT","rb");
              printf("DElete another data(Y/N):");
              fflush(stdin);
              another=getch();
          }
          break;
          case 0:
          fclose(fp);
          exit(1);
      }

  }
  return 0;
}