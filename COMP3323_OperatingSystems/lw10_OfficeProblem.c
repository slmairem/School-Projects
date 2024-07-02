#include <stdio.h>
#include <stdbool.h>

#define P 8   // Number of processes (job types)
#define R 5   // Number of resources (Computers, Desks, Printers, Conference Rooms, Projectors)

// Function prototypes
void calculateNeed(int need[P][R], int max[P][R], int allot[P][R]);
bool isSafe(int processes[], char ** jobTypes, int avail[], int max[][R], int allot[][R]);
void printResult(int safeSeq[P], char** jobTypes);

int main() {
    int process_ids[] = {0, 1, 2, 3, 4, 5, 6, 7};  // Job types IDs
    char** jobTypes = (char*[]){"Software Developer", "Graphic Designer", "Sales Representative", "HR Manager", "Accountant", "Marketing Analyst", "Customer Support Specialist", "Project Manager"};

    // Available instances of resources. Find minimum resources required for each job type.
    // ???
    int avail[P] = {5,0,5,0,2};

    // Maximum R that can be allocated to processes. Look the table in the question for assignment.
    // ???
    int max[P][R]={ 
        {10,4,1,0,0},
        {5,1,8,0,1},
        {1,1,2,1,2},
        {2,2,1,0,1},
        {2,1,1,1,0},
        {2,2,3,3,2},
        {5,8,1,0,0},
        {1,2,1,2,2}
    };

    // Resources currently allocated to processes. Look the table in the question for assignment.
    // ???
    int allot[P][R]={ 
        {0,2,0,0,0},
        {1,0,1,0,0},
        {1,1,0,1,0},
        {0,1,1,0,0},
        {1,1,0,0,0},
        {1,2,0,1,1},
        {1,2,1,0,0},
        {0,1,0,1,0}
    };

    // Check system state
    // ???
    if (isSafe(process_ids, jobTypes, avail, max, allot)) {
        printResult(process_ids, jobTypes);
    } else {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}

// Function to calculate need matrix
void calculateNeed(int need[P][R], int max[P][R], int allot[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

// Print result
void printResult(int safeSeq[P], char** jobTypes) {
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    
    printf("\n\nOrder of job types: ");
    for (int i = 0; i < P; i++)
        printf("\n%d. %s", i + 1, jobTypes[safeSeq[i]]);
    printf("\n");
}

bool isSafe(int process_ids[], char** jobTypes, int avail[], int max[][R], int allot[][R]) {
    int work[R];
    bool finish[P]= {false};

    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0; 

    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool execute = true;
                for (int j = 0; j < R; j++) {
                    if (max[i][j] - allot[i][j] > work[j]) {
                        execute = false;
                        break;
                    }
                }

                if (execute) {
                    for (int j = 0; j < R; j++) {
                        work[j] += allot[i][j];
                    }
                    finish[i] = true;
                    count++;
                    found = true;
                    break; 
                }
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}
