#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void add_two(int foo, int bar)
{
	__asm__ __volatile__(
		"addl %%ebx,%%eax;\n"
		: "=a"(foo)
		: "a"(foo), "b"(bar)
		);
	printf("foo + bar = %d\n", foo);
}

static void atomic_add_two(int foo, int bar)
{
	__asm__ __volatile__(
		"lock;\n"
		"addl %1,%0;\n"
		: "=m"(foo)
		: "ir"(bar), "m"(foo)
		);
	printf("atomic foo + bar = %d\n", foo);
}

static void decrement_compare(int foo)
{
	bool comp = 0;
	__asm__ __volatile__(
		"decl %0;\n"
		"sete %1;\n"
		: "=m"(foo), "=q"(comp)
		: "m"(foo)
		: "memory"
		);
	if (comp) {
		puts("decrement result is zero");
	} else {
		puts("decrement result is not zero");
	}
}

static void bit_set(int foo, int pos)
{
	__asm__ __volatile__(
		"btsl %1,%0;\n"
		: "=m"(foo)
		: "ir"(pos)
		: "cc"
		);
	printf("foo result = %d\n", foo);
}

static void copy_str(char *dest, const char *src)
{
	int d0, d1, d2;
	__asm__ __volatile__(
		"1:\tlodsb;\n"
		"stosb;\n"
                "testb %%al,%%al;\n"
                "jne 1b;\n"
                : "=&S"(d0), "=&D"(d1), "=&a"(d2)
                : "0"(src), "1"(dest) 
                : "memory"
		);
}

int main(int argc, char *argv[argc + 1])
{
	add_two(2, 3);
	atomic_add_two(2, 3);
	decrement_compare(2);
	decrement_compare(1);
	bit_set(4, 1);
	
	const char *src_str = "abc";
	char dest_str[16] = {0};
	copy_str(dest_str, src_str);
	puts(dest_str);
	
	return EXIT_SUCCESS;
}
