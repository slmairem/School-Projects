#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000						// **** do not edit the macro  ****

typedef struct {						// **** do not edit the struct ****
	int film_id;
	char title[255];
	char description[1023];
	unsigned int release_year;
	char rental_duration;
	float rental_rate;
	unsigned char length;
	float replacement_cost;
	char rating[10];
	char last_update[30];
} RECORD_t, *RECORD;


// ************** FUNCTIONS TO BE IMPLEMENTED **************
// *********************************************************

/**
 * @brief Prints given record
 * 
 * @param record record to be printed
 */
void record_print(RECORD_t record);

/**
 * @brief Prints all records in given record array
 * 
 * @param records record array
 */
void records_print(RECORD records);

/**
 * @brief Finds the record with id, updates the rental_rate
 * of that record to new_rental_rate
 * 
 * @param records record array
 * @param id id of the record to be updated
 * @param new_rental_rate new rental rate of the record
 * @return 1, if updated successfully
 * 		   0, if couldn't find the record
 */
int record_update_rental_rate_by_id(RECORD records, int id, float new_rental_rate);

/**
 * @brief Finds the record with title, updates the rental_rate
 * of that record to new_rental_rate
 * 
 * @param records record array
 * @param title title of the record to be updated
 * @param new_rental_rate new rental rate of the record
 * @return 1, if updated successfully
 * 		   0, if couldn't find the record
 * 
 * @details You can use the strcmp() function in string.h
 */
int record_update_rental_rate_by_title(RECORD records, char *title, float new_rental_rate);

/**
 * @brief Finds the record with title, updates the title
 * of that record to new_title
 * 
 * @param records record array
 * @param title title of the record to be updated
 * @param new_title new title of the record
 * @return 1, if updated successfully
 * 		   0, if couldn't find the record
 * 
 * @details You can use the strcmp() and strcpy() functions in string.h
 */
int record_update_title_by_title(RECORD records, char *title, char *new_title);

/**
 * @brief Sorts given record array by id in ascending order
 * 
 * @param records record array
 */
void records_sort_by_id(RECORD records);
// *********************************************************


int main() {
	// *****************************************************
	// *************** DO NOT EDIT THIS PART ***************
	RECORD records = (RECORD)malloc(sizeof(RECORD_t) * MAX);
	FILE *file = fopen("records.txt", "rb");
	if (file == NULL) {
		printf("Cannot open the file.\n");
		exit(0);
	}
	fread(records, sizeof(RECORD_t) * MAX, 1, file);
	fclose(file);
	// *****************************************************

	// *****************************************************
	// ************ FUNCTION CALLS WILL BE HERE ************
	
	// *****************************************************
	
	RECORD_t record;
	record=records[122];
	
	record_print(record);
	printf("\n");
	
	int id=856;
	float new_rental_rate = 2.456;
	record_update_rental_rate_by_id(records, id, new_rental_rate);
	record=records[122];
	record_print(record);
	printf("\n");
	
	char title[] = "STREETCAR INTENTIONS";
	new_rental_rate = 3.456;
	record_update_rental_rate_by_title(records, title, new_rental_rate);
	record=records[122];
	record_print(record);
	printf("\n");
	
	char new_title [] = "STREETCAR INVENTIONS";
	record_update_title_by_title(records, title, new_title);
	record=records[122];
	record_print(record);
	printf("\n");
	
	records_sort_by_id(records);
	record=records[122]; 
	printf("\n");

	records_print(records);
	

/*	// ******** A HINT FOR ACCESSING A RECORD IN RECORDS ARRAY
	printf("ID: %d\n", records[122].film_id);
	printf("TITLE: %s\n", records[122].title);
	printf("DESCRIPTION: %s\n", records[122].description);
	printf("RELEASE YEAR: %d\n", records[122].release_year);
	printf("RENTAL DURATION: %d\n", records[122].rental_duration);
	printf("RENTAL RATE: %f\n", records[122].rental_rate);
	printf("REPLACEMENT COST: %f\n", records[122].replacement_cost);
	printf("RATING: %s\n", records[122].rating);
	printf("LAST UPDATE: %s\n", records[122].last_update);
	// *******************************************************
*/

	// *****************************************************
	// *************** DO NOT EDIT THIS PART ***************
	file = fopen("records_new.txt", "wb");
	fwrite(records, sizeof(RECORD_t) * MAX, 1, file);
	fclose(file);
	free(records);
	return 1;
	// *****************************************************
}

// ******************************************************
// ************ IMPLEMENT THE FUNCTIONS HERE ************
// 
// ******************************************************


void record_print(RECORD_t record){

	printf("ID: %d\n", record.film_id);
	printf("TITLE: %s\n", record.title);
	printf("DESCRIPTION: %s\n", record.description);
	printf("RELEASE YEAR: %d\n", record.release_year);
	printf("RENTAL DURATION: %d\n", record.rental_duration);
	printf("RENTAL RATE: %f\n", record.rental_rate);
	printf("REPLACEMENT COST: %f\n", record.replacement_cost);
	printf("RATING: %s\n", record.rating);
	printf("LAST UPDATE: %s\n", record.last_update);

}


void records_print(RECORD records){
	int i;
	for(i=0; i<MAX ; i++)
	{
	printf("ID: %d\n", records[i].film_id);
	printf("TITLE: %s\n", records[i].title);
	printf("DESCRIPTION: %s\n", records[i].description);
	printf("RELEASE YEAR: %d\n", records[i].release_year);
	printf("RENTAL DURATION: %d\n", records[i].rental_duration);
	printf("RENTAL RATE: %f\n", records[i].rental_rate);
	printf("REPLACEMENT COST: %f\n", records[i].replacement_cost);
	printf("RATING: %s\n", records[i].rating);
	printf("LAST UPDATE: %s\n", records[i].last_update);
	}
}


int record_update_rental_rate_by_id(RECORD records, int id, float new_rental_rate){
	int i;
	for(i=0 ; i < MAX ; i++)
	{	
		if (records[i].film_id == id)
		{
			records[i].rental_rate = new_rental_rate;
			return 1;
		}
	}

	return 0;
} 


int record_update_rental_rate_by_title(RECORD records, char *title, float new_rental_rate){
	int i;
	for(i=0 ; i < MAX ; i++)
	{	
		if ((strcmp(title, records[i].title) == 0))
		{
			records[i].rental_rate = new_rental_rate;
			return 1;
		}
	}
	
	return 0;
}


int record_update_title_by_title(RECORD records, char *title, char *new_title){	
	int i;
	for(i=0 ; i < MAX ; i++)
	{	
		if ((strcmp(title, records[i].title) == 0))
		{
			strcpy(records[i].title ,new_title);
			
			return 1;
		}
	}
	
	return 0;
}

void records_sort_by_id(RECORD records){
	int i, j;
	RECORD_t temp;
	for(i=0; i < MAX-1 ; i++)
	{
		for(j=0; j< MAX-i-1 ; j++)
		{
			if(records[j].film_id > records[j+1].film_id)
			{
				temp = records[j];
				records[j] = records[j+1];
				records[j+1] = temp;
			}
		}
	}
}
