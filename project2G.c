#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{	
	if (argc < 2)
	{
		return EXIT_FAILURE;
	}

	
	FILE* filePointer;
	
	filePointer = fopen(argv[1] , "r");
	if (filePointer == NULL)
	{
		printf("Error Opening File");
		fclose(filePointer);
		return EXIT_FAILURE;
	}

	fseek(filePointer, 0, SEEK_END);
	long size = ftell(filePointer);
	fseek(filePointer, 0, SEEK_SET);
	if (size == 0)
	{
		printf("Empty file");
		fclose(filePointer);
		return EXIT_FAILURE;
	}
	char *word = malloc(size + 1);
	char *buffer = malloc(size + 1);
	if (buffer == NULL)
	{
		printf("Memory Allocation failed\n");
		fclose(filePointer);
		return EXIT_FAILURE;
	}
	fread(buffer, sizeof(char), size, filePointer);
	for (int i = 2; i < argc; i++)
	{	
	int count = 0;
	int same_count = 0;
	for (int j = 0; j < size ; j++)
	{
		word[count] = buffer[j];

		if (buffer[j] == ' ' || buffer[j] == '.' || buffer[j] == ',' || buffer[j] == '\n')
		{
			word[count+1] = '\0';

			int check;

		
			if (strlen(word) - 1 <= strlen(argv[i]))
			
			check = strncmp(word, argv[i], strlen(argv[i]));
			
			else
			
			check = strncmp(word, argv[i], strlen(word) - 1);
			
			count = 0;

			if  (check == 0)
			{
				same_count ++;
			}
		}
		else
		
			count++;
		

	}
	printf("The word \"%s\" occurs %d times.\n", argv[i], same_count);
	}
	free(buffer);
	free(word);
	fclose(filePointer);
}


