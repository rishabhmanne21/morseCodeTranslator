/* 
Author: Rishabh Manne 
Date: 3/24/22
Description: Creating two functions that translate English to Morse code and vice versa
             which make use of the different syntax and semantics that C++ has to offer
Usage: morse_assn3 infile.txt -mc infile.mc
*/ 


#include <string.h> 
#include <iostream>
#include <fstream>  
using namespace std;



const char* englishToMorse(char);      // forward calling the method to let compiler know that it exists
char morseToEnglish(const char*);      // both of them translate English to morse code and vice versa

int main(int argc, char**argv)
{

    bool mc = false;                   // a boolean variable to keep track of which functions to call based on user input
	
    if(argc == 4)                      // only if all the args are provided, the code will go through otherwise an error message will pop up
     {	
        if(strcmp(argv[2], "-mc") == 0)
	 {

     		cout << "Translating " << argv[1] << " to morse code\n";     // if third arg is of -mc, then it means we are translating into morse code
		mc = true;
     	 }


	else if(strcmp(argv[2], "-e") == 0)
	 {
		cout << "Translating " << argv[1] << " to English\n";         // if third arg is of -e then it means we are translating into English
	 }



	ifstream inputFile;
	inputFile.open(argv[1]);         // creating input and output files that will read the command line files and will be used below
	ofstream outputFile;
	outputFile.open(argv[3]);



        char* row = new char[1785];     // creating a character array of up to 1785 characters that will hold the lines from getline
        char* token;	                // a token variable that will be useful when tokenizing



	while (inputFile.getline(row, 1785))           // as long as there is a new line in the inputFile, we continue to read
	{
           if(mc == true)
	    {
	  	 token = strtok(row, "\n");           // if translating into morse code, we separate by line and then character by delimiting on newline character
	    }
	   
           else
	    {
		 token = strtok(row, "|");            // if translating into English, we separate by the vertical bars(delimiters) and then treat morse digits as whole letters
	    }


	    while (token != NULL)                           // while token is not null, this function will run
	     {

		for(int i = 0; i < strlen(token); i++)
                {
                     if(mc == true)                          // looping through token array and if we are translating into mc, then we go ahead here
		     {

		       if(i == strlen(token)-1)
                        {
                          outputFile << englishToMorse(token[i]);           // making sure that the end of the line doesn't have a bar at the end so we check to see current position
			  break;					    // and then break loop
                        }

                        
		      
                       else
			{
			  outputFile << englishToMorse(token[i]);           // otherwise we write into the output file as usual with bar at end by calling our helper translator function
			  outputFile << "|";
			}
                     }
		     

		     else
		     {
			outputFile << morseToEnglish(token);		    // if translating into English, then we grab the current token(letter) and then break the loop to continue after the bar
		        break;
		     }
		
                }


	  if(mc == true)					
	   {
		     token = strtok(NULL, " ");			// if translating into mc, then we call strtok but with the " " as delimiter
 	   }


	  else
	   {
		     token = strtok(NULL, "|");                 // otherwise, the bar is our delimiter if we are translating into English
	   }

         }

        
	   outputFile << "\n";                 // a newline character at end of line to match the style of original input file
	}
  
    inputFile.close();			       // closing both files as we are done using them
    outputFile.close();


				
    cout << argv[3] << " file completed.";     // printing a success message

     }
     
     else
     {
        cout << "Error -- usage: <exe> <input file> <-mc|-e> <output file>";     // if user shall provide incorrect arguments, then an error message is printed with correct usage
     }

    return 0;			// a return value for main function, which returns an int
           
}


const char* englishToMorse(char letter)          // an englishToMorse method that uses switches to match char inputs and return their morse code equivalent const char* types
{
	switch(letter)
       	{
            
            case 'A':
            case 'a':
		return ".-";
		break;


	    case 'B':
	    case 'b':
		return "-...";
		break;


	    case 'C':
	    case 'c':
		return "-.-.";
		break;


	    case 'D':
	    case 'd':
		return "-..";
		break;


	    case 'E':
	    case 'e':
		return ".";
		break;


	    case 'F':
	    case 'f':
		return "..-.";
		break;


	    case 'G':
	    case 'g':
		return "--.";
		break;


	    case 'H':
	    case 'h':
		return "....";
		break;


	    case 'I':
	    case 'i':
		return "..";
		break;


	    case 'J':
	    case 'j':
		return ".---";
		break;


	    case 'K':
  	    case 'k':
		return "-.-";
		break;


	    case 'L':
	    case 'l':
		return ".-..";
		break;


	    case 'M':
	    case 'm':
		return "--";
		break;


	    case 'N':
	    case 'n':
		return "-.";
		break;


	    case 'O':
	    case 'o':
		return "---";
		break;


	    case 'P':
	    case 'p':
		return ".--.";
		break;


	    case 'Q':
	    case 'q':
		return "--.-";
		break;


	    case 'R':
	    case 'r':
		return ".-.";
		break;


	    case 'S':
	    case 's':
		return "...";
		break;


	    case 'T':
	    case 't':
		return "-";
		break;


	    case 'U':
	    case 'u':
		return "..-";
		break;


	    case 'V':
	    case 'v':
		return "...-";
		break;


	    case 'W':
	    case 'w':
		return ".--";
		break;


	    case 'X':
	    case 'x':
		return "-..-";
		break;


	    case 'Y':
	    case 'y':
		return "-.--";
		break;


	    case 'Z':
	    case 'z':
		return "--..";
		break;


	    case ' ':
		return "/";
		break;


	    default:
		return "eeee";                      // if unknown English input is present, then 4 e's are outputted
	 
        }
}    


char morseToEnglish(const char* value)              // this function translates from morse code to English by taking in a const char* mc value and outputting the English equivalent in form of char
{

	if(strcmp(value, ".-") == 0)
	  {
	     return 'A';
	  }


	else if(strcmp(value, "-...") == 0)
	  {
	     return 'B';
	  }


	else if(strcmp(value, "-.-.") == 0)
          {
             return 'C';
          }


	else if(strcmp(value, "-..") == 0)
	  {
	     return 'D';
	  }


	else if(strcmp(value, ".") == 0)
	  {
	     return 'E';
	  }


	else if(strcmp(value, "..-.") == 0)
	  {
	     return 'F';
	  }


	else if(strcmp(value, "--.") == 0)
	  {
	     return 'G';
	  }


	else if(strcmp(value, "....") == 0)
	  {
	     return 'H';
	  }


	else if(strcmp(value, "..") == 0)
	  {
	     return 'I';
          }


	else if(strcmp(value, ".---") == 0)
	  {
	     return 'J';
	  }


	else if(strcmp(value, "-.-") == 0)
	  {
	     return 'K';
	  }


	else if(strcmp(value, ".-..") == 0)
	  {
	     return 'L';
	  }


	else if(strcmp(value, "--") == 0)
	  {
	     return 'M';
  	  }


	else if(strcmp(value, "-.") == 0)
	  {
	     return 'N';
	  }


	else if(strcmp(value, "---") == 0)
	  {
	     return 'O';
	  }


	else if(strcmp(value, ".--.") == 0)
	  {
	     return 'P';
	  }


	else if(strcmp(value, "--.-") == 0)
	  {
	     return 'Q';
	  }


	else if(strcmp(value, ".-.") == 0)
	  {
	     return 'R';
	  }


	else if(strcmp(value, "...") == 0)
	  {
	     return 'S';
	  }


	else if(strcmp(value, "-") == 0)
	  {
	     return 'T';
	  }


	else if(strcmp(value, "..-") == 0)
	  {
	     return 'U';
	  }


	else if(strcmp(value, "...-") == 0)
	  {
	     return 'V';
	  }


	else if(strcmp(value, ".--") == 0)
	  {
	     return 'W';
	  }


	else if(strcmp(value, "-..-") == 0)
	  {
	     return 'X';
	  }


	else if(strcmp(value, "-.--") == 0)
	  {
	     return 'Y';
	  }


	else if(strcmp(value, "--..") == 0)
	  {
	     return 'Z';
	  }


	else if(strcmp(value, "/") == 0)
	  {
	     return ' ';
	  }


	else
	  {
	     return '###';                 // if an unknown morse code value is passed through, this is a default check
	  }

}
