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
	if np.dot(v.T,v)==0:
		print("Dot product becomes zero")
		exit(0)
	beta = 2/np.dot(v.T , v)
	
	# z = v @ v.T
	# print(z)

	v = np.array(v)

	H = np.identity(n-j) - beta * v @ v.T 
	H = np.array(H)
	
	return H

def QRDecomposition(A):
	c = 0
	
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

	print("\nMatrix A after applying Transformation \n")
	print(A)
	
	return A

# n = 3
# m = 2
A = []
# A = [[35.0,1,6,26,19,24],[3,32,7,21,23,25],[31,9,2,22,27,20],[8,28,33,17,10,15],[30,5,34,12,14,16],[4,36,29,13,18,11]]
# A = [[3,-2],[0,3],[4,4]]
# b = [3,5,4]
b = []
maxdimensions = 10
maximumVal = 100

n = random.randint(2,maxdimensions)
m = n-1

for i in range(n):
	temp = []
	for j in range(m):
		temp.append(random.randint(1,maximumVal))
	A.append(temp)

Acopy = copy.deepcopy(A)

for i in range(n):
	b.append(random.randint(1,maximumVal))


print("n=",n)
print("m=",m)
print("\nMatrix A \n")
print(A)

print("\nVector b\n")
print(b)

for i in range(n):
	A[i].append(b[i])

print("\nAugmented matrix A' \n")
print(A)

A = np.array(A)

R = QRDecomposition(A)

print("\nMatrix R \n")
print(R)

if np.linalg.det(R)==0:
	print("R Singular matrix found")
	exit(0) 

R_inv=inv(np.array(R))

# print(R_inv)

Q=A@R_inv
print("\nMatrix Q\n")
print(Q)

J=Q@Q.T
# print(J)

barr = []

for i in b:
	temp=[]
	temp.append(i)
	barr.append(temp)

barr = np.array(barr)


btemp = Q.T @ barr
R=R[0:m,0:m]
# print(btemp)
# print(type(btemp))
# print(R[n-1][n-1],btemp[n-1][0])

x = [0]*m	
x[m-1] = btemp[m - 1][0] / R[m - 1][m - 1]

i = m - 2
while i>=0:
	x[i] = btemp[i][0]
	for j in range(i+1,m):
		x[i] -= R[i][j] * x[j]
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

# Final answer x
print("\nvector X \n")
print(x1)
x1=np.array(x1)
Acopy=np.array(Acopy)

# b - Ax should be tend to zero
print("\nb - Ax vector \n")
print(barr-Acopy@x1)
