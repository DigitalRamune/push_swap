/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaciri <inaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:30:58 by ffeder            #+#    #+#             */
/*   Updated: 2026/03/12 17:19:18 by inaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isprint(int c);
int		ft_isdigit(char *c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
char	*ft_strrchr(const char *s, int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);

typedef struct s_list
{
	int				data;
	int				score;
	int				rank;
	size_t			len;
	size_t			pos;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct n_oper
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				print;
	struct n_oper	*next;
}					t_oper;

typedef	struct param_list
{
	int					simple;
	int					medium;
	int					complex;
	int					adaptiv;
	int					bench;
	char				*choice;
	struct param_list	*next;
}						p_list;

void	ft_lstclear_all(t_list **stack_a, t_list **stack_b, p_list **param, t_oper **op);

t_oper	*ft_lstnew_op(int data);
void	ft_lstadd_front_op(t_oper **lst, t_oper *new);
void	ft_lstclear_op(t_oper **lst);

p_list	*ft_lstnew_param(int data);
void	ft_lstclear_param(p_list **lst);
void	ft_lstadd_front_param(p_list **lst, p_list *new);

t_list	*ft_lstnew(int data);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_reverserotate(t_list **stack_a, t_oper **operation, int which);
void	ft_rrr(t_list **stack_a, t_list **stack_b, t_oper **operation);
void	ft_rotate(t_list **stack_a, t_oper **operation, int which);
void	ft_rr(t_list **stack_a, t_list **stack_b, t_oper **operation);
void	ft_push(t_list **stack_a, t_list **stack_b, t_oper **operation, int which);
void	ft_swap(t_list **stack_a, t_oper **operation, int which);
void	ft_ss(t_list **stack_a, t_list **stack_b, t_oper **operation);

void	printlist(t_list *next_p);
float	compute_disorder(t_list **stack_a);
int		ft_adaptive(p_list **param, t_list **stack_a);
void	set_alg(p_list **param, t_list **stack_a, t_list **stack_b, t_oper **op);
char	*ft_strdup(const char *s);

void	ft_simple_alg(t_list **stack_a, t_list **stack_b, t_oper **operation);
void	place_min_at_top(t_list **next_p, int index, t_oper **operation);
void	find_min(t_list **next_p, t_oper **operation);
int		find_min_score(t_list **stack_a, int index_score, int max_data, int size);
int		find_max(t_list **stack_a);

void	ft_medium_alg(t_list **stack_a, t_list **stack_b, t_oper **operation);
int		ft_bucket_no(int data, int size, int max);
void	top_nb_min_in_score(t_list **stack_a, t_list **stack_b, int max_score, t_oper **operation);
void	find_max2(t_list **next_p, t_oper **operation);
int		find_score(t_list **stack_a, int index_score, int size, int *temp_min_data);
void	place_max_at_top(t_list **next_p, int index, t_oper **operation);
void	order_alg(int temp_min_data, int index, t_list **stack_a, t_list **stack_b, t_oper **operation);
t_list	**ft_split(char const *s, char c, t_list **stack_a);

int		find_min_radix(t_list **stack, int list_size);
void	set_min_rank(t_list **stack, int rank, int list_size);
void	set_base_rank(t_list **stack_a);
void	set_all_rank(t_list **stack);
int		ft_bits_num(int list_size);
void	ft_push_back_all(t_list **stack_b, t_list **stack_a, int count, t_oper **operations);
void	ft_radix_loop(t_list **stack_a, t_list **stack_b, t_oper **operation, int maxbits, int bits);
void	ft_radix(t_list **stack_a, t_list **stack_b, t_oper **operation);
void	ft_set_op_nbr(t_oper **operations);

int		ft_detect(char *argv, p_list **param);
int		ft_check_all(char **argv, p_list **param);
void	set_alg(p_list **param, t_list **stack_a, t_list **stack_b, t_oper **op);

void	print_bench(p_list **param, t_list **stack_a, t_oper **op, float disorder);
void	ft_bench(t_oper **op, p_list **param, t_list **stack_a, t_list **stack_b);

void	ft_create_stack(t_list **stack_a, char **argv, int i, int z);
void	ft_init_lists(t_oper **operations, p_list **param);
int		ft_result_after_check(char **argv, p_list **param);

void	ft_push_swap(t_list **stack_a, t_list **stack_b, t_oper **op, p_list **param);
int		ft_check_duplicate(t_list **stack_a, int nb, char **arr, int index);

#endif
