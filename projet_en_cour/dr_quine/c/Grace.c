#include <stdio.h>
#include <unistd.h>

/*
	Commentaire
*/

#define STR "#include <stdio.h>%c#include <unistd.h>%c%c/*%c%cCommentaire%c*/%c%c#define STR %c%s%c%c#define PRINTF(fd) fprintf(fd, STR, 10, 10, 10, 10, 9, 10, 10, 10, 34, STR, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10);}%c#define MAIN int main(void){FILE *fd;fd = fopen(%c./Grace_kid.c%c, %cw+%c); PRINTF(fd);%c%cMAIN%c"
#define PRINTF(fd) fprintf(fd, STR, 10, 10, 10, 10, 9, 10, 10, 10, 34, STR, 34, 10, 10, 34, 34, 34, 34, 10, 10, 10);}
#define MAIN int main(void){FILE *fd;fd = fopen("./Grace_kid.c", "w+"); PRINTF(fd);

MAIN
