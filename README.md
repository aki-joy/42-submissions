*This project has been created as part of the 42 curriculum by <atajima>*


**Description**
今後の自分のっプロジェクトで使う関数をまとめたライブラリを作成しました。中身としては、標準ライブラリにある関数を再実装したもの、42内で使う自作関数という主に二つのジャンルに分けられます。
一つ目の方の再実装の方に関しては、元の関数の動きとなるべく近い動きをするように作成しました。
二つ目の、自作関数の方では、subjectにあるdescriptionに則って、なるべく安全性を高めたコードを書きました。
次に関数て主に扱う内容の説明です。

***ft_is*の関数***
この文字がついてる関数に関しては、char型の文字が決められた範囲内にあるものかというのをチェックするものになっています。asciiによって判別しています。

***ft_lst*の関数***
listを扱った関数です。nodeに

main関数

atoi
```int main(void)
{
	char nbr[] = "  213a45";
	printf("%d\n", ft_atoi(nbr));
	return (0);
}```

itoa
```int	main(void)
{
	int nbr = 2147483647;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}```

putnbr_fd
```int main(void)
{
     int n = 123;
     int fd = 1;
     ft_putnbr_fd(n, fd);
     return (0);
}```

 split
```int	main(int argc, char **argv)
{
	char	**splited;
	int		i;
	int		count;

	i = 0;
	if (argc != 4)
		return (1);
	count = atoi(argv[3]);
	splited = ft_split(argv[1], argv[2][0]);
	while (i < count)
	{
		printf("%s\n", splited[i]);
		i++;
	}
	i = 0;
	while (i <= count)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (0);
}```

strjoin
```#include <stdio.h>

int	main(int argc, char **argv)
{
 	char	*joined;

 	if (argc != 3)
 		return (1);
 	joined = ft_strjoin(argv[1], argv[2]);
 	printf("%s\n", joined);
 	free(joined);
 	return (0);
}```

strlcat
```#include <stdio.h>
int	main(void)
{
 	char	dest[10] = "abc";
 	char	src[] = "def";
 	size_t	size = 6;

 	printf("%d\n", (int)ft_strlcat(dest, src, size));
 	printf("%s", dest);
 	return (0);
}```

strlcpy
```#include <stdio.h>

int	main(void)
{
 	char dest[10];
 	char src[] = "hello world";
 	size_t size = 4;
 	printf("%d\n", (int)ft_strlcpy(dest, src, size));
 	printf("%s", dest);
 	return (0);
}```

strnstr
```#include <stdio.h>
int main(void)
{
 	char heystack[] = "hello world";
 	char needle[] = "ll";
 	printf("%s", ft_strstr(heystack, needle));
 	return (0);
}```

 strtrim
```int	main(int argc, char **argv)
{
 	char	*trimmed;

 	if (argc != 3)
 		return (1);
 	trimmed = ft_strtrim(argv[1], argv[2]);
 	printf("%s\n", trimmed);
 	free(trimmed);
 	return (0);
}```

substr
```int	main(int argc, char **argv)
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
}```

 