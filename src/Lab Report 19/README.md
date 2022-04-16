# Perform read operation  on a file

## Source Code

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   if ((fptr = fopen("read.txt","r")) == NULL){
       printf("Error! opening file");

       exit(1);
   }

   fscanf(fptr,"%d", &num);

   printf("Value of n = %d\n", num);
   fclose(fptr); 
  
   return 0;
}
```

## Output

![Read Operation in File](./LR19.png)