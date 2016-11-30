#ifndef __CPUIDH_H__
#define __CPUIDH_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NON_BAREMETAL
extern char    configdata[2][1024];
extern char    timeday[30];
extern double  theseSecs;
extern double  startSecs;
extern double  secs;
extern double  ramGB;
extern int     megaHz;
extern int     CPUconf;
extern int     CPUavail;


void local_time(void);
int getDetails(void);
#else 
extern double  start;
extern double  end;
extern double  secs;

double fabs(double x);
#endif 

void start_time(void);
void end_time(void);

#ifdef __cplusplus
};
#endif

#endif //__CPUIDH_H__
