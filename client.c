#include "minitalk.h"

void extract_bits(char byte, int PID)
{
    int i = 0;
    int bit = 0;

    while (i < 8)
    {
        bit = byte & 1;
        if (bit == 1)
        {
            if (kill (PID, SIGUSR1) == -1)
            {
                write (1, "Invalid PID\n",13);
                exit (1);
            }
        }
        if (bit == 0)
        {
            if (kill (PID, SIGUSR2) == -1)
            {
                 write (1, "Invalid PID\n",13);
                 exit (1);
            }
        }
        byte >>= 1;
        i++;
        usleep(100);
    }
}

void send_str (char *str,int PID)
{
    int i = 0;
    while (str[i])
    {
        extract_bits (str[i], PID);
        i++;
    }
    extract_bits (str[i], PID);
}

void signal_handler (int signo)
{
    usleep (500);
    write (1 ,"Message recieved from SERVER\n", 30); 
    signo++;
}

int main(int argc, char *argv[])
{
    struct sigaction client_act ;
    if (argc < 3)
    {
        write (1, "make sure you have 3 arguments !\n",34);
        exit (1);
    }

    client_act.sa_handler = &signal_handler;
    sigaction (SIGUSR2, &client_act, NULL);
    int PID = atoi (argv[argc - 2]);
    send_str (argv [argc -1], PID); 
}
