#include <stdio.h>

int main() {
    int readings[7];
    int *ptr = readings;
    int total = 0;
    int max_day = 1;
    int threshold;
    int *linked_meter = NULL;

    for (int i = 0; i < 7; i++) {
        printf("Enter consumption for Day %d: ", i + 1);
        scanf("%d", (ptr + i));
    }

    printf("\n");

    for (int i = 0; i < 7; i++) {
        printf("Day %d Reading: %d at Address: %p\n", i + 1, *(ptr + i), (void*)(ptr + i));
        
        if (i < 6) {
            unsigned long long addr1 = (unsigned long long)(ptr + i);
            unsigned long long addr2 = (unsigned long long)(ptr + i + 1);
            unsigned long long diff = addr2 - addr1;
            printf("Distance to next day: %llu bytes. Explanation: An 'int' type takes 4 bytes of memory.\n", diff);
        }
    }

    int max_val = *ptr;
    for (int i = 0; i < 7; i++) {
        total += *(ptr + i);
        if (*(ptr + i) > max_val) {
            max_val = *(ptr + i);
            max_day = i + 1;
        }
    }

    printf("\nWeekly Total Consumption: %d units\n", total);
    printf("Day with highest consumption: Day %d (%d units)\n", max_day, max_val);

    printf("\nEnter peak-tariff threshold: ");
    scanf("%d", &threshold);

    for (int i = 0; i < 7; i++) {
        if (*(ptr + i) > threshold) {
            *(ptr + i) *= 2;
        }
    }

    printf("\nAdjusted readings:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: %d units\n", i + 1, *(ptr + i));
    }

    printf("\n--- Linked Meter Demonstration ---\n");
    if (linked_meter == NULL) {
        printf("Linked meter is unassigned (NULL pointer is safe).\n");
    }

    linked_meter = (ptr + 2);

    if (linked_meter != NULL) {
        printf("Linked meter assigned safely. Consumption value at link: %d\n", *linked_meter);
    }

    return 0;
}
