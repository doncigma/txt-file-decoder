## Decoder  
### Description  
This program takes in an encoded .txt file from the console and decodes it (the input file encoding is shown in more detail at the bottom of this doc). This is done using two functions: decode() and readFile(). 
I chose to split them up to compartmentalize the code, so as to make debugging easier and make it more readable. A three function approach 
is also possible as seen in 'main-split.ccp'.  

### readFile()  
First, readFile() does exactly what it sounds like it does: takes in the const reference of a file name, opens a file stream to it, 
and reads in every line. These are stored in the variable fullLines and contains the unaltered lines of the file to pass around and 
manipulate without messing with the file more than is necessary.  

### decode()  
Second, decode() does all the heavy lifting. It takes in a vector of strings, which represent the full unaltered lines of the file. 
It then uses some cool iterator tricks to isolate the full words and full numbers of each line, mapping them for easy look-up later, 
and sorting them to prepare for decoding. Making the decode key consists of using some cool math to shear away all numbers except for 
the last number on each row of the 'pyramid.' After everything is prepared, it is time to decode. This is the simplest part of the process, 
as all the hard work was done before. Decoding simply consists of going through the decode key and performing look ups on the map to 
get the correct words for the decoded sentence. It is then returned and displayed on the console.  

### Input files  
The input is a .txt file made of N lines, each starting with a number, followed by a space, and a word.
E.g.:  
|   1 love  
|   23 cats  
|   5 boats  
The decoded message is found by constructing a pyramid of these lines, sorting them, and taking the right-most number of each row, then adding those corresponding words together.  
The above example would look like this:  
|     1  
|   5  23  
The right-most numbers of each row are 1 and 23, making the decoded message: "love cats."

Please note: the test files provided do not necessarily contain an intelligble message, they were merely used to compare to an answer key for testing purposes.
