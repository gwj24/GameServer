/*
 * @Author: guanwenjie 
 * @Date: 2021-02-25 17:04:26 
 * @Last Modified by: guanwenjie
 * @Last Modified time: 2021-02-25 17:27:43
 */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "miscutils.h"

void StartDaemon()
{
    if (fork() != 0)
    {
        // TODO
        exit(1);
    }

    if (setsid() < 0)
    {
        // TODO
        exit(1);
    }

    if (fork() != 0)
    {
        // TODO
        exit(1);
    }

    umask(0);
    signal(SIGINT,SIG_IGN);
    signal(SIGHUP,SIG_IGN);
    signal(SIGQUIT,SIG_IGN);
    signal(SIGPIPE,SIG_IGN);
    signal(SIGTTOU,SIG_IGN);
    signal(SIGTTIN,SIG_IGN);
    signal(SIGUSR1,SIG_IGN);
    signal(SIGUSR2,SIG_IGN);
    signal(SIGALRM,SIG_IGN);

    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
}