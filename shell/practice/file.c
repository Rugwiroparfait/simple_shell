#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	/** open a file for writing **/
	int fd = open("output.txt", 0_WRONLY | 0_CREAT, 0644);

	/** Check if the file opened successfully **/

	if (fd != -1)
	{
		/** REDIRECT standard output to the file **/


