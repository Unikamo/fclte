#include <stdio.h>
#include <string.h>

void edit_line(char* buffer, int current_line)
{
	for (int i = 0; i < current_line; i++){ // continue to search each time from the new line each time (\n)	
		buffer = strchr(buffer, '\n') + 1; // man strchr, buffer is the thing to search in, "\n" is the char to search for
	}

	char* line_end = strchr(buffer, '\n');
	char saved[1024] = {0};
	strcpy(saved, line_end); // man strcpy

	scanf("%s", buffer);
	strcpy(buffer + strlen(buffer), saved);
}

void main(int argc, char** argv)
{
	FILE* f = fopen(argv[1], "r"); // man fopen, "r" is the mode for read
	char buffer[1024] = {0};
	fread(buffer, 1024, 1, f); // man fread, buffer = buffer, 1024 = block, 1 = 1 block of 1024, stream = file = f
	fclose(f); // man fclose
	printf("fclte : Content :\n%s\n", buffer);

	int current_line = 0;
	scanf("%d", &current_line); // man scanf
	edit_line(buffer, current_line);	

	f = fopen(argv[1], "w");
	fwrite(buffer, strlen(buffer), 1, f); // man fwrite
	fclose(f);
}

