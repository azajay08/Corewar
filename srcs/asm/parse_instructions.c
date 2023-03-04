/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:56:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/04 21:57:14 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void	get_statement(t_asm *assem)
// {
// 	int i = 0;

// 	assem->line->num = 0;
// 	while (i < STATEMENT_MAX)
// 	{
// 		ft_printf("\nState Name: %s\n", g_op_tab[i].state_name);
// 		i++;
// 	}
// }

void	append_statement(t_asm *assem, t_state *statement)
{
	t_state	*tmp;

	tmp = assem->state;
	while (assem->state)
		assem->state = assem->state->next;
	assem->state->next = statement;
	assem->state = tmp;
}

t_state	*make_statement(t_asm *assem, int index)
{
	t_state	*statement;

	statement = (t_state *)malloc(sizeof(t_state));
	if (!statement)
		error_exit1(STATE_FAIL, assem);
	// get_statement(assem);
	statement->index = index;
	statement->byte_count = 0;
	label_check(assem, index);
	return (statement);
}

void	parse_instructions(t_asm *assem, int index)
{
	t_state	*statement;
	
	while (index < assem->line_count)
	{
		if (assem->l_array[index]->line[0]
			&& line_has_statement(assem, index, assem->l_array[index]->line))
		{
			statement = make_statement(assem, index);
			if (!assem->state)
				assem->state = statement;
			else
				append_statement(assem, statement);
			ft_printf("\nThere is a statment!:\n%s\n", assem->l_array[index]->line);
		}
		index++;
	}
	if (!assem->state)
		error_exit1(INSTRUCT, assem);
}
