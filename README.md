# SENG 440 - RSA Cryptography Project

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

    2,    3,    5,    7,    11,   13,   17,   19,   23,   29,                // 1  - 10
    31,   37,   41,   43,   47,   53,   59,   61,   67,   71,                // 11 - 20
    73,   79,   83,   89,   97,   101,  103,  107,  109,  113,               // 21 - 30
    127,  131,  137,  139,  149,  151,  157,  163,  167,  173,               // 31 - 40
    179,  181,  191,  193,  197,  199,  211,  223,  227,  229,               // 41 - 50
    233,  239,  241,  251,  257,  263,  269,  271,  277,  281                // 51 - 60

  ASCII CHAR to DEC

    Dec Char                            Dec Char      Dec Char      Dec Char
    0   NUL (null)                      32  SPACE     64  @         96  `
    1   SOH (start of heading)          33  !         65  A         97  a
    2   STX (start of text)             34  "         66  B         98  b
    3   ETX (end of text)               35  #         67  C         99  c
    4   EOT (end of transmission)       36  $         68  D        100  d
    5   ENQ (enquiry)                   37  %         69  E        101  e
    6   ACK (acknowledge)               38  &         70  F        102  f
    7   BEL (bell)                      39  '         71  G        103  g
    8   BS  (backspace)                 40  (         72  H        104  h
    9   TAB (horizontal tab)            41  )         73  I        105  i
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

