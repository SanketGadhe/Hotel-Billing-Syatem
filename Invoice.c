#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void exit_to_admin();
int main(){
    struct customer{
         WORD wYear;
		WORD wMonth;
		WORD wDayOfWeek;
		WORD wDay;
		WORD wHour;
		WORD wMinute;
		WORD wSecond;
		WORD wMilliseconds;
          int item,max=20;
        char Cus_Name[40],(Item_Name[max])[40],discount;
        int unitprice[max],quantity[max];
        float Total[max],subtotal;
        float Net_total,Grand_total,cgst,sgst;
        float Discount;
        float dis;
}c;
     FILE *R_N,*S_C;
    int x,size,choice;
    char search_name[7],another; 
     size=sizeof(c);
    printf("%d",size);
    system("cls");
 R_N=fopen("Restaurant_Name.DAT","rb+");
   if(R_N==NULL){
       R_N=fopen("Restaurant_Name.DAT","wb+");
       if(R_N==NULL){
           printf("File Not Found");
           exit(1);
       }
   }
while(1){
   printf("\nPlease select operation you want to perform↓\n\n");
    printf("1.Generate Inoice\n");
    printf("2.Show All Incoice\n");
    printf("3.Search Invoice\n");
    printf("4.EXIT\n");
    printf("\nYour Choice:     ");
    scanf("%d",&choice);
    switch(choice)
    {
 case 1:
        fseek(R_N,0,SEEK_END);
         another='y';
 while(another=='y'||another=='Y'){
     system("cls");
printf("\nEnter name of customer:");
scanf("%s",c.Cus_Name);
printf("\nEnter the number of item taken:");
scanf("%d",&c.item);
for(int i=1;i<=c.item;i++){
    printf("\nPlease enter name of item%d:",i);
   scanf("%s",(c.Item_Name[i]));
    printf("\nEnter the unit price of %s:",(c.Item_Name[i]));
    scanf("%d",&c.unitprice[i]);
    printf("\nEnter the quantity of %s taken:",(c.Item_Name[i]));
    scanf("%d",&c.quantity[i]);
}
 printf("\nDisscount applied (y/n):");
c.discount=getch();
if(c.discount=='y'||c.discount=='Y'){
    printf("\nPercent of discount:");
    scanf("%f",&c.dis);

}
else
c.dis=0;
system("cls");
printf("\n\n\t\t\t\t         CODERS HOTEL\n");
printf("\t\t\t\t\t-------------------------\n");
GetSystemTime(&c);
printf("Date:%d/%d/%d %d %d:%d:%d\n",c.wDay,c.wMonth,c.wYear,c.wDayOfWeek,c.wHour,c.wMinute,c.wSecond,c.wMilliseconds);
printf("Invoice To:%s\n",c.Cus_Name);
printf("---------------------------------------------------------------------------------------------\n");
printf("Items                        Quantity                         Total\n");
printf("---------------------------------------------------------------------------------------------\n");
c.subtotal=0;
for(int i=1;i<=c.item;i++){
    c.Total[i]=(c.unitprice[i]*c.quantity[i]);
printf("\n%s",(c.Item_Name[i]));
printf("                          %d                              %.2f\n",c.quantity[i],c.Total[i]);
c.subtotal=c.subtotal+(c.unitprice[i]*c.quantity[i]);
}
printf("---------------------------------------------------------------------------------------------\n");
printf("Sub Total                                                       %.2f\n",c.subtotal);
c.Discount=(c.subtotal*(c.dis/100));
printf("Discount @%.2f                                                  %.2f\n\n",c.dis,c.Discount);
printf("                                                              -------------\n");
c.Net_total=c.subtotal-c.Discount;
c.cgst=0.09*c.Net_total;
c.sgst=0.09*c.Net_total;
c.Grand_total=c.Net_total+c.cgst+c.sgst;
printf("Net Total                                                       %.2f\n",c.Net_total);
printf("CGST @9                                                          %.2f\n",c.cgst);
printf("SGST @9                                                          %.2f\n",c.sgst);
printf("---------------------------------------------------------------------------------------------\n");
printf("Grand Total                                                    %.2f\n",c.Grand_total);
printf("---------------------------------------------------------------------------------------------\n");
char s;
printf("Do you want to save the invoice(y/n):");
fflush(stdin);
s=getch();
if(s=='y'||s=='Y'){  
    fwrite(&c,size,1,R_N);
     if(fwrite!=0){
        printf("\nSuccesfully Saved!");
    }
    else
    printf("\nEROR");   
}
printf("\nCreate another invoice(y/n)");
another=getch();
}
break;
case 2:
    rewind(R_N);
    while(fread(&c,size,1,R_N)==1){
    printf("\n\n\t\t\t\t           CODERS HOTEL \n");
printf("\t\t\t\t\t-------------------------\n");
printf("Date:%d/%d/%d %d %d:%d:%d\n",c.wDay,c.wMonth,c.wYear,c.wDayOfWeek,c.wHour,c.wMinute,c.wSecond,c.wMilliseconds);
printf("Invoice To:%s\n",c.Cus_Name);
printf("---------------------------------------------------------------------------------------------\n");
printf("Items                        Quantity                         Total\n");
printf("---------------------------------------------------------------------------------------------\n");
for(int i=1;i<=c.item;i++){
    printf("\n%s",(c.Item_Name[i]));
printf("                          %d                              %.2f\n",c.quantity[i],c.Total[i]);
}
printf("---------------------------------------------------------------------------------------------\n");
printf("Sub Total                                                       %.2f\n",c.subtotal);
printf("Discount @%.2f                                                  %.2f\n\n",c.dis,c.Discount);
printf("                                                              -------------\n");
printf("Net Total                                                       %.2f\n",c.Net_total);
printf("CGST @9                                                          %.2f\n",c.cgst);
printf("SGST @9                                                          %.2f\n",c.sgst);
printf("---------------------------------------------------------------------------------------------\n");
printf("Grand Total                                                    %.2f\n",c.Grand_total);
printf("---------------------------------------------------------------------------------------------\n");
    }
     break;
case 3:

    another='y';
    FILE *R_N,*S_C;
    R_N=fopen("Restaurant_Name.DAT","rb+");
   
    while(another=='y'){
        system("cls");
   printf("\nEnter the Name u wanted search:");
   scanf("%s",search_name);
S_C=fopen("Search.DAT","wb");
rewind(R_N);
while(fread(&c,sizeof(c),1,R_N)==1){
 
  
    if(strcmp(c.Cus_Name,search_name)==0){
        printf("******Customer %s Found******",search_name);
    fwrite(&c,sizeof(c),1,S_C);
    x=1;
    }
    else 
    x=0;
}
fclose(R_N);

fclose(S_C);
if(x==0){
    printf("\nNO Such Customer Found\n");
}
S_C=fopen("Search.DAT","rb+");
while(fread(&c,size,1,S_C)==1){
    system("cls");
    printf("\n\n\t\t\t\t           CODERS HOTEL\n");
printf("\t\t\t\t\t-------------------------\n");
printf("Date:%d/%d/%d %d %d:%d:%d\n",c.wDay,c.wMonth,c.wYear,c.wDayOfWeek,c.wHour,c.wMinute,c.wSecond,c.wMilliseconds);
printf("Invoice To:%s\n",c.Cus_Name);
printf("---------------------------------------------------------------------------------------------\n");
printf("Items                        Quantity                         Total\n");
printf("---------------------------------------------------------------------------------------------\n");
for(int i=1;i<=c.item;i++){
    printf("\n%s",(c.Item_Name[i]));
printf("                          %d                              %.2f\n",c.quantity[i],c.Total[i]);
}
printf("---------------------------------------------------------------------------------------------\n");
printf("Sub Total                                                       %.2f\n",c.subtotal);
printf("Discount @%.2f                                                  %.2f\n\n",c.dis,c.Discount);
printf("                                                              -------------\n");
printf("Net Total                                                       %.2f\n",c.Net_total);
printf("CGST @9                                                          %.2f\n",c.cgst);
printf("SGST @9                                                          %.2f\n",c.sgst);
printf("---------------------------------------------------------------------------------------------\n");
printf("Grand Total                                                    %.2f\n",c.Grand_total);
printf("---------------------------------------------------------------------------------------------\n");
}
R_N=fopen("Restaurant_Name.DAT","rb+");
   printf("\nDO U WANT TO SEARCH ANOTHER(y/n):");
   fflush(stdin);
   another=getch(); 
   }
break;
case 4:
exit_to_admin();
}
}
return 0;
}
void exit_to_admin(){
    system("cls");
char id[40],pass[40],login,ahead;
    int inc=1;
    printf("\n=====****BYYY****=====\n");
    printf("\nDo You want to login again?(y/n):");
    fflush(stdin);
    login=getch();
    if(login=='y'||login=='Y'){
        system("cls");
    while(inc==1){printf("\nEnter Admin Login id: ");
  
  fflush(stdin);
  fgets(id,40,stdin);
  id[strlen(id)-1]=0;
  printf("\nEnter Password:");
  fflush(stdin);
   while(inc<10){
   pass[inc]=getch();
        printf("*");
        inc++;
    } 
    if(strcmp(id,"Sanket366")==0||pass=="San311002"){
        printf("\nSuccesfully Login");
      printf("\nDo you want to move ahead(y/n):");
      fflush(stdin);
      ahead=getch();
      if(ahead=='y'||ahead=='Y'){
          main();}
    }
    else 
    {
        printf("Failed To Login\n**Login Id or Password is incorrect**");
   printf("\nPlz Try Again!");
   inc=1;
    }
    }
    }
}
