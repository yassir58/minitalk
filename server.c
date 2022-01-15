#include "minitalk.h"


int bin_to_ascii (char byte[])
{
    int length ;
    int sum ;
    int multiplier;
    int i ;
    
    length = 8;
    sum = 0;
    multiplier = 0;
    i = length - 1;
    while (i>=0)
        sum += ((byte[i--] - 48) * (1 << multiplier++));
    return sum;
}

char set_bit (int signo)
{
    if (signo == SIGUSR1)
        return  ('1'); 
    else if (signo == SIGUSR2)
        return ('0'); 
    return (0);
}


void signal_handler (int signo, siginfo_t *siginfo, void *context)
{
    static int indx;
    static char byte[8];
    int temp ;
    int check;
    char c;

    context = NULL;
    check = 1;
    temp = BIT_COUNT - (++indx);  
    if (temp == 0)
    {
        byte[temp] = set_bit(signo);
        indx = 0;
        c = bin_to_ascii (byte);
        if (c == 0)
            check = 0;
        write (1, &c,sizeof (char));
    }
    else
        byte[temp] = set_bit(signo);
    if (!check)
    {
        if (kill (siginfo->si_pid, SIGUSR2) == -1)
            write (2, "Error returning signal\n", 24);
    }
}

int main ()
{
    int PID;
    struct sigaction sig_act;

    PID = getpid ();
    write (1, "server PID: ", 12);
    write (1, &PID, sizeof (int));
    sig_act.sa_sigaction = &signal_handler;
    sig_act.sa_flags = SA_SIGINFO;
    sig_act.sa_flags = SA_NODEFER;
    sigaction (SIGUSR2, &sig_act, NULL);
    sigaction (SIGUSR1, &sig_act, NULL);
    while (1)
        pause ();
    return (0);
}