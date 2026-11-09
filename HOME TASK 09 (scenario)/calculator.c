#include <stdio.h>


void genericPrint(void *data, char typeIndicator) {
    if (typeIndicator == 'i') {
        printf("Integer Value: %d\n", *(int *)data);
    } 
    else if (typeIndicator == 'f') {
        printf("Decimal Value: %.2f\n", *(float *)data);
    } 
    else if (typeIndicator == 'c') {
        printf("Character Value: %c\n", *(char *)data);
    } 
    else {
        printf("Error: Unknown data type indicator.\n");
    }
}



typedef int (*CalcOp)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int divide(int a, int b) {
    if (b == 0) {
        printf("\n[Execution Error]: Division by zero detected! Operation aborted.\n");
        return 0; 
    }
    return a / b;
}

int executeOperation(int num1, int num2, CalcOp operation) {
    return operation(num1, num2);
}

int main() {
    printf("--- TESTING GENERIC DATA PRINTER ---\n");
    int testInt = 42;
    float testFloat = 3.14159;
    char testChar = 'E';

    genericPrint(&testInt, 'i');
    genericPrint(&testFloat, 'f');
    genericPrint(&testChar, 'c');
    printf("------------------------------------\n\n");

    CalcOp operations[4] = {add, subtract, multiply, divide};

    int n1, n2, choice;
    printf("--- SMART CALCULATOR ENGINE ---\n");
    printf("Enter first integer number: ");
    scanf("%d", &n1);
    printf("Enter second integer number: ");
    scanf("%d", &n2);

    printf("\nAvailable Operations:\n");
    printf("[0] Add\n");
    printf("[1] Subtract\n");
    printf("[2] Multiply\n");
    printf("[3] Divide\n");
    printf("Select choice index: ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= 4) {
        printf("\n[Menu Error]: Choice %d is out of range. Valid index options are 0 to 3.\n", choice);
        return 1;
    }

    int finalOutput = executeOperation(n1, n2, operations[choice]);


    printf("\nCalculation Completed Successfully.\n");
    genericPrint(&finalOutput, 'i');

    return 0;
}
