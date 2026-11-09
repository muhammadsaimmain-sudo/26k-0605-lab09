#include <stdio.h>

// Struct for Hall 1: Standard uniform 3x4 grid
struct ModernHall {
    int seats[3][4];
};

// Struct for Hall 2: Jagged structure with varying row lengths
struct OlderHall {
    int row1[3];
    int row2[5];
    int row3[7];
    int *rows[3];     
    int rowSizes[3];   
};

// Function prototypes
void printHall1(struct ModernHall *h1);
void printHall2(struct OlderHall *h2);
int bookHall2(struct OlderHall *h2, int row, int seat);

int main() {
    // 1. Initialise Hall 1 (0 = Vacant, 1 = Booked)
    struct ModernHall hall1 = {
        .seats = {
            {0, 1, 0, 0},
            {1, 0, 0, 1},
            {0, 0, 1, 0}
        }
    };

    // 2. Initialise Hall 2 arrays
    struct OlderHall hall2 = {
        .row1 = {0, 1, 0},           
        .row2 = {1, 0, 0, 1, 0},       
        .row3 = {0, 0, 1, 0, 0, 0, 1}, 
        .rowSizes = {3, 5, 7}          
    };

 
    hall2.rows[0] = hall2.row1;
    hall2.rows[1] = hall2.row2;
    hall2.rows[2] = hall2.row3;


    printf("--- INITIAL SEATING CHARTS ---\n");
    printHall1(&hall1);
    printHall2(&hall2);

    int r, s;
    printf("\n--- CUSTOMER BOOKING FOR HALL 2 ---\n");
    printf("Enter Row index (0 to 2) and Seat index to book (e.g., 1 4): ");
    if (scanf("%d %d", &r, &s) == 2) {
        
        if (bookHall2(&hall2, r, s)) {
            printf("\n--- UPDATED SEATING CHARTS AFTER SUCCESSFUL BOOKING ---\n");
            printHall2(&hall2);
        }
    }

    return 0;
}

void printHall1(struct ModernHall *h1) {
    printf("\n[ Hall 1 - Seating Chart ]\n");
    
    int (*rowPtr)[4] = h1->seats; 
    int vacantCount = 0;

    for (int i = 0; i < 3; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < 4; j++) {
            int seatStatus = *(*(rowPtr + i) + j); 
            if (seatStatus == 0) {
                printf("[V] ");
                vacantCount++;
            } else {
                printf("[B] ");
            }
        }
        printf("\n");
    }
    printf("Total Vacant Seats in Hall 1: %d\n", vacantCount);
}

void printHall2(struct OlderHall *h2) {
    printf("\n[ Hall 2 - Seating Chart ]\n");
    int vacantCount = 0;

    for (int i = 0; i < 3; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < h2->rowSizes[i]; j++) {
            int seatStatus = h2->rows[i][j];
            if (seatStatus == 0) {
                printf("[V] ");
                vacantCount++;
            } else {
                printf("[B] ");
            }
        }
        printf("\n");
    }
    printf("Total Vacant Seats in Hall 2: %d\n", vacantCount);
}

int bookHall2(struct OlderHall *h2, int row, int seat) {
    if (row < 0 || row >= 3) {
        printf("Booking Rejected: Row %d does not exist in Hall 2.\n", row);
        return 0;
    }

    if (seat < 0 || seat >= h2->rowSizes[row]) {
        printf("Booking Rejected: Seat %d does not exist in Row %d. (This row only has %d seats).\n", 
               seat, row, h2->rowSizes[row]);
        return 0;
    }

    if (h2->rows[row][seat] == 1) {
        printf("Booking Rejected: Seat %d in Row %d is already booked.\n", seat, row);
        return 0;
    }

    h2->rows[row][seat] = 1;
    printf("Booking Successful! Row %d, Seat %d has been reserved.\n", row, seat);
    return 1;
}
