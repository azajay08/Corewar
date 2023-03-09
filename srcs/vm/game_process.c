/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/09 16:42:35 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** init_corewar:
** - Initialises the data to be used within the Corewar game.
*/
void	init_corewar(t_corewar *corewar)
{
	corewar->cycles_total = 0;
	corewar->cycles = 0;
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->lives_this_round = 0;
	corewar->checks = 0;
	corewar->carry = 0;
}

static void	apply_statement(t_vm *vm, t_process *process)
{
	if (vm || process)
		ft_printf("");
	process->op_code = vm->arena[process->pos];
	ft_printf("process now at %x\n", process->op_code);
}

static void	execute_statement(t_vm *vm, t_process *process)
{
	if (vm || process)
		ft_printf("");
	ft_printf("Executing process %d\n", process->id);
	process->executed = true;
	vm->process_count--;
}

/*
** execute_cycle:
** -
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_process	*temp_process;

	ft_printf("%sExecuting cycle %d%s\n", RED, corewar->cycles_total, RESET);
	temp_process = vm->processes;
	while (temp_process)
	{
		if (temp_process->cycles_until_exec == 0 && !temp_process->executed)
			apply_statement(vm, temp_process);
		if (temp_process->cycles_until_exec > 0 && !temp_process->executed)
			temp_process->cycles_until_exec--;
		if (temp_process->cycles_until_exec == 0 && !temp_process->executed)
			execute_statement(vm, temp_process);
		temp_process = temp_process->next;
	}
	corewar->cycles_total++;
}

/*
** game_process:
** - Loops until only one player remains active in the arena.
*/
void	game_process(t_vm *vm)
{
	t_corewar	corewar;

	init_corewar(&corewar);
	init_arena(vm);
	vm->latest_live = vm->player_count;
	while (vm->processes != NULL && vm->process_count > 0)
	{
		if (corewar.cycles == vm->cycle_dump)
		{
			print_arena(vm);
			exit(EXIT_FAILURE);
		}
		execute_cycle(vm, &corewar);
		if (vm->cycles_to_die <= 0)
			ft_printf("ended\n");
		else
			vm->cycles_to_die--;
	}
}
