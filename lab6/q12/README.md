The program below allows the user to pass a 32-bit virtual address through main arguments 
& output the page number & offset for the given address by assuming 4𝐾𝐵 page size


```
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 unsigned long page, offset, address;
 if(argc != 2) exit(1);
 address= atoll(argv[1]);
 page = address >> 12; /*calculating pages number*/
 offset = address & 0xfff; /*calculating remaining offset*/
 printf("The address %lu contains: \n", address);
 printf("page number = %lu\n",page);
 printf("offset = %lu\n", offset);
 return 0;
}
```

## Task:

- Modify the program above & call it 𝑣𝑎𝑑𝑑𝑟2.𝑐
- The new program should output the page number & offset for the given address using 1𝑀𝐵 page size
