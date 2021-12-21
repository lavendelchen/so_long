/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:25:39 by shaas             #+#    #+#             */
/*   Updated: 2021/12/21 15:53:02 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalnum(int c);													// -----------------
int		ft_isalpha(int c);													//| checks if char  |
int		ft_isascii(int c);													//| is certain type |
int		ft_isdigit(int c);													//| of character    |
int		ft_isprint(int c);													// -----------------
int		ft_tolower(int c);													// / converts letter to
int		ft_toupper(int c);													// \ different case
void	ft_putchar_fd(char c, int fd);										// ------------------------
void	ft_putstr_fd(char *s, int fd);										//| print stuff to certain |
void	ft_putendl_fd(char *s, int fd);										//| file descriptor        |//follow string with newline
void	ft_putnbr_fd(int n, int fd);										// ------------------------
void	*ft_memchr(const void *s, int c, size_t n);							// finds char in mem
char	*ft_strchr(const char *s, int c);									// finds char in string
char	*ft_strrchr(const char *s, int c);									// finds last occurence of char in string
void	*ft_memset(void *b, int c, size_t len);								// makes mem one specific char
void	ft_bzero(void *s, size_t n);										// makes mem \0
int		ft_memcmp(const void *s1, const void *s2, size_t n);				// compare memory, return difference
int		ft_strncmp(const char *s1, const char *s2, size_t n);				// compare strings
void	*ft_memcpy(void *dst, const void *src, size_t n);					// copies mem to other mem
void	*ft_memmove(void *dst, const void *src, size_t len);				// better memcpy, mems can overlap
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);				// copies string to other string (choose to end before)
char	*ft_strdup(const char *s1);											// 💭 copies string into allocated mem
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);				// appends string to other string
char	*ft_strjoin(const char *s1, const char *s2);						// 💭 allocates combined string
size_t	ft_strlen(const char *s);											// returns length of string
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);	// finds string in other string
int		ft_atoi(const char *str);											// converts string to integer
char	*ft_itoa(int n);													// converts integer to string
void	*ft_calloc(size_t count, size_t size);								// 💭 allocates mem + sets it to \0
char	*ft_substr(const char *s, unsigned int start, size_t len);			// 💭 allocates part of string (choose freely)
char	*ft_strtrim(const char *s1, const char *set);						// 💭 allocates trimmed string (complicated lol, meaning it trims chars from set from front and end)
char	**ft_split(const char *s, char c);									// 💭 splits string into substrings, allocates them
void	ft_striteri(char *s, void (*f)(unsigned int, char*));				// applies function to every char of string
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));			// 💭 applies function to every char of string, allocates result
t_list	*ft_lstnew(void *content);											// 💭 create new linked list, return pointer to it
void	ft_lstadd_front(t_list **lst, t_list *new);							// add element to front of list
int		ft_lstsize(t_list *lst);											// give amount of elements in list
t_list	*ft_lstlast(t_list *lst);											// return pointer to last element in list
void	ft_lstadd_back(t_list **lst, t_list *new);							// add element to end of list
void	ft_lstdelone(t_list *lst, void (*del)(void *));						// apply function del to element lst, meaning it'll be freed
void	ft_lstclear(t_list **lst, void (*del)(void*));						// frees every element of list, sets pointer to NULL
void	ft_lstiter(t_list *lst, void (*f)(void *));							// applies function to every content of every element of list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));	// 💭 applies function to every content,but creates seperate list for that

#endif
