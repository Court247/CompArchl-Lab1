#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Return true (non-zero) if c is the delimiter character
   previously chosen by the user.
   Zero terminators are not printable (therefore false) */
bool delim_character(char c, char delim)
{
   //if c is the delim character return true
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
   //if c is not a delim character return true
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
   char* p = str;
   //while string not empty
   while(*p != '\0'){

      //if char next to it is a non delim char
      if (non_delim_character(*p, delim)){

         //return the current char
         return p;
         
      }
      else{
         //else move to the next char
         p++;
      }
   }
   //return current char
   return p;
}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char *end_word(char* str,char delim)
{
   int i = 0;
   str = word_start(str, delim);
   //while not the end of string
   while(str[i] != '\0'){
      //if char next to it is a delim char or it is the end of the string
      if((delim_character(str[i+1],delim)) || (str[i+1] == '\0')){
         //set pointer to it
         str = &str[i+1];
         break;
      }
      //increment i
      i++;
   }
   //return pointer
   return str;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{

   int c = 1;
   // while string not empty
   while(*str!= '\0'){
      //find the start of the word
      str = word_start(str, delim);
      //find the end of the word
      str = end_word(str,delim);
      //keep adding until the pointer reaches the end
      c++;
   }
   //subtracts 1 due to it not counting the '\0' at the end of the word
   return c-1;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
   //allocate space with one extra space for the zero terminator
   char* s =(char*)malloc(len +1);
   
   for (int i =0; i < len;i++){
      //copy i into the new char array
      s[i] = inStr[i];
   }
   //put zero terminator at the end of array
   s[len] = '\0';

   //return array
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
   //count how many words are in the string
   int tokensL = count_tokens(str, delim);
   //find the start word
   char* start = word_start(str, delim);
   //then use that output and find the end of the same word
   char* end = end_word(start, delim);

   //allocate space  with an arraythat is the length of however many words are there 
   char** token = (char**)malloc((tokensL) * (sizeof(char*)));
   
   for (int i = 0; i < tokensL;i++){
      //finds the length of each word
      int wordL = end_word(str, delim) - word_start(str, delim);
      //copies the word into an array and it is placed into the token double array
      token[i] = copy_str(start, wordL);

      //uses the end of the last word to find the start of the next word if there is one.
      start = word_start(end+1, delim);
      //uses the placement of where ever the start is to find the end of the same word
      end = end_word(start, delim);
   }
   //returns the token
   return token;
}

void print_all_tokens(char** tokens)
{
   //for the double array as long as  the token does not equal 0
   for (int i =0; *tokens !=0; tokens++){
      //print each array until it reaches 0
      printf("Tokens: %s\n", *tokens);
      //increment i so it can traverse the array
      i++;
   }
}
int main(){

   int MAX_LIMIT = 1000;
   char ch[MAX_LIMIT];
   char b[MAX_LIMIT];

   printf("Enter sentence: ");
   fgets(ch, MAX_LIMIT, stdin);

   printf("Enter delimiter character: ");
   fgets(b, MAX_LIMIT, stdin);

   print_all_tokens(tokenize(ch, b[0]));

   
}

