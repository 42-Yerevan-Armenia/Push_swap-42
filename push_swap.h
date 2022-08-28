/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:50 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/10 20:30:51 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_all
{
	int				index;
	int				content;
	struct s_all	*next;
}				t_all;

//PARSING ⚙️
void			ft_free(char **str);
void			ft_error(char *str);
void			checks(char **args);
char			**check_args(int ac, char **av);
void			ft_fill_stack(t_all **a, int ac, char **av);

//CHECK ✅
void			simple_sort(t_all **a, t_all **b);
void			radix_sort(t_all **a, t_all **b);
void			ft_for_swap(t_all **swap);
int				ft_for_push(t_all **sa, t_all **b);
int				is_sorted(t_all **a);

//LIBFT 📚
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			ft_lstadd_back(t_all **lst, t_all *new);
t_all			*ft_lstlast(t_all *lst);
t_all			*ft_lstnew(int content);
int				ft_lstsize(t_all *head);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int n);
long long int	ft_atoi(const char *str);

//PRINTF 🖨
int				ft_putchar(int c);
int				ft_putstr(char *s);
int				ft_printf(const char *s, ...);
int				ft_print_unsigned(unsigned int n);
int				ft_print_pointer(unsigned long long l);
int				ft_print_hex(unsigned long long num, unsigned int b, int a);

//SORTERS ♻️
void			sa(t_all **a, int t);
void			sb(t_all **b, int t);
void			ss(t_all **a, t_all **b, int t);

int				pa(t_all **a, t_all **b);
int				pb(t_all **a, t_all **b);

void			ra(t_all **a, int t);
void			rb(t_all **b, int t);
void			rr(t_all **a, t_all **b, int t);

void			rra(t_all **a, int t);
void			rrb(t_all **b, int t);
void			rrr(t_all **a, t_all **b, int t);

/*
read, write, malloc, free, exit

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss (): sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr (): ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr (): rra and rrb at the same time.
*/

#endif