#include <stdio.h>
#include <stdbool.h>

int main() {
    int frames, pages;
    printf("Enter number of frames:");
    scanf("%d", &frames);
    
    printf("Enter number of pages:");
    scanf("%d", &pages);
 
    int refString[pages];
    printf("Enter the reference string:");
    for(int i=0 ; i<pages ; i++){
        scanf("%d", &refString[i]);
    }

    int faults=0, time=0;
    
    int frame[frames], frameTime[frames];
    bool inMemory = false;
    
    for(int i=0; i<frames; i++){
        frame[i] = -1;
        frameTime[i] = -1;
    }
    
    for(int i=0; i<pages; i++) {
        int page = refString[i];
        inMemory = false;
        
        for(int j=0; j<frames; j++) {
            if(frame[j] == page) {
                inMemory = true;
                frameTime[j] = time;
                break;
            }
        }
        
        if(!inMemory) {
            int replace = 0;
            for(int k=1; k<frames; k++) {
                if(frameTime[k] < frameTime[replace]) {
                    replace = k;
                }
            }
            frame[replace] = page;
            frameTime[replace] = time;
            faults++;
        }
        
        printf("\n");
        for(int k=0; k<frames; k++) {
            printf("%d\t", frame[k]);
        }
        time++;
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
