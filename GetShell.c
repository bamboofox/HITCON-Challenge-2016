#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long hashcode = 0xddaa1234;
char *keypt = NULL;

void print_bomb(){
	system("cat /home/ctf/graph");
	fflush(stdout);
}

void md5bof(char *mid){
    char overflow[40];
	keypt = mid;
    printf("Start overflow!!!! : ");
    scanf("%s", overflow);
    int i = 0;
    unsigned long result = 0;
    int *convert = (int*)keypt;
    for(i = 0; i < 5; ++i){
        result += convert[i];
    }
    if(result == hashcode){
        system("/bin/sh");
    }
    else{
        printf("Oh no, plz try again!!\n");
	}
}


int main(){
	setvbuf(stdout, 0LL, 2, 0LL);
	setvbuf(stdin, 0LL, 1, 0LL);
	char choice;
	print_bomb();
	printf("**********************************************************\n");
	printf("* Emergency! Emergency!                                  *\n");
	printf("* There is a dark-matter-bomb going to exploit!!         *\n");
	printf("* You, the one who can save the world need to solve this *\n");
	printf("* buffer overflow with md5 problem to find the passcode! *\n");
	printf("**********************************************************\n");
	printf("\nWould you like to take this important task?(y/n)");
	scanf("%c", &choice);
	getchar();
	if(choice == 'y' | choice == 'Y'){
		printf("Then try to overflow me!!!\n");
		char blank[20] = {0};
		md5bof(blank);
	}
	else
		printf("The bomb is gonna to explode.....\n");
}
