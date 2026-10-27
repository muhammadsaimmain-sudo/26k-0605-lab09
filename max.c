#include <stdio.h>

int max(int a,int b,int c); 

int main(){
int a;
int b;
int c;
printf("Enter first number \n");
scanf("%d",&a);

printf("Enter second number \n");
scanf("%d",&b);



printf("Enter third number \n");
scanf("%d",&c);


max(a,b,c);


}



int max(int a,int b,int c){
 
if(a>b && a>c){
    printf("A is greatest\n");
}

else if(b>a && b>c){
    printf("B is greatest\n");
}

else if(c>b && c>b){
    printf("C is greatest\n");
}

}




//array[],array