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
- ft_isalpha　アルファベットかどうかをチェックする
- ft_isdigit　数字かどうかをチェックする
- ft_isalnum　アルファベットまたは数字かどうかをチェックする
- ft_isascii　ASCII文字かどうかをチェックする
- ft_isprint　表示可能な文字かどうかをチェックする

### String functions
- ft_strlen　文字列の長さを数える
- ft_strlcpy　文字列を指定したサイズまでコピーする
- ft_strlcat　文字列を指定したサイズまで連結する
- ft_strchr　文字列の中から指定した文字を先頭から探す
- ft_strrchr　文字列の中から指定した文字を後ろから探す
- ft_strncmp　2つの文字列を指定した文字数だけ比較する
- ft_strnstr　文字列の中から指定した文字列を指定範囲内で探す
- ft_strdup　文字列を新しく確保したメモリにコピーする
- ft_substr　文字列の一部を切り出して新しい文字列を作る
- ft_strjoin　2つの文字列を連結して新しい文字列を作る
- ft_strtrim　文字列の先頭と末尾から指定した文字を取り除く
- ft_split　文字列を指定した区切り文字で分割する

### Memory functions
- ft_memset　メモリ領域を指定した値で埋める
- ft_bzero　メモリ領域を0で埋める
- ft_memcpy　メモリ領域を指定したバイト数だけコピーする
- ft_memmove　重なりがある可能性のあるメモリ領域をコピーする
- ft_memchr　メモリ領域の中から指定した値を探す
- ft_memcmp　2つのメモリ領域を指定したバイト数だけ比較する
- ft_calloc　メモリを確保し、その中身を0で初期化する

### Output functions
- ft_putchar_fd　指定したファイルディスクリプタに1文字を出力する
- ft_putstr_fd　指定したファイルディスクリプタに文字列を出力する
- ft_putendl_fd　指定したファイルディスクリプタに文字列と改行を出力する
- ft_putnbr_fd　指定したファイルディスクリプタに数値を出力する

### Linked list functions
- ft_lstnew　新しいリスト要素を作る
- ft_lstadd_front　リストの先頭に要素を追加する
- ft_lstsize　リストの要素数を数える
- ft_lstlast　リストの最後の要素を取得する
- ft_lstadd_back　リストの末尾に要素を追加する
- ft_lstdelone　リストの要素を1つ削除する
- ft_lstclear　リスト全体を削除する
- ft_lstiter　リストの各要素に関数を適用する
- ft_lstmap　リストの各要素に関数を適用して新しいリストを作る


## main関数
下に幾つかのmain関数を用意しました。testerとは別に個別でチェックしたい場合に使ってください。

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