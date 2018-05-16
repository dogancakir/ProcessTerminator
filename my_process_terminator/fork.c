#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int i ;
	
	for(i = 0; i < 2; i++){
	int f = fork();
	if(f != 0){
		f = fork();
		if(f != 0)
		{
		break;
		}
	}
	}
	sleep (100);
	scanf("%i",i);
return 0;	
}
