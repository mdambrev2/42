#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *up;
	char *files_name;
	char *exec_name;
	char *exec_cmd;
	char *str;
	int x;
	FILE *fd;

	x = 5;
	up = getenv("_");
	if(!strstr(up, "./Sully_"))
		x++;
	if(x <= 0)
		return(0);
	asprintf(&files_name, "./Sully_%d.c", x - 1);
	asprintf(&exec_name, "./Sully_%d", x - 1);
	asprintf(&exec_cmd, "clang -Wall -Wextra -Werror -o Sully_%d Sully_%d.c ; %s ", x - 1, x - 1, exec_name);
	fd = fopen(files_name, "w+");
	str = "#include <string.h>%c#include <stdio.h>%c#include <stdlib.h>%c%cint main(void)%c{%c%cchar *up;%c%cchar *files_name;%c%cchar *exec_name;%c%cchar *exec_cmd;%c%cchar *str;%c%cint x;%c%cFILE *fd;%c%c%cx = %d;%c%cup = getenv(%c_%c);%c%cif(!strstr(up, %c./Sully_%c))%c%c%cx++;%c%cif(x <= 0)%c%c%creturn(0);%c%casprintf(&files_name, %c./Sully_%%d.c%c, x - 1);%c%casprintf(&exec_name, %c./Sully_%%d%c, x - 1);%c%casprintf(&exec_cmd, %cclang -Wall -Wextra -Werror -o Sully_%%d Sully_%%d.c ; %%s %c, x - 1, x - 1, exec_name);%c%cfd = fopen(files_name, %cw+%c);%c%cstr = %c%s%c;%c%cfprintf(fd,str, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10, 9, x - 1, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 34, 34 ,10, 9, 34, str, 34, 10, 9, 10, 9, 10, 9, 10, 9, 9,10, 10);%c%cfclose(fd);%c%cif(x - 1 != 0)%c%c%csystem(exec_cmd);%c}%c";
	fprintf(fd,str, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 10, 9, x - 1, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 9, 10, 9, 10, 9, 9, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 34, 34, 10, 9, 34, 34 ,10, 9, 34, str, 34, 10, 9, 10, 9, 10, 9, 10, 9, 9,10, 10);
	fclose(fd);
	if(x - 1 != 0)
		system(exec_cmd);
}
