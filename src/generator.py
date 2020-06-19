import wolframalpha
client = wolframalpha.Client('demo')

# Generated by encrypting the ASCII table
encrytped_ascii = [0, 1, 41139, 33080, 33142, 24541, 25681, 5777, 15688, 7043, 37620,
                   18873, 36468, 38146, 17333, 12747, 24814, 34599, 33550, 34324, 6907,
                   718, 12138, 9182, 8544, 22943, 38058, 11762, 44431, 43977, 12654,
                   10320, 37817, 23909, 27929, 41292, 44121, 10878, 35300, 27533, 9098,
                   44769, 23391, 11936, 26037, 23482, 25714, 38125, 14064, 40863, 19847,
                   31649, 11666, 6633, 11285, 6163, 19885, 9095, 30747, 206, 5182, 10695,
                   32130, 32096, 25150, 35512, 3266, 313, 20483, 16157, 38189, 38195, 24927,
                   12404, 32039, 25278, 25802, 1200, 36488, 5364, 29109, 8857, 43660, 17242,
                   31689, 4436, 26714, 17651, 37054, 18789, 1806, 22127, 1442, 15723, 27676,
                   39034, 15579, 10909, 44297, 40305, 10208, 7923, 4902, 10421, 15165, 10622,
                   12685, 32727, 19333, 29540, 39168, 11010, 1185, 2576, 40461, 1694, 3922,
                   22738, 29110, 15996, 22663, 40585, 5743, 26902, 26641, 24204, 20528, 35992]


def generate_encrypt_table():
  # a^(2^b) modulo 44923, a: 0 - 127, b: 0 - 14 
  for a in range(0, 128):
      print('{', end='')
      for b in range(0, 15):
          query = str(a) + '^(2^' + str(b) + ') modulo 44923'
          res = client.query(query)
          print(next(res.results).text, end='')
          if(b != 15):
              print(', ', end='')
      print('}')

def generate_decrypt_table():
  # a^(2^b) modulo 44923, a: 0 - 127, b: 0 - 14 
  for a in encrytped_ascii:
      print('{', end='')
      for b in range(0, 16):
          query = str(a) + '^(2^' + str(b) + ') modulo 44923'
          res = client.query(query)
          print(next(res.results).text, end='')
          if(b != 15):
              print(', ', end='')
      print('}')

generate_decrypt_table()
