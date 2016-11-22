#include <common.h>
#include <command.h>
#include <div64.h>

static int do_whets(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
#if 0
    int nopause = 1;

	if (argc > 1)       
		iterations = simple_strtoul(argv[1], NULL, 10);

	start = get_timer(0);
	dhry(iterations);
	duration = get_timer(start);
	dhry_per_sec = lldiv(iterations * 1000ULL, duration);
	vax_mips = lldiv(dhry_per_sec, 1757);
	printf("%d iterations in %lu ms: %lu/s, %lu DMIPS\n", iterations,
	       duration, (ulong)dhry_per_sec, vax_mips);

#endif 
	return 0;
}

U_BOOT_CMD(
	whets,	2,	1,	do_whets,
	"[iterations] - run whetsstone benchmark",
	"\n    - run the Whetstone\n"
);
