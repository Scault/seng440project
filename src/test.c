/* -------------------------------- Includes -------------------------------- */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "main.h"

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
    int i=0;
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

  i=0;
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

  i=0;
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
  i=0;
  printf("%-15s", "Recived");
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


int test_ASCII()
{
  printf("%-9s|%-9s|%-9s|%-9s|%-9s\n","Char","Orginial","Encrypted","Decrypted","PASS/FAIL");
  printf("---------+---------+---------+---------+---------\n");
  uint16_t encrypted = 0;
  uint16_t decrypted = 0;
  int cases_passed = 0;
  for(int i=0; i<128; i++)
  {

    encrypted = encrypt((uint16_t)i);
    decrypted = decrypt(encrypted);
    if(i>31 && i<127)
    {
      printf("%-9c|", i);
      printf("%-9d|", i);
      printf("%-9d|", encrypted);
      printf("%-9d|", decrypted);
      if(i == (int)decrypted)
      {
        printf("%-9s|", "PASS");
        cases_passed = cases_passed +1;
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
        cases_passed = cases_passed +1;
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


void test()
{
  int ASCII_result  = test_ASCII();
  int santiy_result = test_sanity();
  printf("+---------------+----------+\n");
  printf("|%-15s|%-10s|\n","Test","PASS/FAIL");
  printf("|---------------+----------| \n");
  if(ASCII_result)
  {
    printf("|%-15s|%-10s|\n","ASCII Test","PASS");
  }
  else 
  {
    printf("|%-15s|%-10s|\n","ASCII Test","FAIL");
  }

  printf("|---------------+----------| \n");

  if(santiy_result)
  {
    printf("|%-15s|%-10s|\n","Sanity Test","PASS");
  }
  else 
  {
    printf("|%-15s|%-10s|\n","Sanity Test","FAIL");
  }


  printf("+---------------+----------+");
  
}
