#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Return true (non-zero) if c is the delimiter character
   previously chosen by the user.
   Zero terminators are not printable (therefore false) */
bool delim_character(char c, char delim)
{
   if(c == delim){
      return true;
   }else{
      return false;
   }

}

/* Return true (non-zero) if c is a non-delimiter
   character.
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c, char delim)
{
   if (c != delim){
      return true;
   }else{
      return false;
   }
}

/* Returns a pointer to the first character of the next
   word starting with a non-delimiter character. Return a zero pointer if
   str does not contain any words.*/
char *word_start(char* str,char delim)
{
   int i =0;
   char* p = str;

   //while string not empty
   while(*p != '\0'){

      //if char next to it is a non delim char
      if (non_delim_character(str[i+1], delim)){

         //equals word after delim character
         p = &str[i+1];
         
         //stop loop
         break;
      }
      
      //increment i
      i++;
   }
   return p;
}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char *end_word(char* str,char delim)
{
   int i = 0;
   char* p = NULL;
   //while not the end of string
   while(str[i] != '\0'){
      //if char next to it is a delim char
      if(delim_character(str[i+1],delim)){

         //equals word before delim char
         p = &str[i];

         //stop loop
         break;
      }
      //increment i
      i++;
   }
   return p;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{
   int i = 0;
   int c = 1;
   // while string not empty
   while(str[i] != '\0'){
      //adds 1 at every delim character
      if (delim_character(str[i], delim)){
         c += 1;
      }
   }
   //subtracts 1 due to it not counting the '\0' at the end of the word
   return c-1;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
   char* s =(char*)malloc(len +1);
   for (int i =0; i < len;i++){
      s[i] = inStr[i];
   }
   s[len] = 0;

   return s;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   delimiter-separated tokens from zero-terminated str.
   For example, tokenize("hello world string"), with a character delimiter
   of a space " " would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char** tokenize(char* str, char delim)
{
   int tokensL = count_tokens(str, delim);
   char* start = word_start(str, delim);
   char* end = word_end(start, delim);

   Char** token = (char**)malloc(tokensL + 1) * sizeof(char*)

   for (int i = 0; i < lenTokens;i++){

   }
   

   start = word_start(end, delim);
   end = word_end(start, delim);
}

void print_all_tokens(char** tokens)
{
   for(int i = 0; i < tokens.length; i++){
      cout <<
   }
}
