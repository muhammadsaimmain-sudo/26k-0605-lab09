#include <stdio.h>

int before(int a,int b);
int after(int *a,int*b);
int work(int arr[],int *a,int *b,int *c);

int main() {

   int wardA=10;
    int wardB=20;
    printf("ADRESS OF wardA is  %p\n",&wardA);
    printf("ADRESS OF wardB  is %p \n",&wardB);
before(wardA,wardB);
printf(" BEFORE CHANGE VALUE oF A :%d \n",wardA);
printf("BEFORE CHANGE VALUE OF B :%d \n",wardB);

    
after(&wardA,&wardB);

printf(" AFTER CHANGE VALUE oF A :%d \n",wardA);
printf("AFter CHANGE VALUE OF B :%d \n",wardB);

int data[7]={1,4,6,7,8,9,5}    ;
    int total=0;
    int high=0;
    int low=data[0];
    work( data, &high, &low,&total);
   printf("TOTAL = %d \n",total);
    printf("HIGHEST = %d \n ",high);
    printf("LOWEST = %d \n",low);

    printf("ADRESS OF ARRAY is  %p\n",&data);
    printf("ADRESS OF total is  %p\n",&total);
    printf("ADRESS OF high is  %p\n",&high);
    printf("ADRESS OF low is  %p\n",&low);
    return 0;
}




int before(int a,int b){
 // a=20;
 // b=10;   

   int temp=a;
    a=b;
    b=temp;
    
 printf("ADRESS OF wardA is  %p\n",&a);
    printf("ADRESS OF wardB  is %p \n",&b);

    
}


int after(int *a,int *b){
 int temp=*a;
     *a=*b;
    *b=temp;

    
     printf("ADRESS OF wardA is  %p\n",a);
    printf("ADRESS OF wardB  is %p \n",b);
    
}



int work(int arr[],int *a,int *b,int *c){
   for(int i=0;i<7;i++){
    if(arr[i]> *a){
        *a=arr[i];
    }
    if(arr[i]< *b){
        *b=arr[i];
    }
       *c+=arr[i];
        
       
   }

   printf("ADRESS OF ARRAY is  %p\n",&arr);
    printf("ADRESS OF total is  %p\n",&c);
    printf("ADRESS OF high is  %p\n",&a);
    printf("ADRESS OF low is  %p\n",&b);

    
}
