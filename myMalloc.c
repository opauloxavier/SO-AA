
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024
#define align4 (x)(((((x) -1) >>2)<<2)+4)
#define BLOCK_SIZE sizeof (struct s_block)
typedef struct s_block *t_block;

struct s_block{
	size_t size;
	t_block next;
	int free;
};

void *p;
void *base=NULL;


t_block find_block ( t_block *last , size_t size ){
	
	t_block b = base;
	
	while (b && !(b->free && b->size >= size)) {
		*last = b;
		b = b->next;
	}

	return (b);
}

void *myMallocInit(size_t size){

	p = sbrk(size);

	return p;
}

void *giveMalloc(size_t size){

}

int main(){

	int *abc = myMallocInit(sizeof(int)*4);

	t_block b;

	b = sbrk(0);

	return 0;
}