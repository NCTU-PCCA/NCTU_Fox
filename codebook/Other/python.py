#!/usr/bin/env python3

# import
import math
from math import *
import math as M
from math import sqrt

# input
n = int( input() )
a = [ int(x) for x in input().split() ]

# EOF
while True:
    try:
        solve()
    except:
        break;

# output
print( x, sep=' ')
print( ''.join( str(x)+' ' for x in a ) )
print( '{:5d}'.format(x) ) 

# sort
a.sort()
sorted(a)

# list
a = [ x for x in range(n) ]
a.append(x)

# Basic operator 
a, b = 10, 20
a/b  # 0.5
a//b # 0
a%b  # 10
a**b # 10^20

# if, else if, else
if a==0:
    print('zero')
elif a>0:
    print('postive')
else:
    print('negative')

# loop
while a==b and b==c:
for i in LIST:

# stack	        # C++
stack = [3,4,5] 
stack.append(6)	# push()
stack.pop()     # pop()
stack[-1]       # top()
len(stack)      # size() O(1)

# queue         # C++
from collections import deque
queue = deque([3,4,5])
queue.append(6) # push()
queue.popleft() # pop()
queue[0]        # front()
len(queue)      # size() O(1)

# random
from random import *
randrange(L,R,step) # [L,R) L+k*step
randint(L,R) # int from [L,R]
choice(list) # pick 1 item from list
choices(list,k) # pick k item
shuffle(list)
Uniform(L,R) # float from [L,R]

# Decimal
from fractions import Fraction
from decimal import Decimal, getcontext
getcontext().prec = 250 # set precision

itwo = Decimal(0.5)
two = Decimal(2)

N = 200
def angle(cosT):
  """given cos(theta) in decimal return theta"""
  for i in range(N):
    cosT = ((cosT + 1) / two) ** itwo
  sinT = (1 - cosT * cosT) ** itwo
  return sinT * (2 ** N)
pi = angle(Decimal(-1))

# file IO
r = open("filename.in")
a = r.read() # read whole content into one string

w = open("filename.out", "w")
w.write('123\n')

# IO redirection
import sys
sys.stdin = open('filename.in')
sys.stdout = open('filename.out', 'w')
