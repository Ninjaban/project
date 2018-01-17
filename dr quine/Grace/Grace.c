#include <stdio.h>
#define A "./Grace_kid.c"
#define B "#include <stdio.h>%c#define A %c./Grace_kid.c%c%c#define B %c%s%c%c#define C(X)int%cmain(){FILE *f = fopen(X, %cw+%c);fprintf(f,B,10,34,34,10,34,B,34,10,9,34,34,10,10,9,10,10,10);return 0;}%c/*%c%cCOMMENT%c*/%cC(A)%c"
#define C(X)int	main(){FILE *f = fopen(X, "w+");fprintf(f,B,10,34,34,10,34,B,34,10,9,34,34,10,10,9,10,10,10);return 0;}
/*
	COMMENT
*/
C(A)
