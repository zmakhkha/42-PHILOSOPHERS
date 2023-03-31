/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:42:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/30 14:25:16 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>          /* printf()                 */
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <errno.h>          /* errno, ECHILD            */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait().. */
#include <fcntl.h> 			/* O_CREAT, O_EXEC          */


const char *semName = "haha";

void parent(void){
    sem_t *sem;

	sem = sem_open(semName, O_CREAT, 0600, 0);

    if (sem == SEM_FAILED){
        perror("Parent  : [sem_open] Failed\n"); return;
    }

    printf("Parent  : Wait for Child to Print\n");
    if (sem_wait(sem) < 0)
        printf("Parent  : [sem_wait] Failed\n");
    printf("Parent  : Child Printed! \n");
    
    if (sem_close(sem) != 0){
        perror("Parent  : [sem_close] Failed\n"); return;
    }

    if (sem_unlink(semName) < 0){
        printf("Parent  : [sem_unlink] Failed\n"); return;
    }
}

void child(void)
{
    sem_t *sem;

	sem = sem_open(semName, O_CREAT, 0600, 0);

    if (sem == SEM_FAILED){
        perror("Child error yaaa wld hnini\n"); return;        
    }

    printf("Child   : saliiina men Semaphore\n");
    if (sem_post(sem) < 0)
        printf("Child   : masebna liha jehd \n");
}

int main(int argc, char *argv[])
{
    pid_t pid;
	int	i;

	i = 3;
	while (--i)
	{
		pid = fork();
	}
    if (pid < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (!pid){
        child();
        printf("Child   : Done with sem_open \n");
    }
    else{
        int status;
        parent();
        waitpid(-1, NULL, 0);
        printf("Parent  : Done with sem_open \n");
    }

    return 0;
}