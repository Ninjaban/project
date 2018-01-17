#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	(void)ac;
	int		i = 5;
	FILE	*f = NULL;
	char	buff[200];

	if (i > 0 && strcmp(av[0], "./Sully"))
		i--;
	else if (i == 0)
		return 0;
	sprintf(buff, "./Sully_%d.c", i);
	f = fopen(buff, "w+");
	char	*a = "#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%c#include <unistd.h>%c%cint%c%cmain(int ac, char **av)%c{%c%c(void)ac;%c%cint%c%ci = %d;%c%cFILE%c*f = NULL;%c%cchar%cbuff[200];%c%c%cif (i > 0 && strcmp(av[0], %c./Sully%c))%c%c%ci--;%c%celse if (i == 0)%c%c%creturn 0;%c%csprintf(buff, %c./Sully_%%d.c%c, i);%c%cf = fopen(buff, %cw+%c);%c%cchar%c*a = %c%s%c;%c%cfprintf(f,a,10,10,10,10,10,9,9,10,10,9,10,9,9,9,i,10,9,9,10,9,9,10,10,9,34,34,10,9,9,10,9,10,9,9,10,9,34,34,10,9,34,34,10,9,9,34,a,34,10,9,10,9,10,9,34,34,10,9,10,9,10,10);%c%cfclose(f);%c%csprintf(buff, %cclang -Wall -Wextra -Werror Sully_%%d.c -o Sully_%%d ; ./Sully_%%d %c,i,i,i);%c%csystem(buff);%c%creturn 0;%c}%c";
	fprintf(f,a,10,10,10,10,10,9,9,10,10,9,10,9,9,9,i,10,9,9,10,9,9,10,10,9,34,34,10,9,9,10,9,10,9,9,10,9,34,34,10,9,34,34,10,9,9,34,a,34,10,9,10,9,10,9,34,34,10,9,10,9,10,10);
	fclose(f);
	sprintf(buff, "clang -Wall -Wextra -Werror Sully_%d.c -o Sully_%d ; ./Sully_%d ",i,i,i);
	system(buff);
	return 0;
}
