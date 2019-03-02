import numpy as np
import random
from numpy import linalg as LA
from numpy.linalg import inv
import copy

def houseHold(A,j):
	
	A1 = []
	for i in A:
		temp = []
		temp.append(i[j])
		A1.append(temp)
	
	A1 = A1[j:]
	# print(A1)
	e1 = []
	for i in range(n-j):
		temp=[]
		temp.append(0)
		e1.append(temp)

	e1[0][0]=1
	
	# print(e1)
	# e1 = e1[j:]
	
	A1 = np.array(A1)
	e1 = np.array(e1)
	
	v = A1 - LA.norm(A1)*e1
	# print(v)
	beta = 2/np.dot(v.T , v)
	
	# z = v @ v.T
	# print(z)
	v = np.array(v)

	H = np.identity(n-j) - beta * v @ v.T 
	H = np.array(H)
	
	# print(H)
	
	return H

def QRDecomposition(A):
	c = 0
	Q = np.identity(n)
	global H
	for i in range(n-1):
	
		# print(c)
		H2=houseHold(A,c)
		A = np.array(A)
		A1=A[c:,c:]
		A1 = H2 @ A1
		for i in range(c,n):
			for i1 in range(c,n):
				A[i][i1]=A1[i-c][i1-c]
				# print(H[i][i1],H1[i][i1])
		c = c + 1

		# print(A)

	print("\nMatrix A after applying Transformation\n")
	print(A)
	
	return A

# n = 3
# A = [[35.0,1,6,26,19,24],[3,32,7,21,23,25],[31,9,2,22,27,20],[8,28,33,17,10,15],[30,5,34,12,14,16],[4,36,29,13,18,11]]
# A = [[3,-2,3],[0,3,5],[4,4,4]]
# b = [4,5,6]

maxdimensions = 10
maximumVal = 100

A = []
b = []
n = random.randint(2,maxdimensions)

for i in range(n):
	temp = []
	for j in range(n):
		temp.append(random.randint(1,maximumVal))
	A.append(temp)

Acopy = copy.deepcopy(A)

for i in range(n):
	b.append(random.randint(1,maximumVal))

A = np.array(A)
print("n=",n)
print("\nMatrix A\n")
print(A)

print("\nVector b\n")
print(b)

R = QRDecomposition(A)

print("\nMatrix R\n")
print(R)

R_inv=inv(np.array(R))
# print(R_inv)

Q=A@R_inv

print("\nMatrix Q\n")
print(Q)

# J should be one since Q is orthogonal
J=Q@Q.T

# print(J)
barr=[]

for i in b:
	temp=[]
	temp.append(i)
	barr.append(temp)

barr = np.array(barr)

btemp=Q.T@barr

# print(btemp)
# print(R[n-1][n-1],btemp[n-1][0])

x = [0]*n	
x[n-1] = btemp[n - 1][0] / R[n - 1][n - 1]

i = n - 2
while i>=0:
	x[i] = btemp[i][0]
	for j in range(i+1,n):
		x[i] = x[i] - (R[i][j] * x[j])
	x[i] = x[i]/R[i][i]	
	i-=1

# x=np.array(x)
# print(x)

# x=np.array(x)
x1=[]
for i in x:
	temp=[]
	temp.append(i)
	x1.append(temp)

# Final answer
print("\nVector X\n")
print(x1)
x1=np.array(x1)
Acopy=np.array(Acopy)

# b - Ax should be nearly zero
# For cross check purpose
print("\nb - Ax\n")
print(btemp-Acopy@x1)
