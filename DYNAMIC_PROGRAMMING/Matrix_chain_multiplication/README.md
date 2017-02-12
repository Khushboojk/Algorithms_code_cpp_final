# MATRIX CHAIN MULTIPLICATION
---------------------------

Problem Statement:- 
We are given a sequence (chain) <A1 ; A2 ; : : : ; An> of n matrices to be multiplied, and we wish to compute the product A1A2A3A4...An. in minimum number of scalar multiplication. In this problem we are not interested in finding actual product but our goal is only to determine an order for multiplying matrices that has the lowest cost

For example:- There are three matrices A1(5X50),A2(50X10),A3(10X2). We can multiply in two possible ways
			  1. (A1A2)A3 
			  	 total no. scalar multiplication required = 5x50x10 + 5x10x2 = 2600
			  2. A1(A2A3)
			  	 total no. scalar multiplication required = 50x10x2 + 5x50x2 = 1500

From above example we can see that by selecting appropriate order we can reduce time complexity  during product.

Sample Input:- No. of matrices = 6; order[]= 30 35 15 5 10 20 25
				order[i] = order[i-1]xorder[i]

Sample Output:- optimal scalar multiplication table
				0 0 0 0 0 0 0 
				0 0 15750 7875 9375 11875 15125 
				0 0 0 2625 4375 7125 10500 
				0 0 0 0 750 2500 5375 
				0 0 0 0 0 1000 3500 
				0 0 0 0 0 0 5000 
				0 0 0 0 0 0 0 

				Split position table
				0 0 0 0 0 0 0 
				0 0 1 1 3 3 3 
				0 0 0 2 3 3 3 
				0 0 0 0 3 3 3 
				0 0 0 0 0 4 5 
				0 0 0 0 0 0 5 
				0 0 0 0 0 0 0 

