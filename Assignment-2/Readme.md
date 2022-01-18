# Exec family system call and basic IPC using signals API
In S1.c we have a sigterm handler. 
In our main function, we spawn two child processes
SR and ST respectively. Whenever SR or ST is executed, we execute the respective processes for SR and ST while the parents
are same. So from this we create two more processes which
are different in nature unlike the similar child processes. 
<br>

In SR.c we initiate a itimerval structure and initialises its
parameter along with a sigaction structure as well and
initialise its handler parameter and call it.Then using
sigaction we call the sigalarm which calls the random number
generator mentioned in our inline assembly print
it in sigalarmhandler function and queue
it in sigqueue. This gets printed in our S1.c file where
the parent ID has been passed too.
<br>

In ST.c we also initialise itimerval and
sigaction. But, we first call the SIGALARM and then 
the SIGTERM using sigaction. In sigalarm handler we first queue
the union into SIGTERM and at SIGTERM we print the number of seconds .However it may or may not be accurate depending upon the frequency of our processor.
However we see that it keeps incrementing second by second. So it
acts like a sort of a clock.
<br>

To run the programmes, type: 

    make

