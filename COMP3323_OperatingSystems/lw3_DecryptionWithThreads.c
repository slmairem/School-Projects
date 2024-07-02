#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

char* decrypt(char* str_message, int key){
    int length = strlen(str_message);
    int i;
    for(i=0 ; i<length ; i++) {
        str_message[i] = (str_message[i]-key-'A'+26)%26+'A'; //26->eng alphb
    }
    
    return str_message;
}

void *decrypt_thread(void *arg)
{
  int key = 2; // shift 2 times to decrypt the message
  char *str_message = (char*)arg;
  
  decrypt(str_message, key);
  void *usr = malloc(strlen(str_message)+1); // +1 for null terminator
  strcpy(usr, str_message);

  pthread_exit(usr); 
}

int main(){
  pthread_t t1, t2; //THREAD YAPISI IÇIN MEMORY DE YER AÇTIM

  char *str_message1 = strdup("FKUEQXGTA");
  char *str_message2 = strdup("OKUUKQP");

  void *first; // it will be used to store the return value of the first thread
  void *second; // it will be used to store the return value of the second thread

  
  //Fill in this part... 
  //1. Create threads
  pthread_create(&t1, NULL, decrypt_thread, str_message1);
  pthread_create(&t2, NULL, decrypt_thread, str_message2);

  //2. join threads
  pthread_join(t1, &first);
  pthread_join(t2, &second);
  
  //3. print the decrypted messages
  printf("%s\n", (char*) first);
  printf("%s", (char*) second);
  
  //4. free memory
  free(first);
  free(second);

  pthread_exit(NULL);
}