import numpy as np
import random
from numpy import linalg as LA
from numpy.linalg import inv

def houseHold(A):
	
	A1 = []
	for i in A:
		temp = []
		temp.append(i[0])
		A1.append(temp)
	

	# print(A1)
	e1 = []
	for i in range(n):
		temp=[]
		temp.append(0)
		e1.append(temp)

	e1[0][0]=1
	# print(e1)
	
	A1 = np.array(A1)
	e1 = np.array(e1)
	
	v = A1 - LA.norm(A1)*e1
	
	# print(v)
	if np.dot(v.T,v)==0:
		print("Dot product becomes zero")
		exit(0)
	beta = 2/np.dot(v.T , v)
	
	# z = v @ v.T
	# print(z)
	v = np.array(v)

	H = np.identity(n) - beta * (v @ v.T)
	H = np.array(H)
	
	return H


A = []
# n = 3
# A = [[3,-2,3],[0,3,5],[4,4,4]]
maxdimensions = 10
maximumVal = 100

n = random.randint(2,maxdimensions)

for i in range(n):
	temp = []
	for j in range(n):
		temp.append(random.randint(1,maximumVal))
	A.append(temp)

print("n=",n)

print("Matrix A")
A=np.array(A)
print(A)

H = houseHold(A)

print("HouseHold Matrix")
print(H)