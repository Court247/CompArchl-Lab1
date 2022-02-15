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
   char* p = str;
   //while string not empty
   while(*p != '\0'){

      //if char next to it is a non delim char
      if (non_delim_character(*p, delim)){

         //equals word after delim character
         return p;
         
      }
      else{
         p++;
      }
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
      if((delim_character(str[i+1],delim)) || (str[i+1] == '\0')){
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

   int c = 1;
   // while string not empty
   while(*str!= '\0'){
      str = word_start(str, delim);
      str = end_word(str,delim);
      c++;
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

   char** token = (char**)malloc((tokensL) * (sizeof(char*)));
   
   for (int i = 0; i < tokensL;i++){
      int wordL = end_word(str, delim) - word_start(str, delim);
      token[i] = copy_str(start, wordL);

      start = word_start(end+1, delim);
      end = end_word(start, delim);
   }
   return token;
}

void print_all_tokens(char** tokens)
{
   for (int i =0; *tokens !=0; tokens++){
      printf("Tokens: %s\n", *tokens);
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

   /*char c[] = "Hello,World";
   char* e = c;
   char b = ',';
   char x = ' ';

   char* a = word_start(e,b);
   printf("First letter: %c\n", *a);

   char*r = end_word(e,b);
   printf("Last letter: %c\n", *r);

   int t = count_tokens(e,b);
   printf("output %i\n", t );
   char** q = tokenize(e,b);
   print_all_tokens(q);*/

}

