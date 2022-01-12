#include "minitalk.h"


int setting_bits(int bit)
{
   static int indx;
   static short int byte ;
   char mask;

    if (indx == 7)
    {
        indx = 0;
        if (byte)
        {
           write (1, &byte,1);
        }
        else
            return (0);
    }
    else
    {
        mask = 1 << indx ;
        byte = ((byte & ~mask) | (bit << indx));
        indx++;
    }
    return (1);
}

void signal_handler (int signo, siginfo_t *siginfo, void *context)
{
    int check;

    context = NULL;
    check = 1;
    if (signo == SIGUSR1)
        check = setting_bits (1);
    if (signo == SIGUSR2)
        check = setting_bits (0);
    if (!check)
    {
        if (kill (siginfo->si_pid, SIGUSR2) == -1)
            write (1, "Error returning signal\n", 24);
    }
}

int main ()
{
    int PID;

    PID = getpid ();
    printf ("server PID: %d\n",PID);
    struct sigaction sig_act;
    sig_act.sa_sigaction = &signal_handler;
    sig_act.sa_flags = SA_SIGINFO;
    sig_act.sa_flags = SA_NODEFER;
    sigaction (SIGUSR2, &sig_act, NULL);
    sigaction (SIGUSR1, &sig_act, NULL);
    while (1)
        pause ();
    return (0);
}