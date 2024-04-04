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

float average_rental_rate(RECORD records){
	int i, sum=0;
	for(i=0; i<MAX ; i++){
		sum = sum + records[i].rental_rate;
	}
	return (float)sum/MAX;
}

float average_release_year(RECORD records){
	int i, sum=0;
	for(i=0; i<MAX ; i++){
		sum=sum + records[i].release_year;
	}
	return (float)sum/MAX;
}

RECORD find_top_ten_films(RECORD records){
	int i, j;
	RECORD topTen = (RECORD)malloc(10*sizeof(RECORD_t));
	for(i=0; i<10; i++){
		for(j=0; j<MAX ; j++ ){
			if (records[j].film_id == i+1){
				topTen[i] = records[j];
				break;
			}
		}
	}
	return topTen;
}

RECORD find_ten_affordable_films(RECORD records){
	int i;
	int counter = 0;
	RECORD tenFilms = (RECORD)malloc(10*sizeof(RECORD_t));
	for(i=0; i<MAX; i++){
		if ( records[i].rental_rate < average_rental_rate(records) && records[i].release_year > average_release_year(records)){
			tenFilms[counter] = records[i];
			counter++;
		}
		if(counter >= 10){
			break;
		}
	}
	return tenFilms;
}



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
    // YOUR CODE GOES HERE!
    
    int i;
	
	printf("%f \n", average_rental_rate(records));
	printf("\n");
	
	printf("%f \n", average_release_year(records));
	printf("\n");
	
	RECORD topTen = find_top_ten_films(records);
    for(i=0 ; i<10 ; i++){
    	printf("%s \n", topTen[i].title);
	}
    printf("\n");
    
    RECORD tenFilms = find_ten_affordable_films(records);
    for(i=0 ; i<10 ; i++){
    	printf("%s \n", tenFilms[i].title);
	}


	FILE *file1 = fopen("records_top_ten.txt", "w");
    FILE *file2 = fopen("records_affordables.txt", "w");
	for (i = 0; i < 10; i++)
    {
        fprintf(file1,
                "Film ID: %d\n Title: %s\n Description: %s\n Release Year: %d\n Rental Duration: %d\n Rental Rate: %f\n Length: %d\n Replacement Cost: %f\n Rating: %s\n Last Update: %s\n \n",
                topTen[i].film_id, topTen[i].title,
                topTen[i].description, topTen[i].release_year, topTen[i].rental_duration, topTen[i].rental_rate, topTen[i].length,
                topTen[i].replacement_cost, topTen[i].rating, topTen[i].last_update);
                
         fprintf(file2,
                "Film ID: %d\n Title: %s\n Description: %s\n Release Year: %d\n Rental Duration: %d\n Rental Rate: %f\n Length: %d\n Replacement Cost: %f\n Rating: %s\n Last Update: %s\n \n",
                tenFilms[i].film_id, tenFilms[i].title,
                tenFilms[i].description, tenFilms[i].release_year, tenFilms[i].rental_duration, tenFilms[i].rental_rate, tenFilms[i].length,
                tenFilms[i].replacement_cost, tenFilms[i].rating, tenFilms[i].last_update);        
    }
	fclose(file1);
	fclose(file2);
    // *****************************************************

	return 1;
}




