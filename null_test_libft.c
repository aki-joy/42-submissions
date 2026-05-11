#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void	title(const char *s)
{
	printf("\n=== %s ===\n", s);
}

static void	show_str_ptr(const char *test, char *result, const char *original)
{
	if (result == NULL)
		printf("%-40s ft: NULL | original: %s\n", test, original);
	else if (*result == '\0')
		printf("%-40s ft: \"\\\\0\" | original: %s\n", test, original);
	else
		printf("%-40s ft: \"%s\" | original: %s\n", test, result, original);
}

static void	show_int(const char *test, int result, const char *original)
{
	printf("%-40s ft: %d | original: %s\n", test, result, original);
}

static void	show_size(const char *test, size_t result, const char *original)
{
	printf("%-40s ft: %zu | original: %s\n", test, result, original);
}

int	main(void)
{
	char	buf[10];

	title("strlen");
	show_size("ft_strlen(\"\")", ft_strlen(""), "0");
	/* show_size("ft_strlen(NULL)", ft_strlen(NULL), "segfault / undefined behavior"); */

	title("strchr / strrchr");
	show_str_ptr("ft_strchr(\"abc\", 'b')",
		ft_strchr("abc", 'b'), "pointer to 'b'");
	show_str_ptr("ft_strchr(\"abc\", '\\0')",
		ft_strchr("abc", '\0'), "pointer to '\\0'");
	/* show_str_ptr("ft_strchr(NULL, 'a')",
		ft_strchr(NULL, 'a'), "segfault / undefined behavior"); */
	/* show_str_ptr("ft_strrchr(NULL, 'a')",
		ft_strrchr(NULL, 'a'), "segfault / undefined behavior"); */

	title("strncmp");
	show_int("ft_strncmp(\"abc\", \"abc\", 3)",
		ft_strncmp("abc", "abc", 3), "0");
	show_int("ft_strncmp(\"abc\", \"abd\", 3)",
		ft_strncmp("abc", "abd", 3), "negative value");
	show_int("ft_strncmp(NULL, NULL, 0)",
		ft_strncmp(NULL, NULL, 0), "usually 0 because n == 0");
	/* show_int("ft_strncmp(NULL, \"abc\", 1)",
		ft_strncmp(NULL, "abc", 1), "segfault / undefined behavior"); */

	title("memcpy");
	memset(buf, 'X', sizeof(buf));
	show_str_ptr("ft_memcpy(buf, NULL, 0)",
		ft_memcpy(buf, NULL, 0), "buf / no access because n == 0");
	show_str_ptr("ft_memcpy(NULL, NULL, 0)",
		ft_memcpy(NULL, NULL, 0), "usually NULL / no access because n == 0");
	/* show_str_ptr("ft_memcpy(NULL, \"abc\", 3)",
		ft_memcpy(NULL, "abc", 3), "segfault / undefined behavior"); */

	title("memmove");
	memset(buf, 'X', sizeof(buf));
	show_str_ptr("ft_memmove(buf, NULL, 0)",
		ft_memmove(buf, NULL, 0), "buf / no access because n == 0");
	show_str_ptr("ft_memmove(NULL, NULL, 0)",
		ft_memmove(NULL, NULL, 0), "usually NULL / no access because n == 0");
	/* show_str_ptr("ft_memmove(NULL, \"abc\", 3)",
		ft_memmove(NULL, "abc", 3), "segfault / undefined behavior"); */

	title("memchr");
	show_str_ptr("ft_memchr(NULL, 'a', 0)",
		ft_memchr(NULL, 'a', 0), "NULL / no access because n == 0");
	/* show_str_ptr("ft_memchr(NULL, 'a', 1)",
		ft_memchr(NULL, 'a', 1), "segfault / undefined behavior"); */

	title("memcmp");
	show_int("ft_memcmp(NULL, NULL, 0)",
		ft_memcmp(NULL, NULL, 0), "0 / no access because n == 0");
	/* show_int("ft_memcmp(NULL, \"abc\", 1)",
		ft_memcmp(NULL, "abc", 1), "segfault / undefined behavior"); */

	title("strnstr");
	show_str_ptr("ft_strnstr(\"hello\", \"\", 0)",
		ft_strnstr("hello", "", 0), "haystack pointer");
	show_str_ptr("ft_strnstr(NULL, \"a\", 0)",
		ft_strnstr(NULL, "a", 0), "NULL / should not access haystack");
	show_str_ptr("ft_strnstr(NULL, \"\", 0)",
		ft_strnstr(NULL, "", 0), "haystack pointer, so NULL");
	/* show_str_ptr("ft_strnstr(NULL, \"a\", 1)",
		ft_strnstr(NULL, "a", 1), "segfault / undefined behavior"); */

	title("atoi");
	show_int("ft_atoi(\"\")", ft_atoi(""), "0");
	show_int("ft_atoi(\"   -42abc\")",
		ft_atoi("   -42abc"), "-42");
	/* show_int("ft_atoi(NULL)",
		ft_atoi(NULL), "segfault / undefined behavior"); */

	title("calloc");
	show_str_ptr("ft_calloc(0, 10)",
		ft_calloc(0, 10), "non-NULL or NULL allowed depending implementation");
	show_str_ptr("ft_calloc(10, 0)",
		ft_calloc(10, 0), "non-NULL or NULL allowed depending implementation");

	title("strdup");
	show_str_ptr("ft_strdup(\"\")",
		ft_strdup(""), "pointer to allocated empty string");
	/* show_str_ptr("ft_strdup(NULL)",
		ft_strdup(NULL), "segfault / undefined behavior"); */

	return (0);
}