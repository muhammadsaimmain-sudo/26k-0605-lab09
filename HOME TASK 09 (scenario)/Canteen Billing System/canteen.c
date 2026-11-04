#include <stdio.h>
 
int display(float item_one,float item_two,int quatone,int quanttwo);
int main(){

float item_one;
    float item_two;
   int quatone;
   int quanttwo;

do{

printf("Enter Item one price \n");
scanf("%f",&item_one);

printf("Enter Quantity \n");
scanf("%d",&quatone);
if(quatone <=0 || item_one<=0){
    printf("INVALID INPUT TRY AGAIN \n");
}







}while(item_one <=0 || quatone<=0);





do{

printf("Enter Item two price \n");
scanf("%f",&item_two);

printf("Enter Quantity \n");
scanf("%d",&quanttwo);
if(quanttwo <=0 || item_two<=0){
    printf("INVALID INPUT TRY AGAIN \n");
}







}while(item_two <=0 || quanttwo<=0);

display( item_one, item_two,quatone,quanttwo);

}




int display(float item_one,float item_two,int quatone,int quanttwo){
    float p1=item_one *quatone;
    float p2=item_two*quanttwo;
    float total=p1+p2;
    float dis=0;

    if(total>1000){
     dis=total*(0.10);
     total=total-dis;
     if(item_one>item_two){
        printf("Item one has the higfhest unit price\n");
     }   
    else{
        printf("Item two has the highest unit price \n");
    }
    printf("Total price is %f",total);

    }
     
    else if(total<=1000 ){
         if(item_one>item_two){
        printf("Item one has the higfhest unit price \n");
     }   
    else{
        printf("Item two has the highest unit price \n");
    }
    printf("Total price is %f \n",total);

    }

}