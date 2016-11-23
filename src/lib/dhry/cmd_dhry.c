/*
 * (C) Copyright 2015 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <div64.h>
#include "dhry.h"

static int do_dhry(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	ulong start, duration, vax_mips;
	u64 dhry_per_sec;
	int iterations = 1000000;

	printf("RADO : Inside %s @ %d ###\n", __FILE__,__LINE__); 
	if (argc > 1)
		iterations = simple_strtoul(argv[1], NULL, 10);

	printf("RADO : Before Timer start %s @ %d ###\n", __FILE__,__LINE__); 
	start = get_timer(0);
	printf("RADO : After Timer start: %ld  %s @ %d ###\n",start, __FILE__,__LINE__); 
	dhry(iterations);
	printf("RADO : After dhry called %s @ %d ###\n", __FILE__,__LINE__); 
	duration = get_timer(start);
	dhry_per_sec = lldiv(iterations * 1000ULL, duration);
	vax_mips = lldiv(dhry_per_sec, 1757);
	printf("%d iterations in %lu ms: %lu/s, %lu DMIPS\n", iterations,
	       duration, (ulong)dhry_per_sec, vax_mips);

	return 0;
}

U_BOOT_CMD(
	dhry,	2,	1,	do_dhry,
	"[iterations] - run dhrystone benchmark",
	"\n    - run the Dhrystone 2.1 benchmark, a rough measure of CPU speed\n"
);
