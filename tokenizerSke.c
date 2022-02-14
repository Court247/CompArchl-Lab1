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
   while(str[i] != '\0'){

      //if char next to it is a non delim char
      if (non_delim_character(str[i], delim)){

         //equals word after delim character
         p = &str[i];
         
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
   str = word_start(str, delim);
   //while not the end of string
   while(str[i] != '\0'){
      //if char next to it is a delim char
      if(delim_character(str[i+1],delim)){
         
         str = &str[i+1];
         break;
      }
      //increment i
      i++;
   }
   return str;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{
   int i = 0;
   int c = 1;
   while(*str != '\0'){
      str = word_start(str, delim);
      str = end_word(str+1,delim);
      c++;
   }
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
   s[len] = '\0';

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
   char* end = end_word(start, delim);

   char** token = (char**)malloc((tokensL + 1) * (sizeof(char*)));

   for (int i = 0; i < tokensL;i++){
      int wordL = end_word(str, delim) - word_start(str, delim);
      token[i] = copy_str(str, wordL);
   }

   start = word_start(end+1, delim);
   end = end_word(start, delim);
}

void print_all_tokens(char** tokens)
{
   for(int i =0; i <sizeof(*tokens);i++){
      printf("%c", tokens[i]);
   }
}

int main(){

   char* c = "Hello How Are You";
   char* e = ",,,hello,,,";
   char b = ',';
   char x = ' ';

   
   //printf(word_start(e, b));
   //printf(end_word(c, x));
   printf("num tokens", count_tokens(c, x));
   //short len = end_word(c, x) - word_start(c, x);
  // printf(copy_str(c, len));
   //tokenize(c, x);

}

