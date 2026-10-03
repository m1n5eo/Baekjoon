import sys

input = sys.stdin.readline

n = int(input())
str = "WelcomeToSMUPC"

print(str[(n-1)%14])