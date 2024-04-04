// This provides the entry point for the Hospital program

#include <stdio.h>
#include <stdlib.h>
#include "Patient.h"

#pragma warning(disable : 4996)

int main(void)
{
	Patient patient_ary[MAX_BEDS]; 

	// Open the random patient file for reading
	FILE *fp = fopen("RandomPatients.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading");
        exit(1);
    }

	// Open the ordered patient file for writing
	FILE *fp2 = fopen("OrderedPatients.txt", "w");
	if (fp2 == NULL) {
   		printf("Error opening file for writing.");
    	exit(1);
	}

	// Read the patients into the structure array
	int num_pats = 0;

	while (!feof(fp)) {
    	fscanf(fp, "%s %s %d", patient_ary[num_pats].name, patient_ary[num_pats].surname, &patient_ary[num_pats].age);
    	num_pats++;
	}

	fclose(fp);	// we are finished with the random file, close it

	// Order the patients for age using the Bubble Sort Algorithm
	for (int i=0; i < num_pats; i++ ){
		for (int j = 0; j < num_pats-1; j++){
			if (patient_ary[j].age > patient_ary[j+1].age) {
            	Patient temp = patient_ary[j];
            	patient_ary[j] = patient_ary[j+1];
            	patient_ary[j+1] = temp;
			}
		}
	}	

	// Write the ordered patients to the output file
	for (int i = 1; i < num_pats; i++) {
    	fprintf(fp2, "%s %s %d\n", patient_ary[i].name, patient_ary[i].surname, patient_ary[i].age);
	}

	fclose(fp2);	// we are finished with the ordered file, close it

	printf("Patients ordered by age in the output file!..\n");
	return 0;
}
