#include <stdio.h>

void	function()
{
	char *a = "#include <stdio.h>%c%cvoid%cfunction()%c{%c%cchar *a = %c%s%c;%c%cprintf(a,10,10,9,10,10,9,34,a,34,10,9,10,10,10,9,10,10,9,10,10,9,10,9,10,9,9,10,9,10,9,10,10);%c}%c/*%c%cCOMMENT 1%c*/%cint%cmain()%c{%c%cfunction();%c%c/*%c%c%cCOMMENT 2%c%c*/%c%creturn 0;%c}%c";
	printf(a,10,10,9,10,10,9,34,a,34,10,9,10,10,10,9,10,10,9,10,10,9,10,9,10,9,9,10,9,10,9,10,10);
}
/*
	COMMENT 1
*/
int	main()
{
	function();
	/*
		COMMENT 2
	*/
	return 0;
}
