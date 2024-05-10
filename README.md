This program takes in a .txt file from the console as args in main and calls the necessary functions from there. There are two functions 
that tackle this task: decode() and readFile(). I chose to split them up to make debugging much easier and compartmentalize the code, making 
it more readable and easier to understand. A three function approach is also possible and even more concise, but I wanted to keep in the spirit 
of the question and try and keep it two.

First, readFile() does exactly what it sounds like it does: takes in the const reference of a file name, opens a file stream to it, 
and reads in every line. These are stored in the variable fullLines and contains the unaltered lines of the file to pass around and 
manipulate without messing with the file more than is necessary.

Second, decode() does all the heavy lifting. It takes in a vector of strings, which represent the full unaltered lines of the file. 
It then uses some cool iterator tricks to isolate the full words and full numbers of each line, mapping them for easy look-up later, 
and sorting them to prepare for decoding. Making the decode key consists of using some cool math to shear away all numbers except for 
the last number on each row of the 'pyramid.' After everything is prepared, it is time to decode--the simplest of the process, 
as all the hard work was done before. Decoding  simply consists of going through the decode key and performing look ups on the map to 
get the correct words for the decoded sentence. It is then returned and displayed on the console.