#include <stdio.h>

int sum(int a,int b);
int minus(int a,int b);
int divide(int a,int b);
int mult(int a,int b);


int main(){
 int a;
 int b;

printf("Enter first number\n");
scanf("%d",&a);

printf("Enter second number\n");
scanf("%d",&b);
int opt;
printf("Enter Operation\n :1:+\n 2:-\n 3: / \n 4:* \n");

scanf("%d",&opt);


switch(opt){
case 1:
     printf("%d + %d = %d",a,b,sum(a,b));
     break;
case 2:
     printf("%d - %d = %d",a,b,minus(a,b));
     break;

case 3:
     printf("%d / %d = %d",a,b,divide(a,b));
     break;


case 4:
     printf("%d * %d = %d",a,b,mult(a,b));
      break;

}


}



int sum(int a,int b){
return a+b;

}


int minus(int a,int b){
return a-b;

}

int divide(int a,int b){
return a/b;

}

int mult(int a,int b){
return a*b;

}
