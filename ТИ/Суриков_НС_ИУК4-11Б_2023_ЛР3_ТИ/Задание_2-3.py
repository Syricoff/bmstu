s = """0x27 0x41 0x6E 0x64 0x20 0x74 0x68 0x6F 0x75 0x20 0x68 0x61 0x73 0x74 
0x20 0x73 0x6C 0x61 0x69 0x6E 0x20 0x74 0x68 0x65 0x20 0x4A 0x61 0x62 0x62 
0x65 0x72 0x77 0x6F 0x63 0x6B 0x3F"""

for i in s.split():
    print(chr(int(i, 16)), end='')


for i in "Дизассемблер":
    print(hex(ord(i)), end=' ')
