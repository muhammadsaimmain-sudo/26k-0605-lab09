#include <stdio.h>

void calculate_analysis(int arr[], int size, int pass_threshold);
void apply_bonus(int arr[], int size, int bonus_val);

int main() {
    int size = 10;
    int arr[10];
    int pass_threshold, bonus_val;

    // 1. Gather Marks
    for(int i = 0; i < size; i++) {
        printf("Enter student %d marks: ", i + 1);
        scanf("%d", &arr[i]);
        if(arr[i] < 0 || arr[i] > 100) {
            printf("INVALID input enter again \n");
            i--;
        }
    }
   
   
    printf("\nEnter passing threshold mark (e.g. 50): ");
    scanf("%d", &pass_threshold);

  
    printf("\n================ INITIAL REPORT ================\n");
    calculate_analysis(arr, size, pass_threshold);  

    
    printf("\nEnter flat bonus marks to apply to all students: ");
    scanf("%d", &bonus_val);


    apply_bonus(arr, size, bonus_val);
    printf("\n============ REPORT AFTER BONUS MODERATION ============\n");
    calculate_analysis(arr, size, pass_threshold);

    return 0;
}

void calculate_analysis(int arr[], int size, int pass_threshold) {
    int total = 0;
    int highest = -1; 
    int lowest = 101;  
    int passcount = 0;
    int topscorer_count = 0;

    for(int i = 0; i < size; i++) {
        total += arr[i];
        
        if(arr[i] > highest) {
            highest = arr[i];
        }
        if(arr[i] < lowest) {
            lowest = arr[i];
        }
        if(arr[i] >= pass_threshold) {
            passcount++;
        }
    }

  
    for(int i = 0; i < size; i++) {
        if(arr[i] == highest) {
            topscorer_count++;
        }
    }

    float average = (float)total / size;

    printf("CLASS TOTAL MARKS:      %d\n", total);
    printf("CLASS AVERAGE:          %.2f\n", average);
    printf("HIGHEST MARKS:          %d\n", highest);
    printf("LOWEST MARKS:           %d\n", lowest);
    printf("TOTAL STUDENTS PASSED:  %d\n", passcount);
    printf("STUDENTS SHARING TOP:   %d\n", topscorer_count);
    printf("________________________________________________\n");
}

void apply_bonus(int arr[], int size, int bonus_val) {
    for(int i = 0; i < size; i++) {
        arr[i] += bonus_val;
   
        if(arr[i] > 100) {
            arr[i] = 100;
        }
    }
}
