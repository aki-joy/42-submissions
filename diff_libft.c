#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef USE_FT
# include "libft.h"
# define F_ISALPHA ft_isalpha
# define F_ISDIGIT ft_isdigit
# define F_ISALNUM ft_isalnum
# define F_ISASCII ft_isascii
# define F_ISPRINT ft_isprint
# define F_STRLEN ft_strlen
# define F_MEMSET ft_memset
# define F_BZERO ft_bzero
# define F_MEMCPY ft_memcpy
# define F_MEMMOVE ft_memmove
# define F_STRLCPY ft_strlcpy
# define F_STRLCAT ft_strlcat
# define F_TOUPPER ft_toupper
# define F_TOLOWER ft_tolower
# define F_STRCHR ft_strchr
# define F_STRRCHR ft_strrchr
# define F_STRNCMP ft_strncmp
# define F_MEMCHR ft_memchr
# define F_MEMCMP ft_memcmp
# define F_STRNSTR ft_strnstr
# define F_ATOI ft_atoi
# define F_CALLOC ft_calloc
# define F_STRDUP ft_strdup
#else
# define F_ISALPHA isalpha
# define F_ISDIGIT isdigit
# define F_ISALNUM isalnum
# define F_ISASCII isascii
# define F_ISPRINT isprint
# define F_STRLEN strlen
# define F_MEMSET memset
# define F_BZERO bzero
# define F_MEMCPY memcpy
# define F_MEMMOVE memmove
# define F_STRLCPY strlcpy
# define F_STRLCAT strlcat
# define F_TOUPPER toupper
# define F_TOLOWER tolower
# define F_STRCHR strchr
# define F_STRRCHR strrchr
# define F_STRNCMP strncmp
# define F_MEMCHR memchr
# define F_MEMCMP memcmp
# define F_STRNSTR strnstr
# define F_ATOI atoi
# define F_CALLOC calloc
# define F_STRDUP strdup
#endif

static int	sign(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static void	print_bytes(const unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%02x", s[i]);
		if (i + 1 < n)
			printf(" ");
		i++;
	}
	printf("\n");
}

static long	offset_str(const char *base, const char *ptr)
{
	if (!ptr)
		return (-1);
	return (ptr - base);
}

static long	offset_mem(const unsigned char *base, const void *ptr)
{
	if (!ptr)
		return (-1);
	return ((const unsigned char *)ptr - base);
}

static void	test_is_functions(void)
{
	int	cases[] = {-1, 0, 8, 9, 10, 13, 31, 32, '0', '9', 'A',
		'Z', 'a', 'z', 127, 128, 255};
	size_t	i;

	printf("== is functions ==\n");
	i = 0;
	while (i < sizeof(cases) / sizeof(cases[0]))
	{
		printf("%d: %d %d %d %d %d\n",
			cases[i],
			!!F_ISALPHA(cases[i]),
			!!F_ISDIGIT(cases[i]),
			!!F_ISALNUM(cases[i]),
			!!F_ISASCII(cases[i]),
			!!F_ISPRINT(cases[i]));
		i++;
	}
}

static void	test_strlen(void)
{
	printf("== strlen ==\n");
	printf("%zu\n", F_STRLEN(""));
	printf("%zu\n", F_STRLEN("a"));
	printf("%zu\n", F_STRLEN("hello"));
	printf("%zu\n", F_STRLEN("abc\0def"));
}

static void	test_memset_bzero(void)
{
	unsigned char	buf[12];

	printf("== memset bzero ==\n");
	memset(buf, 0xaa, sizeof(buf));
	F_MEMSET(buf, 0x42, 5);
	print_bytes(buf, sizeof(buf));
	memset(buf, 0xaa, sizeof(buf));
	F_MEMSET(buf, 300, 5);
	print_bytes(buf, sizeof(buf));
	memset(buf, 0xaa, sizeof(buf));
	F_BZERO(buf + 2, 6);
	print_bytes(buf, sizeof(buf));
}

static void	test_memcpy(void)
{
	unsigned char	src[] = {0, 1, 2, 3, 4, 5, 255};
	unsigned char	dst[10];

	printf("== memcpy ==\n");
	memset(dst, 0xaa, sizeof(dst));
	F_MEMCPY(dst, src, 7);
	print_bytes(dst, sizeof(dst));
	memset(dst, 0xaa, sizeof(dst));
	F_MEMCPY(dst, src, 0);
	print_bytes(dst, sizeof(dst));
}

static void	test_memmove(void)
{
	unsigned char	buf1[] = "0123456789";
	unsigned char	buf2[] = "0123456789";
	unsigned char	buf3[] = "0123456789";

	printf("== memmove ==\n");
	F_MEMMOVE(buf1 + 2, buf1, 6);
	print_bytes(buf1, sizeof(buf1));
	F_MEMMOVE(buf2, buf2 + 2, 6);
	print_bytes(buf2, sizeof(buf2));
	F_MEMMOVE(buf3, buf3, 6);
	print_bytes(buf3, sizeof(buf3));
}

static void	test_strlcpy_strlcat(void)
{
	char	buf[20];
	size_t	ret;

	printf("== strlcpy ==\n");
	memset(buf, 'X', sizeof(buf));
	ret = F_STRLCPY(buf, "hello", 20);
	printf("%zu [%s]\n", ret, buf);
	memset(buf, 'X', sizeof(buf));
	ret = F_STRLCPY(buf, "hello", 4);
	printf("%zu [%s]\n", ret, buf);
	memset(buf, 'X', sizeof(buf));
	ret = F_STRLCPY(buf, "hello", 0);
	printf("%zu ", ret);
	print_bytes((unsigned char *)buf, 8);

	printf("== strlcat ==\n");
	strcpy(buf, "abc");
	ret = F_STRLCAT(buf, "DEF", 20);
	printf("%zu [%s]\n", ret, buf);
	strcpy(buf, "abc");
	ret = F_STRLCAT(buf, "DEF", 5);
	printf("%zu [%s]\n", ret, buf);
	strcpy(buf, "abc");
	ret = F_STRLCAT(buf, "DEF", 0);
	printf("%zu [%s]\n", ret, buf);
}

static void	test_toupper_tolower(void)
{
	int	cases[] = {-1, 0, 'A', 'Z', 'a', 'z', '[', '`', '{', 127, 255};
	size_t	i;

	printf("== toupper tolower ==\n");
	i = 0;
	while (i < sizeof(cases) / sizeof(cases[0]))
	{
		printf("%d: %d %d\n",
			cases[i],
			F_TOUPPER(cases[i]),
			F_TOLOWER(cases[i]));
		i++;
	}
}

static void	test_strchr_strrchr(void)
{
	const char	*s = "abca";

	printf("== strchr strrchr ==\n");
	printf("%ld\n", offset_str(s, F_STRCHR(s, 'a')));
	printf("%ld\n", offset_str(s, F_STRCHR(s, 'b')));
	printf("%ld\n", offset_str(s, F_STRCHR(s, 'x')));
	printf("%ld\n", offset_str(s, F_STRCHR(s, '\0')));
	printf("%ld\n", offset_str(s, F_STRRCHR(s, 'a')));
	printf("%ld\n", offset_str(s, F_STRRCHR(s, 'b')));
	printf("%ld\n", offset_str(s, F_STRRCHR(s, 'x')));
	printf("%ld\n", offset_str(s, F_STRRCHR(s, '\0')));
}

static void	test_strncmp_memcmp(void)
{
	unsigned char	a1[] = {0, 1, 2, 3, 255};
	unsigned char	a2[] = {0, 1, 2, 4, 0};

	printf("== strncmp memcmp ==\n");
	printf("%d\n", sign(F_STRNCMP("abc", "abc", 3)));
	printf("%d\n", sign(F_STRNCMP("abc", "abd", 3)));
	printf("%d\n", sign(F_STRNCMP("abd", "abc", 3)));
	printf("%d\n", sign(F_STRNCMP("abc", "ab", 3)));
	printf("%d\n", sign(F_STRNCMP("abc", "xyz", 0)));
	printf("%d\n", sign(F_MEMCMP(a1, a2, 0)));
	printf("%d\n", sign(F_MEMCMP(a1, a2, 3)));
	printf("%d\n", sign(F_MEMCMP(a1, a2, 4)));
	printf("%d\n", sign(F_MEMCMP(a1, a2, 5)));
}

static void	test_memchr(void)
{
	unsigned char	s[] = {0, 1, 2, 3, 255, 0, 4};

	printf("== memchr ==\n");
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 0, 7)));
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 255, 7)));
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 300, 7)));
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 4, 6)));
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 4, 7)));
	printf("%ld\n", offset_mem(s, F_MEMCHR(s, 1, 0)));
}

static void	test_strnstr(void)
{
	const char	*s = "hello world";

	printf("== strnstr ==\n");
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "hello", 11)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "world", 11)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "world", 10)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "", 0)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "", 5)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "x", 11)));
	printf("%ld\n", offset_str(s, F_STRNSTR(s, "lo w", 8)));
}

static void	test_atoi(void)
{
	const char	*cases[] = {
		"",
		"0",
		"123",
		"   123",
		"\t\n\r\v\f 42",
		"-42",
		"+42",
		"+-42",
		"--42",
		"42abc",
		"abc42",
		"2147483647",
		"-2147483648",
		NULL
	};
	size_t		i;

	printf("== atoi ==\n");
	i = 0;
	while (cases[i])
	{
		printf("[%s] => %d\n", cases[i], F_ATOI(cases[i]));
		i++;
	}
}

static void	test_calloc_strdup(void)
{
	unsigned char	*p;
	char			*s;

	printf("== calloc strdup ==\n");
	p = F_CALLOC(5, 4);
	if (!p)
		printf("calloc failed\n");
	else
	{
		print_bytes(p, 20);
		free(p);
	}
	s = F_STRDUP("");
	printf("[%s]\n", s);
	free(s);
	s = F_STRDUP("hello");
	printf("[%s]\n", s);
	free(s);
}

int	main(void)
{
	test_is_functions();
	test_strlen();
	test_memset_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy_strlcat();
	test_toupper_tolower();
	test_strchr_strrchr();
	test_strncmp_memcmp();
	test_memchr();
	test_strnstr();
	test_atoi();
	test_calloc_strdup();
	return (0);
}