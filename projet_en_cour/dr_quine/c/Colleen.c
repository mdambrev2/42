#include <stdio.h>

/*
	Commentaire
*/

void	to_repeat(char *c)
{
	printf(c, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, c, 34, 10, 9, 10, 10);
}

int main(void)
{
	/*
		Commentaire
	*/
	char *c = "#include <stdio.h>%c%c/*%c%cCommentaire%c*/%c%cvoid%cto_repeat(char *c)%c{%c%cprintf(c, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 9, 10, 9, 10, 9, 34, c, 34, 10, 9, 10, 10);%c}%c%cint main(void)%c{%c%c/*%c%c%cCommentaire%c%c*/%c%cchar *c = %c%s%c;%c%cto_repeat(c);%c}%c";
	to_repeat(c);
}
