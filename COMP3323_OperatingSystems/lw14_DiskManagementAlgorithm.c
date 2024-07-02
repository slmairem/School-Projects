#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 8

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find_index(int arr[], int head) {
    int i, pos = 0;
    for (i = 0; i < SIZE; i++) {
        if (arr[i] <= head && arr[i + 1] >= head) {
            pos = i;
        }
    }
    return pos;
}

void FCFS(int temp[], int head) {
    int seek_count=0, i;
    int cur_track, distance;
   
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("FCFS Disk Scheduling Algorithm\n");
    for(i=0 ; i<SIZE ; i++){
        cur_track = temp[i];

        distance = abs(cur_track - head);
        seek_count += distance;
       
        printf("head=%d-->%d seek_count=%d\n", head, cur_track, distance);
        head = cur_track;
    }
   
    printf("Total number of seek operations: %d\n", seek_count);
}

void SSTF(int temp[], int head) {
    int seek_count = 0, distance, cur_track;
    int* seek_sequence = (int*)malloc(SIZE * sizeof(int));
    int visited[SIZE] = {0};

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("SSTF Disk Scheduling Algorithm\n");

    for (int i = 0; i < SIZE; i++) {
        int min = 10000, index = -1;
        for (int j = 0; j < SIZE; j++) {
            if (!visited[j] && abs(temp[j] - head) < min) {
                min = abs(temp[j] - head);
                index = j;
            }
        }
        if (index == -1) break;  // in case all tracks have been visited
        visited[index] = 1;

        cur_track = temp[index];
        seek_sequence[i] = cur_track;
        distance = abs(cur_track - head);
        seek_count += distance;
        
        printf("head=%d-->%d seek_count=%d\n", head, cur_track, distance);
        head = cur_track;
    }

    printf("\nTotal number of seek operations = %d\n", seek_count);
    free(seek_sequence);
}

void Scan(int temp[], int head, int rotation) {
    int i, j, seek_time = 0, current = head;
    sort(temp, SIZE);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("SCAN Disk Scheduling:\n");
    if (rotation == 1) { // left
        for (i = SIZE - 1; i >= 0 && temp[i] >= head; i--);
        for (j = i; j >= 0; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
        printf("head=%d-->0 seek_count=%d\n", current, current);
        seek_time += current;
        current = 0;
        for (j = i + 1; j < SIZE; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    } else { // right
        for (i = 0; i < SIZE && temp[i] <= head; i++);
        for (j = i; j < SIZE; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
        printf("head=%d-->199 seek_count=%d\n", current, 199 - current);
        seek_time += 199 - current;
        current = 199;
        for (j = i - 1; j >= 0; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    }
    printf("\nTotal number of seek operations = %d\n", seek_time);
}


void Cscan(int temp[], int head, int rotation) {
    int i, j, seek_time = 0, current = head;
    sort(temp, SIZE);
    
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("C-SCAN Disk Scheduling:\n");

    if (rotation == 1) { // Left
        for (i = SIZE - 1; i >= 0 && temp[i] >= head; i--);

        // Scan to the left
        for (j = i; j >= 0; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }

        //Jump to the beginning
        if (current != 0) {
            printf("head=%d-->0 seek_count=%d\n", current, current);
            seek_time += current;
            current = 0;
        }

        //Jump to the end of the disk
        printf("head=%d-->199 JUMP\n", current);
        current = 199;

        //Scan to the right from the end up to the starting index
        for (j = SIZE - 1; j > i; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    } else { // Right
        for (i = 0; i < SIZE && temp[i] <= head; i++);

        // Scan to the right
        for (j = i; j < SIZE; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }

        //Jump to the end
        if (current != 199) {
            printf("head=%d-->199 seek_count=%d\n", current, 199 - current);
            seek_time += 199 - current;
            current = 199;
        }

        // Jump to the beginning
        printf("head=%d-->0 JUMP\n", current);
        current = 0;

        // Scan to the right from the beginning up to the starting index
        for (j = 0; j < i; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    }

    printf("Total number of seek operations = %d\n", seek_time);
}


void Look(int temp[], int head, int rotation) {
    int i, j, seek_time = 0, current = head;
    sort(temp, SIZE);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("LOOK Disk Scheduling:\n");

    if (rotation == 1) { // left
        for (i = SIZE - 1; i >= 0 && temp[i] >= head; i--);
        for (j = i; j >= 0; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
        for (j = i + 1; j < SIZE; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    } else { // right
        for (i = 0; i < SIZE && temp[i] <= head; i++);
        for (j = i; j < SIZE; j++) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
        for (j = i - 1; j >= 0; j--) {
            printf("head=%d-->%d seek_count=%d\n", current, temp[j], abs(current - temp[j]));
            seek_time += abs(current - temp[j]);
            current = temp[j];
        }
    }
    printf("\nTotal number of seek operations = %d\n", seek_time);

}


void Clook(int temp[], int head, int rotation) {
    int i, j, seek_time = 0, current = head;
    sort(temp, SIZE);

    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    printf("C-LOOK Disk Scheduling:\n");

    for (i = 0; i < SIZE && temp[i] <= head; i++); //head's index

    if (rotation == 1) { // Left 
        for (j = i - 1; j >= 0; j--) {
            int move_time = abs(current - temp[j]);
            if (move_time > 0) {
                printf("head=%d-->%d seek_count=%d\n", current, temp[j], move_time);
            }
            seek_time += move_time;
            current = temp[j];
        }

        //Wrap around
        if (i < SIZE) {
            printf("head=%d-->%d JUMP!!\n", current, temp[SIZE - 1]);
            current = temp[SIZE - 1];
        }

        //Serve requests to the right of head
        for (j = SIZE - 1; j >= i; j--) {
            int move_time = abs(current - temp[j]);
            if (move_time > 0) {
                printf("head=%d-->%d seek_count=%d\n", current, temp[j], move_time);
            }
            seek_time += move_time;
            current = temp[j];
        }

    } else { // Right 
        for (j = i; j < SIZE; j++) {
            int move_time = abs(current - temp[j]);
            if (move_time > 0) {
                printf("head=%d-->%d seek_count=%d\n", current, temp[j], move_time);
            }
            seek_time += move_time;
            current = temp[j];
        }

        //Wrap around
        if (i > 0) {
            printf("head=%d-->%d JUMP!!\n", current, temp[0]);
            current = temp[0];
        }

        //Serve requests to the left of head
        for (j = 0; j < i; j++) {
            int move_time = abs(current - temp[j]);
            if (move_time > 0) {
                printf("head=%d-->%d seek_count=%d\n", current, temp[j], move_time);
            }
            seek_time += move_time;
            current = temp[j];
        }
    }

    printf("Total number of seek operations = %d\n", seek_time);
}

int main() {
    //int arr[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
    int arr[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    //int head = 50;
    int head = 53;
    int direction;
    int choice;
    int i = 1;
    
    printf("----Disk Management Algorithms----\n");
    while (i != 0) {
        printf("\n\nSelect The Disk Management Algorithms You Want To Use: \n\n");
        printf("First Come First Serve--1 \n");
        printf("Shortest Seek Time First--2 \n");
        printf("Scan(Elevator)--3 \n");
        printf("C-Scan(Circular Scan)--4 \n");
        printf("Look--5 \n");
        printf("C-Look(Circular Look)--6 \n");
        printf("Exit--0\n");

        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1: FCFS(arr, head); break;
            case 2: SSTF(arr, head); break;
            case 3: printf("Please Enter Your Disk Rotation (1 for Left & 2 for Right): \t");
                    scanf("%d", &direction);
                    Scan(arr, head, direction);
                    break;
            case 4: printf("Please Enter Your Disk Rotation (1 for Left & 2 for Right): \t");
                    scanf("%d", &direction);
                    Cscan(arr, head, direction); break;
            case 5: printf("Please Enter Your Disk Rotation (1 for Left & 2 for Right): \t");
                    scanf("%d", &direction);
                    Look(arr, head, direction); break;
            case 6: printf("Please Enter Your Disk Rotation (1 for Left & 2 for Right): \t");
                    scanf("%d", &direction);
                    Clook(arr, head, direction); break;
            case 0: i = 0; break;
            default: printf("\n Error--\n");
        }
    }
    return 0;
}
