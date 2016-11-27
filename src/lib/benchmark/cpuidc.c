/*
   ;  nasm -f elf cpuida.asm   for cpuida.o
   ;  gcc cpuidc.c -c          for cpuidc.o
   ;  gcc test.c cpuidc.o cpuida.o -lrt -lc -lm -o test
   ;  ./test
 */

#ifdef NON_BAREMETAL
#include <stdio.h>
#include <stdlib.h>     
#include <string.h> 
#include <time.h>
#include <math.h>
#include "cpuidh.h"

char    configdata[2][1024];
char    timeday[30];
char    idString1[100] = " ";
char    idString2[100] = " ";
struct  timespec tp1;
FILE * info;

unsigned int millisecs  = 0;

double  theseSecs = 0.0;
double  start = 0.0;
double  secs;

void local_time()
{
    time_t t;

    t = time(NULL);
    sprintf(timeday, "%s", asctime(localtime(&t)));
    return;
}

void getSecs(void)
{
    clock_gettime(CLOCK_REALTIME, &tp1);

    theseSecs =  tp1.tv_sec + tp1.tv_nsec / 1e9;               
    return;
}

void start_time(void)
{
    getSecs();
    start = theseSecs;
    return;
}

void end_time(void)
{
    getSecs();
    secs = theseSecs - start;
    millisecs = (int)(1000.0 * secs);
    return;
}    

int getDetails(void)
{
    size_t bytes;

    info = fopen ("/proc/cpuinfo", "r");
    if (info == NULL)
    {
        sprintf (configdata[0], " Cannot open /proc/cpuinfo\n");
        return 1;
    }
    bytes = fread (configdata[0], 1, sizeof(configdata[0]), info);
    fclose (info);
    if (bytes == 0) sprintf (configdata[0], " No data read from /proc/cpuinfo\n");

    info = fopen ("/proc/version", "r");
    if (info == NULL)
    {
        sprintf (configdata[0], " Cannot open /proc/version\n");
        return 1;
    }
    bytes = fread (configdata[1], 1, sizeof(configdata[1]), info);
    fclose (info);
    if (bytes == 0) sprintf (configdata[1], " No data read from /proc/version\n");
    return 0; 
}
#else 

#include <common.h>

unsigned int millisecs  = 0;

ulong start, end;
double secs = 0.0;

void start_time(void)
{
	start = get_timer(0); 

}

void end_time(void) 
{ 
	end = get_timer(0) - start;
	secs = end/1000.0;
    millisecs = (int)(1000.0 * secs);
}

double fabs(double x)
{ 
	*(((int *) &x) + 1) &= 0x7fffffff;
	return x;
} 
 
#endif 

