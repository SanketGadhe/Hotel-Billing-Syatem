#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>

   

int max=20;
int main(){
     FILE *R_N;
    
    int choice;
    char search_name[40],another;
    

 struct customer{
         
          int item;
        char Cus_Name[40],(Item_Name[max])[40],discount;
      int unitprice[max],quantity[max];
        float Total[max],subtotal;
        float Net_total,Grand_total,cgst,sgst;
        float Discount;
        float dis;

    } c;
    int size;
    size=sizeof(c);
 
   R_N=fopen("Restaurant_Name.txt","rb+");
   if(R_N==NULL){
       R_N=fopen("Restaurant_Name.txt","wb+");
       if(R_N==NULL){
           printf("File Not Found");
           exit(1);
       }
   }

while(1){
     system("cls");
    printf("\nPlease select operation you want to perform\n\n");
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
   
    
printf("\nEnter name of customer:");
scanf("%s",c.Cus_Name);
printf("Enter the number of item taken:");
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
printf("\n\n\t\t\t\t     Restaurant Name\n");
printf("\t\t\t\t\t-------------------------\n");
printf("Date:\n");
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
    printf("\n\n\t\t\t\t         Restaurant Name\n");
printf("\t\t\t\t\t-------------------------\n");
printf("Date:\n");
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
while(another=='y'||another=='Y'){
printf("Enter the name of customer to search:");
scanf("%s",search_name);

FILE *S_C;
S_C=fopen("Search_Customer","wb+");
rewind(R_N);


while(fread(&c,size,1,R_N)==1){
    if(strcmp(c.Cus_Name,search_name)==0){
        fwrite(&c,size,1,S_C);
    }
    else
    printf("No customer Found");
}
fclose(R_N);

while(fread(&c,size,1,S_C)==1){
    printf("\n\n\t\t\t\t     Restaurant Name\n");
printf("\t\t\t\t\t-------------------------\n");
printf("Date:\n");
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
fclose(S_C);
remove("Search_Customer");
printf("Search another customer");
fflush(stdin);
another=getch();
    
}
break;

}








}
return 0;
}