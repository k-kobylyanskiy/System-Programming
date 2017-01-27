#include "../include/wc.h"

int count_digits(int number){
	int count = 0;
	while(number){
		number /= 10;
		count++;
	}
	return count;
}

char* int_to_char(int number){
	int count = 0, i;
	char* buffer;
	count = count_digits(number);	
	buffer = malloc(count+1);
	buffer[count] = '\n';
	for(i = 0; i < count; i++){
		buffer[count - i - 1] = (number % 10) + 48;
		number /= 10;
	}
	return buffer;
}

int main(int argc, char** argv){
	ssize_t ret;
	int state = 1;
	int count = 0;
	char* buffer;
	char* number;	
	
	/* TODO add option handle */

	if(argc == 1){
		buffer = malloc(10);

		while(state){
			ret = read(STDIN, buffer + count, 1);
			if(buffer[count] == '\n'){
				state = 0;
			}
			count++;
			if(count > sizeof(buffer)){
				buffer = realloc(buffer, count * 2);
			}
		}
		number = malloc(count_digits(count) + 1);
		number = int_to_char(count);
		ret = write(STDOUT, number, sizeof(buffer));
	} else {
		/* TODO write function to handle all files */	
		printf("need to handle %d files", argc - 1);
	}
	return 0;
}
