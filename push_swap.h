/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhumblet < vhumblet@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:50:29 by vhumblet          #+#    #+#             */
/*   Updated: 2025/04/17 18:40:35 by vhumblet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	int				index;
	struct s_list	*next;
}					t_list;

void				ft_swap(t_list **list);
void				ft_push(t_list **list1, t_list **list2);
void				ft_rotate(t_list **list);
void				ft_rrotate(t_list **list);
void				swap_a(t_list **a);
void				swap_b(t_list **b);
void				double_swap(t_list **a, t_list **b);
void				push_a(t_list **a, t_list **b);
void				push_b(t_list **a, t_list **b);
void				rotate_a(t_list **a);
void				rotate_b(t_list **b);
void				double_rotate(t_list **a, t_list **b);
void				rrotate_a(t_list **a);
void				rrotate_b(t_list **b);
void				double_rrotate(t_list **a, t_list **b);
int					ft_isdigit(char *str);
int					check_digit_av(t_list **list);
int					check_int_max_min(long *array);
long				ft_atol(const char *str);
long				*ft_make_array(t_list **list, int nb);
void				ft_put_index(t_list **list, long *array);
void				ft_feel_free(void **ptr);
void				ft_sort_array(long *array);
int					check_double(long *array);
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(char *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				strs_to_list(char **str, t_list **list);
int					error_and_index(t_list **list);
void				algo_main(t_list **a, t_list **b);
int					ft_strlen(char *str);

#endif
