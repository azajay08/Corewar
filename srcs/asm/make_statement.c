/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:04:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/05 04:04:51 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_statement(t_asm *assem)
{
	int i = 0;

	assem->line->num = 0;
	while (i < STATEMENT_MAX)
	{
		ft_printf("\nState Name: %s\n", g_op_tab[i].state_name);
		i++;
	}
}

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
	get_statement(assem);
	statement->index = index;
	statement->byte_count = 0;
	label_check(assem, index);
	return (statement);
}