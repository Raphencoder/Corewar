#include "op.h"
typedef struct s_process
{
	int	carry;
	int	live;
	int pc;
	int registre[REG_SIZE];	
}

check_process(process)
{
	while (process)
	{
		if (!process->live)
			kill_proces(process);
		process =process->next;
	}
}

int	main()
{
	int	cycle_to_die = 0;
	int check = 0;
	int lives = 0;

	while ("y'a un process")
	{
		if (cycle == CYCLE_TO_DIE)
		{
			check++;
			check_process()
			if (lives == MAX_LIVE || check = MAX_CHECK )
			{
				cycle_to_die -= CYCLE_DELTA
				check = 0;
			}

		}
			exec_process(process)
	}
}

int		corewar(void)
{
	__asm__(
			".name \"CC\""
			".omment "
			
			
			
			);
}
