#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int regis = 0;
int vm1(char *p,int n)
{

    int len = 0;
    int i = 255;
    while(1)
    {
        int opcode1 = p[i];
        int opcode2 = p[i+1];
        int opcode3 = p[i+2];
        if(opcode1 == 1)
        {
            p[opcode2] = opcode3;
            len++;
        }
        else if(opcode1 == 2)
        {
            regis = p[opcode2];
        }
        else if(opcode1 == 3)
        {
            p[opcode2] ^= regis;
        }

        else
            break;
        i+=3;
    }
    printf("READ BINARY....\n-----------------------------------------");
        for(int a = 0 ; a < n;a++)
        {
        if(a%2 == 0) printf(" ");
        if(a!=0&a%16 == 0) printf("|");
        if(a%16 == 0) printf("\n");
        printf("%02hhX",p[a]&0xFF);

        }
        printf("\n-----------------------------------------\n");
        for(int a = 0; a < len;a++)
        {
            if(a%26==0) printf("\n");
            printf("%02hhX ",p[a]);
        }
}
int main()
{
    FILE *fileptr;
    char *buffer;
    long filelen;

    fileptr = fopen("ram.bin", "rb");  // Open the file in binary mode
    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    fclose(fileptr); // Close the file
    printf("READ BINARY....\n-----------------------------------------");
    for(int i = 0 ; i < filelen;i++)
    {
        if(i%2 == 0) printf(" ");
        if(i!=0&i%16 == 0) printf("|");
        if(i%16 == 0) printf("\n");
        printf("%02hhX",buffer[i]&0xFF);

    }
    printf("\n-----------------------------------------\n");
    vm1(buffer,filelen);
    return 0;
}
