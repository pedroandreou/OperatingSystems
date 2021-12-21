## :dart: Task to accomplish  
### Write a C program that creates two child processes.   

-  The parent process and the child processes should be able to print their process ID
- & print out “parent” for the parent process and “child”for the child processes.   
- Additionally, each process initiates a counter with 0 and a loop to increment the counter by 1 in each iteration up to 10.
- Each iteration should last of one second and in each second, each process prints out the counter value.   

The following is a sample output:  
```
parent 6555 process: counter=1  
child 6556 process: counter=1  
child 6557 process: counter=1  
parent 6555 process: counter=2  
child 6556 process: counter=2  
child 6557 process: counter=2  
```

