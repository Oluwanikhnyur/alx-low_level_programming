#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
* read_textfile - This will read a text file and as well
* prints the file to the POSIX stdo
*
* @filename: The name of the file to be read
*
* @letters: The number of letters it should read and as well print
*
* Return: The actual number of letters it could read and
* as the same time print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	ssize_t lenr, lenw;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
	close(file_d);
		return (0);
	}

	lenr = read(file_d, buffer, letters);
	close(file_d);

	if (lenr == -1)
	{
	free(buffer);
		return (0);
	}

	lenw = write(STDOUT_FILENO, buffer, lenr);
	free(buffer);

	if (lenw == -1 || lenw != lenr)
		return (0);

	return (lenw);
}
