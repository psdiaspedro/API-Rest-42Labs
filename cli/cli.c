#include <unistd.h>

int	main(void)
{
	char	*args[] = {"cat", "logs.txt", NULL};
	execv("/bin/cat", args);
}
