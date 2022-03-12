#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1])
{
	const char *str1 = "abc";
	puts("const char * variable before");
	puts(str1);

	const char *str2 = "def";
	str1 = str2;
	puts("const char * variable changed by other variable");
	puts(str1);

	str1 = "ghi";
	puts("const char * variable changed by other literal");
	puts(str1);

	char const *str3 = "jkl";
	puts("char const * variable before");
	puts(str3);

	str3 = "mno";
	puts("char const * variable changed by other too");
	puts(str3);

	const char *const str4 = "pqr";
	// str4 = "wxy";
	puts("const char *const type can't change variable!");

	char const *const str5 = "stu";
	// str5 = "wxy";
	puts("char const *const type can't change too");
	
	const char *str6[] = { "aa", "bb", "cc" };
	puts("const char * var[] variable second element before");
	puts(str6[1]);
	
	str6[1] = "dd";
	puts("const char * var[] variable second element changed by other");
	puts(str6[1]);

	const char *const str7[] = { "dd", "ee", "ff" };
	// str7[1] = "gg";
	puts("const char *const var[] type can't change array elements!");

	return EXIT_SUCCESS;
}
