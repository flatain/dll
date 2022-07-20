#include <stdio.h>

#define MAX_MAIN_QUEUE 7//max = 11
#define MAX_SUB_QUEUE 3
#define ARRAY_SIZE (MAX_MAIN_QUEUE * 2)

int ARRAY[ARRAY_SIZE] = {0};
int main_queue_size = MAX_MAIN_QUEUE;
int queue1_size = 0;
int queue2_size = 0;
int depth = 0;
int flag_one = 1, flag_two = 1, flag_three = 1, flag_four = 1;
long int count = 0;

char select_option(void){
	if((main_queue_size | queue1_size | queue2_size) == 0){
		count ++;
		// printf("%d %d %d %d %d %d %d %d\n", ARRAY[0], ARRAY[1], ARRAY[2], ARRAY[3], ARRAY[4], ARRAY[5], ARRAY[6], ARRAY[7]);
		return 0;
	}
	// if(depth == ARRAY_SIZE -1 && queue1_size == 2){
	// 	printf("%d %d %d %d %d %d %d %d\n", ARRAY[0], ARRAY[1], ARRAY[2], ARRAY[3], ARRAY[4], ARRAY[5], ARRAY[6], ARRAY[7]);
	// 	return 0;
	// }
	if(main_queue_size > 0){
		main_queue_size -= 1;
		ARRAY[depth++] = 1;
		select_option();
		depth--;
		main_queue_size += 1;
	}
	if(queue1_size < MAX_SUB_QUEUE && main_queue_size > 0){
		queue1_size += 1;
		main_queue_size -= 1;
		ARRAY[depth++] = 2;
		select_option();
		depth--;
		queue1_size -= 1;
		main_queue_size += 1;
	}
	if(queue2_size < MAX_SUB_QUEUE && main_queue_size > 0){
		queue2_size += 1;
		main_queue_size -= 1;
		ARRAY[depth++] = 3;
		select_option();
		depth--;
		queue2_size -= 1;
		main_queue_size += 1;
	}
	if(queue1_size > 0){
		queue1_size -= 1;
		ARRAY[depth++] = 4;
		select_option();
		depth--;
		queue1_size += 1;
	}
	if(queue2_size > 0){
		queue2_size -= 1;
		ARRAY[depth++] = 5;
		select_option();
		depth--;
		queue2_size += 1;
	}

	if(ARRAY[0] == 1 && flag_one == 1){
		// printf("1\n");
		flag_one = 0;
	}
	if(ARRAY[0] == 2 && flag_two == 1){
		// printf("2\n");
		flag_two = 0;
	}
	if(ARRAY[0] == 3 && flag_three == 1){
		// printf("3\n");
		flag_three = 0;
	}

}


void main(void){
	select_option();
	printf("count = %ld\n", count);
}	
