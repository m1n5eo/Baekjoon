import sys

input = sys.stdin.readline

word = input()[:-1]

if word == "M":
    print("MatKor")
elif word == "W":
    print("WiCys")
elif word == "C":
    print("CyKor")
elif word == "A":
    print("AlKor")
elif word == "$":
    print("$clear")