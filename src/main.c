/* -------------------------------------------------------------------------- */
/*                          RSA Encryption/Decryption                         */
/*                            SENG 440 Summer 2020                            */
/* -------------------------------------------------------------------------- */
/*
  RSA Cryptography Algorithm

   Public  key-piar(E, PQ), used to encrypt data
   Private key-pair(D, PQ), used to decrypt data

   1. Find P and Q, two large prime numbers

   2. Choose E such that E > 1, E < PQ and
      E and (P-1)(Q-1) have no prime factors in common
      E doesn't have to prime but it must be odd

   3. Compute D such that (DE-1) is evenly divisible by (P-1)(Q-1)
      D = (X(P-1)(Q-1)+1)/E ,find an int X that causes D to be an int

   4. Encryption function is the following
      C = T^E mod PQ where C=ciphertext and T=Plain text

   5. decryption function is the following
      T = C^D mod PQ where C=ciphertext and T=Plain text

  List of the first 60 primes
	 1     2     3     4     5     6     7     8     9    10
  ---------------------------------------------------------
	 2,    3,    5,    7,   11,   13,   17,   19,   23,   29,  // 1  - 10
    31,   37,   41,   43,   47,   53,   59,   61,   67,   71,  // 11 - 20
    73,   79,   83,   89,   97,  101,  103,  107,  109,  113,  // 21 - 30
    27,  131,  137,  139,  149,  151,  157,  163,  167,  173,  // 31 - 40
   179,  181,  191,  193,  197,  199,  211,  223,  227,  229,  // 41 - 50
   233,  239,  241,  251,  257,  263,  269,  271,  277,  281   // 51 - 60

  ASCII CHAR to DEC
  Dec  Char                           Dec  Char     Dec  Char     Dec  Char
  ---------                           ---------     ---------     ----------
    0  NUL (null)                      32  SPACE     64  @         96  `
    1  SOH (start of heading)          33  !         65  A         97  a
    2  STX (start of text)             34  "         66  B         98  b
    3  ETX (end of text)               35  #         67  C         99  c
    4  EOT (end of transmission)       36  $         68  D        100  d
    5  ENQ (enquiry)                   37  %         69  E        101  e
    6  ACK (acknowledge)               38  &         70  F        102  f
    7  BEL (bell)                      39  '         71  G        103  g
    8  BS  (backspace)                 40  (         72  H        104  h
    9  TAB (horizontal tab)            41  )         73  I        105  i
   10  LF  (NL line feed, new line)    42  *         74  J        106  j
   11  VT  (vertical tab)              43  +         75  K        107  k
   12  FF  (NP form feed, new page)    44  ,         76  L        108  l
   13  CR  (carriage return)           45  -         77  M        109  m
   14  SO  (shift out)                 46  .         78  N        110  n
   15  SI  (shift in)                  47  /         79  O        111  o
   16  DLE (data link escape)          48  0         80  P        112  p
   17  DC1 (device control 1)          49  1         81  Q        113  q
   18  DC2 (device control 2)          50  2         82  R        114  r
   19  DC3 (device control 3)          51  3         83  S        115  s
   20  DC4 (device control 4)          52  4         84  T        116  t
   21  NAK (negative acknowledge)      53  5         85  U        117  u
   22  SYN (synchronous idle)          54  6         86  V        118  v
   23  ETB (end of trans. block)       55  7         87  W        119  w
   24  CAN (cancel)                    56  8         88  X        120  x
   25  EM  (end of medium)             57  9         89  Y        121  y
   26  SUB (substitute)                58  :         90  Z        122  z
   27  ESC (escape)                    59  ;         91  [        123  {
   28  FS  (file separator)            60  <         92  \        124  |
   29  GS  (group separator)           61  =         93  ]        125  }
   30  RS  (record separator)          62  >         94  ^        126  ~
   31  US  (unit separator)            63  ?         95  _        127  DEL
*/

/* -------------------------------- Includes -------------------------------- */

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "main.h"
#include "test.h"

/* -------------------------------- Functions ------------------------------- */

/* !!THIS FUNCTION WAS REPLACED BY binarySearch_table()!!
 *
 * int find_index(uint16_t c)
 * Inputs:  uint16_t C, where C is the value to be searched for
 * Outputs: int i,      where i is arrary index of the value
 *
 * Locates the index of decrypt_table[i][0] needed to compuet the power
 *
 * Time complexity: O(n), where n=i
 */
/*
int find_index(uint16_t c)
{
    uint16_t i;
    for(i = 0; i < 128; i++)
    {
        if(decrypt_table[i][0] == (int)c)
        {
            return i;
        }
    }
    return -1;
}

*/
/* int binarySearch_table(arr[][16], left, right, x)
 * Inputs: - const uint16_t decrypt_table[][]
           - uint16_t left , where left is the lefthand boundary for the search
           - uint16_t right, where right is the righthand boundary for the search
           - uint16_t x,     where x is the value to be searched for
 * Outputs: int mid,         where mid = arrary index of the value
 *
 * Locates the index of decrypt_table[i][0] needed to compute the power
 *
 * Time complexity: O(log(n)), where n=i
 */
/*
int binarySearch_table(const uint16_t arr[][16],
                       uint16_t left,
                       uint16_t right,
                       uint16_t x)
{
    if(right >= left)
    {
        uint16_t mid = left + (right - left) / 2;
        if(arr[mid][0] == x)
        {
            return mid;
        }
        if(arr[mid][0] > x)
        {
            return binarySearch_table(arr, left, mid - 1, x);
        }
        return binarySearch_table(arr, mid + 1, right, x);
    }
    return -1;
}
*/
/* int hashFunctionSearch(uint16_t i)
 * Inputs:  uint16_t i, where i is the value to be searched for
 * Outputs: int index,  where intex is the arrary index of the value
 *
 * Locates the index of decrypt_table[i][0] needed to compute the power
 * by utilizing a hash function
 *
 * Time complexity: O(1)
 */
/*
int hashFunctionSearch(uint16_t i)
{
    int index;
    if(i == 5777)
    {
        index = 18;
    }
    else if(i == 5182)
    {
        index = 15;
    }
    else if(i == 25714)
    {
        index = 77;
    }
    else
    {
        int num = (((int)i) % 997);
        index = gen_table[num];
    }
    return index;
}

*/
/* uint16_t encrypt(uint16_t T)
 * Inputs:  uint16_t T, Where T = Plaintext
 * Outputs: uint16_t C, Where C = Ciphertext
 *
 * Computes encryption of of T using the RSA formula below
 * and table method for computing exponents.
 *
 * C = T^E mod PQ where C=ciphertext and T=Plain text
 *
 * E = 16969 = 0100 0010 0100 1001
 * E = 2^0 + 2^3 + 2^6 + 2^6 + 2^9 + 2^14
 */
uint16_t encrypt(uint16_t T)
{
    register uint32_t a = T     * encrypt_table[T][3];
    register uint32_t b = a % 44923 * encrypt_table[T][6];
    register uint32_t c = b % 44923 * encrypt_table[T][9];
    register uint32_t d = c % 44923 * encrypt_table[T][14];
    register uint32_t C = d % 44923;
    return (uint16_t)C;
}


/* uint16_t decrypt(uint16_t C)
 * Inputs:  uint16_t C, Where C = Ciphertext
 * Outputs: uint16_t T, Where T = Plaintext
 *
 * Computes decryption of of C using the RSA formula below
 * and table method for computing exponents.
 *
 * T = C^D mod PQ where C=ciphertext and T=Plain text
 *
 * D = 55785 = 1101 1001 1110 1001
 * D = 2^0 + 2^3 + 2^5 + 2^6 + 2^7 + 2^8 + 2^11 + 2^12 + 2^14 + 2^15
 */
uint16_t decrypt(uint16_t C)
{
    int index;
    if(C > 25714)
    {
        goto skip;
    }
    if(C == 5777)
    {
        index = 18;
    }
    else if(C == 5182)
    {
        index = 15;
    }
    else if(C == 25714)
    {
        index = 77;
    }
    else
    {
     skip:index = gen_table[(((int)C) % 997)];
    }
    register uint32_t a = decrypt_table[index][3] * decrypt_table[index][5];
    register uint32_t b = a % 44923 * decrypt_table[index][6];
    register uint32_t c = b % 44923 * decrypt_table[index][7];
    register uint32_t d = c % 44923 * decrypt_table[index][8];
    register uint32_t e = d % 44923 * decrypt_table[index][11];
    register uint32_t f = e % 44923 * decrypt_table[index][12];
    register uint32_t g = f % 44923 * decrypt_table[index][14];
    register uint32_t h = g % 44923 * decrypt_table[index][15];
    register uint32_t i = h % 44923 * decrypt_table[index][0];
    register uint32_t T = i % 44923;
    return (uint16_t)T;
}


/* int main()
 *
 */
int main(void)
{
    // user_input();
    // test();
    test_performance_CVS();
    return 0;
}
