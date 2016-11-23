/*
 * (C) Copyright 2015 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include "dhry.h"

static int do_dhry(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int iterations = 1000000;

	if (argc > 1)
		iterations = simple_strtoul(argv[1], NULL, 10);

	dhry(iterations);

	return 0;
}

U_BOOT_CMD(
	dhry,	2,	1,	do_dhry,
	"[iterations] - run dhrystone benchmark",
	"\n    - run the Dhrystone 2.1 benchmark, a rough measure of CPU speed\n"
);
