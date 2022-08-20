/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:49 by arakhurs          #+#    #+#             */
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

// Stack A
# define LOAD_A all->a.load
# define TOP_A (all->a.load - 1)

# define STK_A all->a.stk
# define UNDR_A all->a.under

// Stack B
# define LOAD_B all->b.load
# define TOP_B (all->b.load - 1)

# define STK_B all->b.stk
# define UNDR_B all->b.under

typedef struct s_val {
	size_t	key;
	int		val;
}	t_val;

typedef struct s_stk
{
	t_val	*stk;
	size_t	load;
}				t_stk;

typedef struct s_all
{
	t_stk	a;
	t_stk	b;
}				t_all;

void	ft_error(char *str);

//CHECK ✅
int		alpha(char *str);
int		min_max(long long int num);
int		doubles(char **array, char *str, int pos);

//LIBFT 📚
void	ft_swap(t_val *a, t_val *b);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
long long int	ft_atoi(const char *str);

//PRINTF 🖨
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_printf(const char *s, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_print_pointer(unsigned long long l);
int		ft_print_hex(unsigned long long num, unsigned int b, int a);

//SORTERS ♻️
void	sa(t_all *all);
void	sb(t_all *all);
void	ss(t_all *all);
void	pa(t_all *all);
void	pb(t_all *all);
void	ra(t_all *all);
void	rb(t_all *all);
void	rr(t_all *all);
void	rra(t_all *all);
void	rrb(t_all *all);
void	rrr(t_all *all);
static void	rot_stk_top_to_botm(t_val *stk, size_t top);
static void	rot_stk_botm_to_top(t_val *stk, size_t top);

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