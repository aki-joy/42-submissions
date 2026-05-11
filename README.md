*This project has been created as part of the 42 curriculum by <atajima>*


# Description
今後の自分のプロジェクトで使う関数をまとめたライブラリを作成しました。中身としましては大きく分けて二種類、標準ライブラリにある関数を再実装したもの、42内で使う自作関数という主に二つのジャンルに分けられます。
一つ目の方の再実装の方に関しては、元の関数の動きとなるべく同じ動きをするように作成しました。
二つ目の、自作関数の方では、subjectにあるdescriptionに則って、なるべく安全性を高めたコードを書きました。

# Instruction
今回のプロジェクトには`makefile`があります。

ライブラリを作成するには以下のコマンドを使用します。
```bash
make
```
libft.aが作成されます。

オブジェクトファイルを削除します。
```bash
make claen
```
その後実行ファイルを削除します。
```bash
make fclean
```
# Resources

## AIの使用用途に関して
使用用途としましては、関数の仕様、定義及び動作確認で主に使用しました。また理解を助ける補助的な役割としても一部使用しました。実装及び最終確認につきましては自分自身で行いました。

## その他
- man page
- MANPAGES.ORG
- IBM
- Qiita  
等を主に使用しました。使用用途としましては、関数のプロトタイプ等定義の確認です。その他Qiitaに関しましては、再実装の参考にした部分もふくまれております。


### 3. 関数一覧

### Character checks
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint

### String functions
- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_strdup
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split

### Memory functions
- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_calloc

### Output functions
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked list functions
- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap


### atoi
```c
#include <stdio.h>

int main(void)
{
	char nbr[] = "  213a45";
	printf("%d\n", ft_atoi(nbr));
	return (0);
}
```
### itoa
```c
#include <stdio.h>

int	main(void)
{
	int nbr = 2147483647;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
```
### split
```c
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world and see you later";
	char	c = ' ';
	char	**splited;
	int		i = 0;
	splited = ft_split(str, c);
	while (splited[i])
	{
		printf("%s\n", splited[i]);
		i++;
	}
	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (0);
}
```
### strlcat
```c
#include <stdio.h>

int	main(void)
{
 	char	dest[10] = "abc";
 	char	src[] = "def";
 	size_t	size = 6;

 	printf("%d\n", (int)ft_strlcat(dest, src, size));
 	printf("%s", dest);
 	return (0);
}
```
### strlcpy
```c
#include <stdio.h>

int	main(void)
{
 	char	dest[10];
 	char	src[] = "hello world";
 	size_t	size = 4;
 	printf("%d\n", (int)ft_strlcpy(dest, src, size));
 	printf("%s", dest);
 	return (0);
}
```
### strnstr
```c
#include <stdio.h>
int main(void)
{
 	char	haystack[] = "hello world";
 	char	needle[] = "ll";
	int		len = 3;
 	printf("%s", ft_strnstr(haystack, needle, len));
 	return (0);
}
```
### strtrim
```c
#include <stdio.h>

int	main(int argc, char **argv)
{
 	char	*trimmed;

 	if (argc != 3)
 		return (1);
 	trimmed = ft_strtrim(argv[1], argv[2]);
 	printf("%s\n", trimmed);
 	free(trimmed);
 	return (0);
}
```
### substr
```c
#include <stdio.h>

int	main(int argc, char **argv)
{
 	size_t		start;
 	size_t		len;
 	char	*sub;

 	if (argc != 4)
 		return (0);
 	start = atoi(argv[2]);
 	len = atoi(argv[3]);
 	sub = ft_substr(argv[1], start, len);
 	if (!sub)
 		return (1);
 	printf ("%s\n", sub);
 	free(sub);
 	return (0);
}
```