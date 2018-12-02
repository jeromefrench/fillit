/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:19:14 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/02 17:20:31 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include "fcntl.h"

void masuper_fonction(unsigned int index, char *str);
char	maseconde_super(char c);
char	supersuper_f(unsigned int index, char c);

int		main(void)
{
	printf("slt1\n");


printf("La fonction lst_new\n");
char *data = "hello I'm the data";
t_list *l = ft_lstnew(data, ft_strlen(data) + 1);
printf("la data =%s\n", l->content);



//printf("Le nombre =%s\n", ft_itoa(0));

/*
printf("La fonction strlcat\n");
char	dst_lcat[50];
char	src_lcat[50];
ft_strcpy(dst_lcat, "aaa");
ft_strcpy(src_lcat, "bbbb");
int b =ft_strlcat(dst_lcat, src_lcat, 0);
printf("La strlca =%s\n", dst_lcat);
printf("%d\n", b);

printf("\n\n\n");

printf("La fonction strlcat officiel\n");
char	tdst_lcat[50];
char	tsrc_lcat[50];
ft_strcpy(tdst_lcat, "aaa");
ft_strcpy(tsrc_lcat, "bbbb");
int a = strlcat(tdst_lcat, tsrc_lcat, 0);
printf("La strlca =%s\n", tdst_lcat);
printf("%d\n", a);
*/


/*
	printf("\nFonction strcat\n");
	char	cat_src[50];
	char	cat_dest[50];
	strcpy(cat_src, "je suis la source");
	strcpy(cat_dest, "je suis la dest");
	strcat(cat_dest, cat_src);
	printf("%s\n", cat_dest);
*/

/*
	printf("\nFonction toupper\n");
	printf("%c\n", (char)ft_toupper('a'));
*/

/*
	printf("\nFonction tolowerr\n");
	printf("%c\n", (char)ft_tolower('A'));
*/

/*
	printf("\nFonction isprint\n");
	printf("%d\n", ft_isprint('a'));
*/

/*
	printf("\nFonction isascii\n");
	printf("%d\n", ft_isascii('a'));
*/

/*
	printf("\nFonction is alnum\n");
	printf("%d", ft_isalnum('!'));
*/

/*
	printf("\nFonction isdigit\n");
	printf("%d", ft_isdigit('a'));
*/

/*
		printf("\nFonction isalpha\n");
		printf("%d", ft_isalpha('1'));
*/

/*
		printf("\nFonction strcmp\n");
		char	str1[50];
		char	str2[50];

		strcpy(str1, "abcdefgh");
		strcpy(str2, "abcdwxyz");
		printf("La dif :%d\n", ft_strncmp(str1, str2, 4));
		printf("La dif :%d\n", strncmp(str1, str2, 4));
*/

/*
	printf("\nFonction strlen\n");
	char	str_len[50];

	strcpy(str_len, "slt les gilet jaunes");
	printf("la taille :%zu\n", ft_strlen(str_len));
*/

/*
	printf("\nLa fonction ft_putchar\n");
	ft_putchar('a');
	printf("\nLa fonction putstr\n");
	ft_putstr("slt les jilets jaune");
*/

/*
	printf("\nLa fonction strcpy\n");
	char	str_cpy[50];
	ft_strcpy(str_cpy, "slt toi");
	printf("%s\n", str_cpy);
*/

/*
	printf("\nLa fonction strncpy\n");
	char	str_ncpy[50];
	ft_strncpy(str_ncpy, "abcdefghij", 20);
	printf("%s\n", str_ncpy);
*/
/*
	printf("La fonction strncat\n");
	char	str_ncat1[50];
	char	str_ncat2[50];
	ft_strcpy(str_ncat1, "debut");
	ft_strcpy(str_ncat2, "fin");
	ft_strncat(str_ncat1, str_ncat2, 2);
	printf("%s\n", str_ncat1);
*/
/*
	printf("\nLa fonction strdup\n");
	char	*str_dup;
	str_dup = ft_strdup("Gilets jaune");
	ft_putstr(str_dup);
*/
/*
	printf("\nLa fonction memset\n");
	char	str_set[50];
	ft_strcpy(str_set, "Macron demission");
	ft_memset(str_set, 'j', 3);
	ft_putstr(str_set);
*/
/*
	printf("La fonction bzero\n");
	char	str_bzero[50];
	ft_strcpy(str_bzero, "Macron a la guillotine");
	ft_bzero(str_bzero, 3);
	ft_putstr(str_bzero);
*/
		/*
	printf("La fonction memcpy\n");
	char mem_cpy1[50];
	char mem_cpy2[50];
	ft_strcpy(mem_cpy1, "slt");
	ft_strcpy(mem_cpy2, "toi");
	ft_memcpy(mem_cpy1, mem_cpy2, 2);
	ft_putstr(mem_cpy1);
*/

/*
	printf("La fonction memccpy\n");
	char mem_ccpy1[50];
	char mem_ccpy2[50];
	ft_strcpy(mem_ccpy1, "slt");
	ft_strcpy(mem_ccpy2, "toi");
	ft_memcpy(mem_ccpy1, mem_ccpy2, 2);
	ft_putstr(mem_ccpy1);
*/
/*
		printf("slt\n");
		char	str1[] = "123456789";
		char	str11[] = "123456789";
		char	str2[] = "Quiz";
		char	str22[] = "Quiz";
		ft_memmove(&str1[3], &str1[3] + 2, 4);
		memmove(&str11[3], &str11[3] + 2, 4);
		printf("=%s\n", &str1[3]);
		printf("=%s\n", &str11[3]);
		printf("slt\n");
*/

/*
	printf("La fonction memmove\n");
	char mem_move1[50];
	char mem_move2[50];
	ft_strcpy(mem_move1, "abcdefghij");
	ft_strcpy(mem_move2, "abcdefghij");
	ft_memmove(mem_move1, mem_move1 + 2, 20);
	memmove(mem_move2, mem_move2 + 2, 20);
	printf("%s\n", mem_move1);
	printf("%s\n", mem_move1);
*/

/*
	printf("La fonction strchr\n");
	char	str_chr[50];
	ft_strcpy(str_chr, "aller la .bichon");
	char	*ret;
	char	c = '.';
	ret = strchr(str_chr, c);
	ft_putstr(ret);
*/

/*
	printf("La fonction strrchr\n");
	char	str_rchr[50];
	ft_strcpy(str_rchr, ".");
	char	*ret;
	char	c = '.';
	ret = ft_strrchr(str_rchr, c);
	printf("La chaine =%s\n", ret);
	ret = strrchr(str_rchr, c);
	printf("La chaine =%s\n", ret);
*/

//	printf("La fonction strstr\n");
//	printf("L'occurence trouve=%s\n", ft_strstr("ma super phrase aller", "phrase"));
//printf("La fonction strnstr\n");
//printf("L'occurence trouve=%s\n", ft_strnstr("ma super phrase aller", "phrase", 50));
//printf("Le resultat de la cmp=%d", ft_strequ("abcde", "abcde"));
//ft_putnbr(-12345);

/*
int fd;
fd = open("file", O_WRONLY);
if(fd == -1)
	return (1);
ft_putchar_fd('w', fd);
ft_putstr_fd("ma super phrase", fd);
ft_putnbr_fd(1789, fd);
*/

	//printf("res de atoi=%d", ft_atoi(" "));

/*
printf("fonction stiteri\n");
char	str_striteri[50];
ft_strcpy(str_striteri, "abcdef");
ft_striteri(str_striteri, &masuper_fonction);
printf("%s\n", str_striteri);
*/

/*
printf("Fonction strmap\n");
char	str_strmap[50];
ft_strcpy(str_strmap, "abcd");
printf("La chaine=%s", ft_strmap(str_strmap, &maseconde_super));
*/

/*
printf("Fonction mapi\n");
char	str_strmapi[50];
ft_strcpy(str_strmapi, "abcd");
printf("La chaine =%s\n", ft_strmapi(str_strmapi, &supersuper_f));
*/

/*
	printf("La fonction strsub\n");
	char	str_strsub[50];
	ft_strcpy(str_strsub, "revolution sur les champs");
	printf("%s\n", ft_strsub(str_strsub, 3, ft_strlen(str_strsub) - 3));
*/

/*
printf("La fonction strjoin\n");
	char str_join1[50];
	char str_join2[50];
	ft_strcpy(str_join1, "slt");
	ft_strcpy(str_join2, "toi");
//ft_strjoin(str_join1, str_join2);
printf("la concat =%s\n", ft_strjoin(str_join1, str_join2));
*/
/*
printf("La fonction strtrim\n");
char	str_strtrim[50];
ft_strcpy(str_strtrim, "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !");
//ft_strtrim(str_strtrim);
printf("La chaine=%s\n", ft_strtrim(str_strtrim));
*/
/*
printf("La fonction strsplit\n");
char	split[200];
ft_strcpy(split, "");
char	**str_split;
str_split = ft_strsplit(NULL, 0);
int		i;
i = 0;
while (str_split[i] != 0)
{
printf("%s\n", str_split[i]);
i++;
}
printf("slt2\n");
//printf("%s\n", str_split[0]);
//printf("%s\n", str_split[1]);
//printf("%s\n", str_split[2]);
*/


//printf("Fonction memalloc");
//ft_memalloc(32);



		return (0);
}



void masuper_fonction(unsigned int index, char *c)
{
	*c = *c + 1;
	(void)index;
}

char	maseconde_super(char c)
{
	return (c = c + 1);
}

char	supersuper_f(unsigned int index, char c)
{
	(void)index;
	return (c = c + 1);
}


