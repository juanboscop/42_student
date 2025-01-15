# 42 STUDENT
all of 42 student subjects

## MILESTONE 2

### PRINTF
Printf important command to testing printf = cc -o test_ft_printf ft_printf.c libftprintf.a ./libft/libft.a -I./libft

### GET NEXT LINE
test get_next_line = cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c


## MILESTONE 3

### PUSH_SWAP


### MINI_TALK
--TIME EXCUTION
  #include <time.h>
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    clock_gettime(CLOCK_MONOTONIC, &end);
	double elapsed = (end.tv_sec - start.tv_sec) + 
                     (end.tv_nsec - start.tv_nsec) / 1.0e9;
    printf("Time taken: %.6f seconds\n", elapsed);
--INFO
    Time=450×8×100=360,000μs=0.36seconds.

    /*
    ** handler_function is called on SIGUSR1 or SIGUSR2.
    ** We update g_server.current_char by shifting and setting a bit.
    ** Once we have 8 bits, we print the character (or newline if \0),
    ** then reset bit_count + current_char inside g_server.
    ** Finally, we kill(client_pid, SIGUSR1) to ACK the client.
    */
--BNUS;
		// g_ack_received = 0;
		// while (!g_ack_received)
		// 	pause();

--DEBUG
// printf("Received signal %s from PID=%d\n",
    //     (signum == SIGUSR1) ? "SIGUSR1" : "SIGUSR2",
    //     client_pid
    // );

    for i in {1..100}; do ./client <PID> <message> ; done