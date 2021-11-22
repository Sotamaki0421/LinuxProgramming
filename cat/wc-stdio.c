#include <stdio.h>
#include <stdlib.h>

static void do_word_count(FILE *f);

int main(int argc, char *argv[]){
	
	if (argc == 1){
		do_word_count(stdin);
	}
	else{
		int i;
		for(i = 1;i < argc;i++){
			FILE *f = fopen(argv[i], "r");
			if (!f) {
				perror(argv[i]);
				exit(1);
			}
			do_word_count(f);
			fclose(f);
			
		}
	}
	exit(1);
}

static void do_word_count(FILE *f)
{
	int c;
	int prev = '\n';
	unsigned int cnt = 0;
	while((c = fgetc(f) )!= EOF){
		if (c == '\n') cnt++;
		prev = c;
	}
	if (prev != '\n') cnt++;
	printf("%d\n", cnt);
}
