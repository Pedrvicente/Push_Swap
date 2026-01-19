#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

char			**ft_split(char *str, char separator);
int				ft_atoi(char *str);
t_stack_node	*find_last_node(t_stack_node *stack);
int				check_repetition(t_stack_node *a, int n);
void			error_free(t_stack_node **a, char **argv, bool argc_2);
int				error_syntax(char *str);
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **stack, int n);
void			stack_init(t_stack_node **a, char **argv, bool argc_2);
int				stack_len(t_stack_node	*stack);
t_stack_node 	*find_lowest(t_stack_node *stack);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
t_stack_node	*return_cheapest(t_stack_node *stack);
void			init_node(t_stack_node *a, t_stack_node *b);
void			finish_rotation(t_stack_node **stack, t_stack_node *top_node, char name);
void			handle_five(t_stack_node **a, t_stack_node **b);
bool			stack_sorted(t_stack_node *stack);
void			pa(t_stack_node **a, t_stack_node**b, bool checker);
void			pb(t_stack_node **b, t_stack_node**a, bool checker);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			tiny_sort(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
#endif