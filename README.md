*This project has been created as part of the 42 curriculum by <atajima>*


# Description
今後の自分のっプロジェクトで使う関数をまとめたライブラリを作成しました。中身としては、標準ライブラリにある関数を再実装したもの、42内で使う自作関数という主に二つのジャンルに分けられます。
一つ目の方の再実装の方に関しては、元の関数の動きとなるべく近い動きをするように作成しました。
二つ目の、自作関数の方では、subjectにあるdescriptionに則って、なるべく安全性を高めたコードを書きました。
次に関数て主に扱う内容の説明です。

# Instruction
今回のプロジェクトにはmakefileがあるので、makeでオブジェクトファイルを作成します。make clean -> make fcleanをすると、実行ファイル、オブジェクトファイルともに消すことができます。

# Resources

##　AIの使用用途に関して
今回のプロジェクトで主にAIを使用した部分としましては、自作関数の定義チェック、動作確認の最終工程として使いました。また、わからない部分の補助的な教材としても使用しました。

## その他
man page
MANPAGES.ORG
IBM
Qiita
等を主に使用しました。使用用途としましては、関数のプロトタイプ等定義の確認です。その他Qiitaに関しましては、再実装の参考にした部分もあります。

# 主な関数の説明

## ft_is*の関数

この文字がついてる関数に関しては、char型の文字が決められた範囲内にあるものかというのをチェックするものになっています。asciiによって判別しています。

## ft_lst*の関数

linked listを扱った関数です。新しいnodeを作成したり、追加、削除などといった動作をする関数を作成しました。
nodeの型(構造体)はヘッダーファイルに書いてある通りです。

## ft_str*の関数

str系の関数は文字通り文字列を扱う関数郡で、ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_strmapi, ft_striteriの6つの関数は標準関数ではなく自作関数です。
以下に簡単に上の関数の仕様をまとめました。

## ft_mem*の関数

mem系の関数は文字列をメモリのバイト列として扱います。そのため何バイト分見るのかという指標が引数として渡される。

## ft_*_fdの関数

fdで終わる関数に関して、fdとはファイルディスクリプタであり、出力先のことです。つまり、いままでだったら標準出力としていたものをほかのところに出力できるというものです。　0, 1, 2のこの3つの数字は、システムの仕様として決まっている標準ファイルディスクリプタで、0は標準入力、1は標準出力、2は標準エラー出力です。



### ft_substr
もとの文字列を、指定されたバイト数分だけ新しく確保したメモリに書き写す関数。

### ft_sttrjoin
2つの文字列を確保したメモリに連結して書き写す関数。

### ft_strtrim
もとの文字列から、指定された文字が文字列の先頭もしくは終わりにある場合、それを除いた文字列を作成し返す関数。

### ft_split
渡された長い文字列を、区切り文字が含まれている場合に区切り文字ごとにわけて、別の文字列として分割する関数。

### ft_strmapi
渡された文字列の各文字にたいして渡された関数を適用して、それを新しく文字列として作る関数。

### ft_striteri
渡された文字列の各文字にたいして渡された関数を適用して、もとの文字列を書き換える関数。



main関数

atoi
```c
int main(void)
{
	char nbr[] = "  213a45";
	printf("%d\n", ft_atoi(nbr));
	return (0);
}
```

itoa
```c
int	main(void)
{
	int nbr = 2147483647;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
```

putnbr_fd
```c
int main(void)
{
     int n = 123;
     int fd = 1;
     ft_putnbr_fd(n, fd);
     return (0);
}
```

 split
```c
int	main(int argc, char **argv)
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
}
```

strjoin
```c
#include <stdio.h>

int	main(int argc, char **argv)
{
 	char	*joined;

 	if (argc != 3)
 		return (1);
 	joined = ft_strjoin(argv[1], argv[2]);
 	printf("%s\n", joined);
 	free(joined);
 	return (0);
}
```

strlcat
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

strlcpy
```c
#include <stdio.h>

int	main(void)
{
 	char dest[10];
 	char src[] = "hello world";
 	size_t size = 4;
 	printf("%d\n", (int)ft_strlcpy(dest, src, size));
 	printf("%s", dest);
 	return (0);
}
```

strnstr
```c
#include <stdio.h>
int main(void)
{
 	char heystack[] = "hello world";
 	char needle[] = "ll";
 	printf("%s", ft_strstr(heystack, needle));
 	return (0);
}
```

 strtrim
```c
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

substr
```c
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

 