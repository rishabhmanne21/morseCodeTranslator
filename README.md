# morseCodeTranslator
This project translates Morse Code to English and vice versa using tokenizing. Once it receives a certain input file, it will translate it into a particular output file for the user to open.



Depending on a file type that the user inputs, I used if statements to see if I should be translating from morse to English or vice versa.

Tokenizing
- Splitting by line if translating to morse code, otherwise splitting by the '|' character as the input files are specified in that format
- If the end of the line doesn't have a bar, then we write into the outputFile the English translation of the Morse
- Same process for English to Morse, however, the delimiter is the "" instead, and a character by character analysis is started


Shall there be an error with the user inputs, then an error message is printed to the user.

Helper Methods
- EnglishToMorse
    - a switch statement that returns the Morse equivalent of a character(case doesn't matter)
- MorseToEnglish
    - a series of if statements using the strcmp() method to return the character equivalent of a Morse expression
    

