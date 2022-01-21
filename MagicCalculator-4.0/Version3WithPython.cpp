/*
#Magic Trick - Computer will guess the user number by using 7 lists/cards of numbers,
#the user tells the computer if the number is on the list/card or not.

import time

def magicCard(m):
	for row in range(len(m)): #length of matrix = # of rows (# of sub-lists)

		for col in range(len(m[row])+1): # length of a sub list = columns - add 1 will include the last index of a row instead of stopping right before

			if col == (len(m[row])): #This checks if the index is at the end of the list, if so start new line.
				print("")
			else:
				print("{:<4}".format(m[row][col]),end='') #Print numbers

def askUser(matrix):#Does the User see their number on the cards?
	total = 0
	magicCard(matrix) #print out matrix
	numCheck = input("Do you see your number? yes or no: ") #Ask user a question
	print("")
	while numCheck != 'yes' and numCheck != 'no': #No invalid response
		print("invalid input")
		numCheck = input("Do you see your number? yes or no: ")
		print("")
	if numCheck == 'yes':
		digit = '1'  #if yes that binary place is one
	else:
		digit = '0' #Strings so the int function can convert to decimal
	return digit

#Card__ - the number is the binary place (the top left corner number)
card1 = [[1, 3, 5, 7, 9, 11, 13, 15],
		 [17, 19, 21, 23, 25, 27, 29, 31],
		 [33, 35, 37, 39, 41, 43, 45, 47],
		 [49, 51, 53, 55, 57, 59, 61, 63],
		 [65, 67, 69, 71, 73, 75, 77, 79],
		 [81, 83, 85, 87, 89, 91, 93, 95],
		 [97, 99]] #1 - Place/Column
card2 = [[2, 3, 6, 7, 10, 11, 14, 15],
		 [18, 19, 22, 23, 26, 27, 30, 31],
		 [34, 35, 38, 39, 42, 43, 46, 47],
		 [50, 51, 54, 55, 58, 59, 62, 63],
		 [66, 67, 70, 71, 74, 75, 78, 79],
		 [82, 83, 86, 87, 90, 91, 94, 95],
		 [98, 99]] #2
card4 = [[4, 5, 6, 7, 12, 13, 14, 15],
		 [20, 21, 22, 23, 28, 29, 30, 31],
		 [36, 37, 38, 39, 44, 45, 46, 47],
		 [52, 53, 54, 55, 60, 61, 62, 63],
		 [68, 69, 70, 71, 76, 77, 78, 79],
		 [84, 85, 86, 87, 92, 93, 94, 95],
		 [100]] #3
card8 = [[8, 9, 10, 11, 12, 13, 14, 15],
		 [24, 25, 26, 27, 28, 29, 30, 31],
		 [40, 41, 42, 43, 44, 45, 46, 47],
		 [56, 57, 58, 59, 60, 61, 62, 63],
		 [72, 73, 74, 75, 76, 77, 78, 79],
		 [88, 89, 90, 91, 92, 93, 94, 95]] #4
card16 = [[16, 17, 18, 19, 20, 21, 22, 23],
		 [24, 25, 26, 27, 28, 29, 30, 31],
		 [48, 49, 50, 51, 52, 53, 54, 55],
		 [56, 57, 58, 59, 60, 61, 62, 63],
		 [80, 81, 82, 83, 84, 85, 86, 87],
		 [88, 89, 90, 91, 92, 93, 94, 95]] #5
card32 = [[32, 33, 34, 35, 36, 37, 38, 39],
		  [40, 41, 42, 43, 44, 45, 46, 47],
		  [48, 49, 50, 51, 52, 53, 54, 55],
		  [56, 57, 58, 59, 60, 61, 62, 63],
		  [96, 97, 98, 99, 100]] #6
card64 = [[64, 65, 66, 67, 68, 69, 70, 71],
		  [72, 73, 74, 75, 76, 77, 78, 79],
		  [80, 81, 82, 83, 84, 85, 86, 87],
		  [88, 89, 90, 91, 92, 93, 94, 95],
		  [96, 97, 98, 99, 100]] #7
allCards = [card64, card32, card16, card8, card4, card2, card1] #List of all the matrix so we can use a for loop to use all of them

#Introduction to magic trick
print("I'm going to show you a magic trick!")
time.sleep(2) #So user can follow one line at a time - helps user experience
print("Please think of a number between 1-100.")
time.sleep(2)
print("Look at these number sets and find your number.")
print("")
#Use all cards and pass them into ask User function
binaryUser = ""
for c in allCards:
	binaryUser += askUser(c) #find binary number from yes and no

decimalUser = int(binaryUser,2) #Convert from binary to decimal

print("Now I'm going to guess your number.")
time.sleep(2)
print("")
print("Your Number is {}".format(decimalUser))
print("")

*/