/*
Read the duration and pitch of notes from the file into memory.
Then play them using the speaker on the computer.
*/

#include <stdio.h>
#include "Music.h"

#pragma warning(disable : 4996)

int main(void)
{
	Note note_ary[MAX_SONG_SIZE]; // Array of Note structures

	FILE* fPtr = NULL;

	// Open the song file. On error, report and exit.
	fPtr = fopen(SONG_FILE, "r");

	if (fPtr == NULL)
	{
		printf("Error in opening the file.");
		return ERROR_EXIT;
	}

	// Read the notes into the note structure array

	int num_notes = 0;	// number of notes

	// Stay in the loop until all notes are read or the array is full

	do
	{
		fscanf(fPtr, "%d %d", &note_ary[num_notes].frequency, &note_ary[num_notes].duration);

		if (note_ary[num_notes].frequency == 0) {
			note_ary[num_notes].fPlay = Rest;
		}
		else {
			note_ary[num_notes].fPlay = Sound;
		}
		num_notes++;

	} while (num_notes < 16);

	// When finished with the file, close it
	fclose(fPtr);

	// Report it the song file is empty and exit
	if (note_ary[0].fPlay != Rest && note_ary[0].fPlay != Sound) {
		printf("File is empty.");
		exit(ERROR_EXIT);
	}


	// Play the song from memory
	for (int i = 0; i < num_notes; i++)
	{
		note_ary[i].fPlay(&note_ary[i]);
	}

	printf("Hope you liked the song!..\n");

	return SUCCESS_EXIT;
}


