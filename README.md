### Decoder
## Description
This program takes in an encoded .txt file from the console and decodes it. This is done using two functions: decode() and readFile(). 
I chose to split them up to compartmentalize the code, so as to make debugging easier and make it more readable. A three function approach 
is also possible seen in 'old-main.ccp' and is even more concise.

## readFile()
First, readFile() does exactly what it sounds like it does: takes in the const reference of a file name, opens a file stream to it, 
and reads in every line. These are stored in the variable fullLines and contains the unaltered lines of the file to pass around and 
manipulate without messing with the file more than is necessary.

## decode()
Second, decode() does all the heavy lifting. It takes in a vector of strings, which represent the full unaltered lines of the file. 
It then uses some cool iterator tricks to isolate the full words and full numbers of each line, mapping them for easy look-up later, 
and sorting them to prepare for decoding. Making the decode key consists of using some cool math to shear away all numbers except for 
the last number on each row of the 'pyramid.' After everything is prepared, it is time to decode--the simplest of the process, 
as all the hard work was done before. Decoding  simply consists of going through the decode key and performing look ups on the map to 
get the correct words for the decoded sentence. It is then returned and displayed on the console.

## Input files
The input is a .txt file made of however many lines, each starting with a number, followed by a space, and a word.
E.g.:
| 1 love
| 23 cats
| 5 boats
The code is made by constructing a pyramid of these lines, sorting them, and taking the last of each row. Then, adding those corresponding words together.
The above example would look like this:
|   1
| 5  23
The last of each row would be 1 and 23, making the decoded message: "love cats."
