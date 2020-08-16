
/* -------------------------------- TODO LIST ------------------------------- */
/* 1. Create a performance testbench                                          */
/* -------------------------------- Includes -------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <time.h>
#include "main.h"
#include "test.h"

/* -------------------------------- Functions ------------------------------- */

void print_array(uint16_t input[])
{
    int i = 0;
    while(input[i] != '\0')
    {
        printf("%-7d ",input[i]);
        i++;
    }
}

void user_input()
{
    char message[100];
    uint16_t encrypted_message[100];
    uint16_t decrypted_message[100];
    printf("Input a message: ");
    scanf("%s", message);
    int i = 0;
    printf("%-15s", "Sent");
    while(1)
    {
        printf("%-7c ", (int)message[i]);
        encrypted_message[i] = encrypt((uint16_t)message[i]);
        i++;
        if(message[i] == '\0')
        {
            encrypted_message[i] = '\0';
            break;
        }
    }

    i = 0;
    printf("\n%-15s", "ASCII Dec");
    while(1)
    {
        printf("%-7d ", (int)message[i]);
        encrypted_message[i] = encrypt((uint16_t)message[i]);
        i++;
        if(message[i] == '\0')
        {
            encrypted_message[i] = '\0';
            break;
        }
    }

    printf("\n%-15s","Encrypted");
    print_array(encrypted_message);
    printf("\n%-15s","Decrypted");

    i = 0;
    while(1)
    {
        decrypted_message[i] = decrypt(encrypted_message[i]);
        i++;
        if(encrypted_message[i] == '\0')
        {
            decrypted_message[i] = '\0';
            break;
        }
    }

    print_array(decrypted_message);
    printf("\n");
    i = 0;
    printf("%-15s", "Received");
    while(1)
    {
        printf("%-7c ", decrypted_message[i]);
        encrypted_message[i] = encrypt((uint16_t)message[i]);
        i++;
        if(message[i] == '\0')
        {
            encrypted_message[i] = '\0';
            break;
        }
    }
}


/* void test_ASCII()
 *
 *
 *
 */
int test_ASCII()
{
    printf("%-9s|%-9s|%-9s|%-9s|%-9s\n","Char","Orginial","Encrypted","Decrypted","PASS/FAIL");
    printf("---------+---------+---------+---------+---------\n");
    uint16_t encrypted = 0;
    uint16_t decrypted = 0;
    int cases_passed = 0;
    int i;
    for(i = 0; i < 128; i++)
    {
        encrypted = encrypt((uint16_t)i);
        decrypted = decrypt(encrypted);
        if(i > 31 && i < 127)
        {
            printf("%-9c|", i);
            printf("%-9d|", i);
            printf("%-9d|", encrypted);
            printf("%-9d|", decrypted);
            if(i == (int)decrypted)
            {
                printf("%-9s|", "PASS");
                cases_passed = cases_passed + 1;
            }
            else
            {
                printf("%-9s|", "FAIL");
            }
            printf("\n");
        }
        else
        {
            if(i == (int)decrypted)
            {
                cases_passed = cases_passed + 1;
            }
        }
    }
    if(cases_passed == 128)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/* int test_sanity()
 *
 *
 *
 */
int test_sanity()
{
    uint16_t encrypted = encrypt(33);
    uint16_t decrypted = decrypt(encrypted);

    if(33 == (int)decrypted)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


/* int test_encrpytion_performance()
 *
 *
 *
 */
double test_encrpytion_performance()
{
    clock_t start = clock();
    int i, j;
    for(i = 0; i < 10000; i++)
    {
        for(j = 0; j < 128; j++)
        {
            uint16_t encrypted = encrypt((uint16_t)j);
            if(expected_encrypted_ASCII[j] != (int)encrypted)
            {
                return -1;
            }
        }
    }
    clock_t diff = clock() - start;
    double time_taken = ((double)diff) / CLOCKS_PER_SEC; // in seconds
    return time_taken;
}

/* int test_encrpytion_performance()
 *
 *
 *
 */
double test_decrpytion_performance()
{
    clock_t start = clock();
    int i, j;
    for(i = 0; i < 10000; i++)
    {
        for(j = 0;j<128;j++)
        {
            uint16_t decrypted = decrypt((uint16_t)expected_encrypted_ASCII[j]);
            if(j != (int)decrypted)
            {
                return -1;
            }
        }
    }
    clock_t diff = clock() - start;
    double time_taken = ((double)diff) / CLOCKS_PER_SEC; // in seconds
    return time_taken;
}

/* void test()
 *
 *
 *
 */
void test()
{
    int ASCII_result = test_ASCII();
    int santiy_result = test_sanity();
    double encryption_performance = test_encrpytion_performance();
    double decryption_performance = test_decrpytion_performance();
    printf("+---------------+----------+----------+\n");
    printf("|%-15s|%-10s|%-10s|\n","Test","PASS/FAIL","Time");
    printf("|---------------+----------+----------| \n");
    if(ASCII_result)
    {
        printf("|%-15s|%-10s|%-10s|\n","ASCII Test","PASS","N/A");
    }
    else
    {
        printf("|%-15s|%-10s|%-10s|\n","ASCII Test","FAIL","N/A");
    }

    printf("|---------------+----------+----------| \n");

    if(santiy_result)
    {
        printf("|%-15s|%-10s|%-10s|\n","Sanity Test","PASS","N/A");
    }
    else
    {
        printf("|%-15s|%-10s|%-10s|\n","Sanity Test","FAIL","N/A");
    }

    printf("|---------------+----------+----------| \n");

    if((int)encryption_performance != -1)
    {
        printf("|%-15s|%-10s|%-10f|\n","Encryption Perf","PASS",encryption_performance);
    }
    else
    {
        printf("|%-15s|%-10s|%-10s|\n","Encryption Perf","FAIL","N/A");
    }

    printf("|---------------+----------+----------| \n");

    if((int)decryption_performance != -1)
    {
        printf("|%-15s|%-10s|%-10f|\n","Decryption Perf","PASS",decryption_performance);
    }
    else
    {
        printf("|%-15s|%-10s|%-10s|\n","Decryption Perf","FAIL","N/A");
    }

    printf("+---------------+----------+----------+ \n");
}

/* void test()
 *
 *
 *
 */
void test_performance_CVS()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // Allocates storage
    char *file_name = (char*)malloc(100 * sizeof(char));
    // Prints "Hello world!" on hello_world
    sprintf(file_name, "performance_results_%d-%02d-%02d %02d:%02d:%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    FILE * fp;
    fp = fopen (file_name, "w");
    fprintf(fp, "%-10s %-10s\n", "Encryption", "Decryption");
    double encryption_performance = 0.0;
    double decryption_performance = 0.0;
    int i;
    for(i = 0; i < 100; i++)
    {
        encryption_performance = test_encrpytion_performance();
        decryption_performance = test_decrpytion_performance();
        fprintf(fp, "%-10f %-10f\n",encryption_performance,decryption_performance );
    }
    fclose(fp);
}
