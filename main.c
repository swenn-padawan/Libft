#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
	char *ptr = strdup(argv[1]);
	char *ptr2 = strdup(argv[1]);
	printf("myptr address before = %p\n", ptr);

	printf("my strtol = %ld\n", ft_strtol(ptr, &ptr, 16));
	printf("strtol = %ld\n", strtol(ptr, &ptr, 10));

	printf("myptr address after = %s\n", ptr);
}
