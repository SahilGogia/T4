

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/wait.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>
#define OUT    0 
#define IN    1 
unsigned countWords(char *str) 
{ 
    int state = OUT; 
    unsigned wc = 0;  // word count 
  
    // Scan all characters one by one 
    while (*str) 
    { 
        // If next character is a separator, set the  
        // state as OUT 
        if (*str == ' ' || *str == '\n' || *str == '\t') 
            state = OUT; 
  
        // If next character is not a word separator and  
        // state is OUT, then set the state as IN and  
        // increment word count 
        else if (state == OUT) 
        { 
            state = IN; 
            ++wc; 
        } 
  
        // Move to next character 
        ++str; 
    } 
  
    return wc; 
} 

void removeSpecialCharacter(char *str) {
  int source = 0; 
  int destination = 0; 

  while (str[source] != '\0') {
    if (isalpha(str[source])) {
      str[destination] = str[source];
      ++destination;
    }
    ++source;       }
  str[destination] = '\0';
}char *strremove(char *str, const char *sub) {
    char *p, *q, *r;
    if ((q = r = strstr(str, sub)) != NULL) {
        size_t len = strlen(sub);
        while ((r = strstr(p = r + len, sub)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return str;
}
int bgd=0;
int f=0;
int rec=0;
pid_t pidww1[200];
pid_t pidwc;
//int c=0;

int op=1;

int dn;

void child_exit(int sig)
{

   int ch=0;
   
	pid_t pidww;
	while(ch<200){
        if(pidww1[ch]!=0){
			pidww = pidww1[ch];
			if(waitpid(pidww,NULL,WNOHANG)!=0){
				pidww1[ch] =0;
				rec++;
				dn = ch+1;
				
			}
          
		}ch++;
	}
	
   
}

int main(int argc, char **argv){
 int status;
int de=-1;
int ski=0;
char c[200];
int wordcount;
int terminate;
int inv=0;
int or=0;
int cpn=0;
int clear=0;
char *global;
int norm=0;
 int skip=0;
int histn=0;
char *exet="";
while(1){

char d1[20]="";
char d2[20]="";
char d3[20]="";
char d4[20]="";
char d5[20]="";
char d6[20]="";
char d7[20]="";

char d8[20]="";
char d9[20]="";
char d10[20]="";
char filename[30]="";
char filename1[30]="";
int k=0;
int a=0;
int sk=0;
int check=0;
char *commands[1000] = { NULL };
if(rec!= 0){
	printf("\n");
	while(rec!=0){
	printf("[ ]+ DONE            \n",dn);
	rec--;
	if(cpn!=0){
		cpn--;
	}	
	}
	
}

clear = 0;
histn++;
printf(">");
fgets (c, 300, stdin);
if(strcmp(c,"\n")==0){
	continue;
}else if(strstr(c,"clear")!=NULL){
	clear =1;
	
}else if(strstr(c,"exit")!=NULL){
	printf("myShell terminating...");
	wait(NULL);
	printf("\n\n[Process completed]\n");
	exit(1);
}
 waitpid(-1,&status,WNOHANG);


int cnt = countWords(c);

int background =0;
int pos=0;
int ouredirect =0;
int inredirect =0;
int repos=0;
char *redirect = ">";
char *iredirect = "<";
char *pipe1 = "|";
int redirection=0;
if(strstr(c,redirect)!=NULL  && strstr(c,iredirect)!=NULL && strstr(c,"|")==NULL){

if(strstr(c,"&")!=NULL){
		background =1;
}
int f;
	int i=0;
	int x;
	int j=0;
	char a1[200];
	char b[200];
	strcpy(a1,c);
	strcpy(b,c);
	char* token = strtok(a1, " ");

	   while(token != NULL){
	   if(j==0){
                 x=i;
				 
		   }
	   
	   if(f==1){
		   strcpy(filename1,token);
		   f=0;
	   }
	   if(strcmp(token,"<")==0){
		   j=1;
		  
        f=1;
	   }
	   token = strtok(NULL, " ");
	   i++;
   }

   
a=0;
char* token1 = strtok(b, " ");
 while(token1 != NULL){

	 if(strcmp(token1,"<")==0){
		 break;
	 }        
           commands[a] = token1;
		  
			a++;

	   token1 = strtok(NULL, " ");
   }

   a=0;

char *exet1="";
int exi=0;
if(a==0){
			  exet1 = malloc(strlen(commands[a])+1);
			 strcpy(exet1,commands[a]);
		      if(strstr(exet1,"./")!=NULL){
			   char *cc = strremove(exet, "./");
            if( access( cc, F_OK ) == 0 ) {   
				free(exet1);    
     }else{	
		 printf("-myShell: %s: No such file or directory\n",commands[a]);
		 exi =1;
		 free(exet1); 
			continue;
	 }		   
		   }
		     }

char *ptr7 = strchr(filename1, '\n');
       if (ptr7)
        {
            *ptr7  = '\0';
        }

inredirect=1;
f=0;
i=0;
 x=0;
j=0;
char a2[200];
strcpy(a2,c);
token = strtok(a2, " ");

 while(token != NULL){
	   if(j==0){
                 x=i;
				 
		   }
	   
	   if(f==1){
		   strcpy(filename,token);
		   f=0;
	   }
	   if(strcmp(token,">")==0){
		   j=1;
		  
        f=1;
	   }
	   token = strtok(NULL, " ");
	   i++;
   }


char *ptr8 = strchr(filename, '\n');
       if (ptr8)
        {
            *ptr8  = '\0';
        }
ouredirect =1;
 
pid_t pid, wpid;
	FILE *fp1;
	FILE *fp2;
pid=fork();

	 if(pid==0){
       fp1 = freopen(filename1,"r",stdin);
        fp2 = freopen(filename,"w+",stdout);
	   execvp(commands[0],commands);
	 }else{
		 if(background ==0){
             wait(NULL);
		 }else{
			 cpn++;
			  printf("[%d] %d\n",cpn,pid);
			 de++;
					 pidww1[de] = pid;
		 }
	 }


}
 else if(strstr(c,redirect)!=NULL  && strstr(c,pipe1)==NULL ){

	if(strstr(c,"&")!=NULL){
		background =1;
	}
	int f;
	int i=0;
	int x;
	int j=0;
	char a1[200];
	char b[200];
	strcpy(a1,c);
	strcpy(b,c);
	char* token = strtok(a1, " ");
   while(token != NULL){
	   if(j==0){
                 x=i;
				 
		   }
	   
	   if(f==1){
		   strcpy(filename,token);
		   f=0;
	   }
	   if(strcmp(token,">")==0){
		   j=1;
		  
        f=1;
	   }
	   token = strtok(NULL, " ");
	   i++;
   }





char* token1 = strtok(b, " ");
 while(token1 != NULL){

	 if(strcmp(token1,">")==0){
		 k=1;
		 break;
	 }        
           commands[a] = token1;
		  
			a++;

	   token1 = strtok(NULL, " ");
   }

char *ptr9 = strchr(filename, '\n');
       if (ptr9)
        {
            *ptr9  = '\0';
        }
ouredirect =1;
pid_t pid, wpid;
	FILE *fp;
	 pid=fork();

	 if(pid==0){
       fp = freopen(filename,"w+",stdout);

	   execvp(commands[0],commands);


	 }else{
		 if(background ==0){
             wait(NULL);
		 }else{
			 cpn++;
			  printf("[%d] %d\n",cpn,pid);
			 de++;
					 pidww1[de] = pid;
		 }
	 }
}

else if(strstr(c,iredirect)!=NULL  && strstr(c,pipe1)==NULL){
	if(strstr(c,"&")!=NULL){
		background =1;
	}
	int f;
	int i=0;
	int x;
	int j=0;
	char a1[200];
	char b[200];
	if(check ==0){
	strcpy(a1,c);
	strcpy(b,c);
	}else{
	}
	char* token = strtok(a1, " ");
   while(token != NULL){
	   if(j==0){
                 x=i;
				 
		   }
	   
	   if(f==1){
		   strcpy(filename,token);
		   f=0;
	   }
	   if(strcmp(token,"<")==0){
		   j=1;
		  
        f=1;
	   }
	   token = strtok(NULL, " ");
	   i++;
   }
a=0;

char* token1 = strtok(b, " ");
 while(token1 != NULL){

	 if(strcmp(token1,"<")==0){
		 break;
	 }        
           commands[a] = token1;
		
		  
			a++;

	   token1 = strtok(NULL, " ");
   }

   char *exet1="";
int exi=0;
a=0;
if(a==0){
			  exet1 = malloc(strlen(commands[a])+1);
			 strcpy(exet1,commands[a]);
		      if(strstr(exet1,"./")!=NULL){
			   char *cc = strremove(exet1, "./");
            if( access( cc, F_OK ) == 0 ) {   
				free(exet1);    
     }else{	
		 printf("-myShell: %s: No such file or directory\n",commands[a]);
		 exi =1;
		 free(exet1); 
			continue;
	 }		   
		   }
		     }

char *ptr10 = strchr(filename, '\n');
       if (ptr10)
        {
            *ptr10  = '\0';
        }

inredirect=1;
pid_t pid, wpid;
	FILE *fp;
	 pid=fork();

	 if(pid==0){ 
       fp = freopen(filename,"r",stdin);

	   execvp(commands[0],commands);


	 }else{
		 if(background ==0){
             wait(NULL);
		 }else{
			 cpn++;
			  printf("[%d] %d\n",cpn,pid);
			 de++;
					 pidww1[de] = pid;
		 }
	 }


}
else if(strstr(c,pipe1)!=NULL && strstr(c,"<")!=NULL){
int ir=0;
int or=0;
	if(strstr(c,"&")!=NULL){
		background =1;
	}if(strstr(c,"<")!=NULL){
		ir =1;
	}if(strstr(c,">")!=NULL){
		or =1;
	}

	char b1[200];
	char a1[200];
strcpy(b1,c);
strcpy(a1,c);
char *comm1[200]={NULL};
char *comm2[200]={NULL};
char *iarray[200]={NULL};
char *tarray[200]={NULL};
int ctr=0;
int ctr1=0;
int ctr2=0;
int icheck=0;
int ocheck =0;
int p=0;
int rec=0;
int ored=0;
int cr=0;
int pippe =0;
int block=0;
int o=0;
int i=0;
int iff=0;
int ski =0;
char* token2 = strtok(b1, " ");
   while(token2 != NULL){
	  
	   if(strcmp(token2,"|")==0){
            break;
	}
    if(strcmp(token2,"<")==0){
            ski=1;
	}if(ski==1){
		strcpy(filename,token2);
		
	}
     if(ski==0){
		 iarray[ctr] = token2;
		 ctr++;
	 }
	   token2 = strtok(NULL, " ");
	   
   }

   char *exet2="";
int exi=0;
int min =0;
if(min==0){
			  exet2 = malloc(strlen(iarray[min])+1);
			 strcpy(exet2,iarray[min]);
		      if(strstr(exet2,"./")!=NULL){
			   char *cc = strremove(exet2, "./");
            if( access( cc, F_OK ) == 0 ) {   
				free(exet2);    
     }else{	
		 printf("-myShell: %s: No such file or directory\n",iarray[min]);
		 exi =1;
		 free(exet2); 
			continue;
	 }		   
		   }
		     }
int c1 =0;
int c2=0;
int ch=0;
int cont=0;
int j=0;
token2 = strtok(a1, " ");
 while(token2 != NULL){
	 char *ptr4 = strchr(token2, '\n');
       if (ptr4)
        {
            *ptr4  = '\0';
        }
	 
if(strcmp(token2,">")==0){
	j=1;
}
if(j==1 && strcmp(token2,">")!=0 && strcmp(token2,"&")!=0){
  strcpy(filename1,token2);
  char *ptr6 = strchr(filename1, '\n');
       if (ptr6)
        {
            *ptr6  = '\0';
        }
}else{
	 if(strcmp(token2,"|")==0){
            cont++;    
	 }
if(cont==1 && strcmp(token2,"|")!=0 && j==0 && strcmp(token2,"&")!=0){
	tarray[ctr1] = token2;

	ptr4 = strchr(tarray[ctr1], '\n');
       if (ptr4)
        {
            *ptr4  = '\0';
        }
	ctr1++;
}        
}
  token2 = strtok(NULL, " ");

   }

FILE *fp;
FILE *fp2;

	
       int pipefd1[2];
	   pipe(pipefd1);  
	   pid_t pir,pir1;
	   pir = fork();
	   if(pir==0){
		   close(pipefd1[0]); 
        dup2(pipefd1[1], STDOUT_FILENO); 
       close(pipefd1[1]);
	  freopen(filename,"r",stdin);
		   execvp(iarray[0],iarray);
	   }else{
          pir1 = fork();

		  if(pir1==0){
              close(pipefd1[1]);
			   dup2(pipefd1[0], STDIN_FILENO); 
            close(pipefd1[0]); 
			if(or==1){
                int fd = open(filename1, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); //for output
                dup2(fd,1);  //for output
            close(fd);
            }
               execvp(tarray[0],tarray);

		  }else{
               // parent executing, waiting for two children 
            close(pipefd1[0]); 
           close(pipefd1[1]); 
		   if(background==1){
              cpn++;
			  printf("[%d] %d\n",cpn,pir);
		   }else{
		  	wait(NULL); 
		   }
		  }
            if(background ==0){
	
            wait(NULL); 
		   }else{
              
			 de++;
					 pidww1[de] = pir;
		   }
	   }

	

}

else if(strstr(c,pipe1)!=NULL){
    if(strstr(c,"&")!=NULL){
        background =1;
    }

    char b1[200];
strcpy(b1,c);
char *comm1[200]={NULL};
char *comm2[200]={NULL};
int ctr=0;
int icheck=0;
int ocheck =0;
int p=0;
int rec=0;
int ored=0;
int cr=0;
int pippe =0;
int block=0;
int o=0;
int i=0;
char* token2 = strtok(b1, " ");
   while(token2 != NULL){
       pippe=0;
       block  = 0;
       /* if(icheck ==1){
            strcpy(filename,token2);
            icheck =0;
            continue;
        }*/
        if(ocheck ==1){
            strcpy(filename1,token2);
            ocheck =0;
            ored =1;
            o=1;
            block  = 1;
            
        }
       /*if(strcmp(token2,"<")==0){
             icheck=1;
             continue;
       } */  if(strcmp(token2,">")==0){
             ocheck=1;
             o=1;
            block =1;
            
       }
       if(strcmp(token2,"|")==0){
           p=1;
           pippe=1; 
          
       }
if(pippe==0){
if(block ==0){
    if(p==0){
      comm1[ctr] = token2;
    }else{
         comm2[cr] = token2;
         rec = cr;
         cr++;
         p=0;
    }
}
}
       token2 = strtok(NULL, " ");
       ctr++;

   }
char *ptr4 = strchr(filename1, '\n');
       if (ptr4)
        {
            *ptr4  = '\0';
        }

ptr4 = strchr(comm2[rec], '\n');
       if (ptr4)
        {
            *ptr4  = '\0';
        }
FILE *fp;
FILE *fp2;
if(i == 1){
fp = freopen(filename,"r",stdin);
}
    

int pipefd[2];  
    pid_t p1, p2; 
  
    if (pipe(pipefd) < 0) { 
        printf("\nPipe could not be initialized"); 
        return 1; 
    } 
    p1 = fork(); 
    if (p1 < 0) { 
        printf("\nCould not fork"); 
        return 1; 
    } 
  
    if (p1 == 0) { 
        // Child 1 executing.. 
        // It only needs to write at the write end 
        close(pipefd[0]); 
        dup2(pipefd[1], STDOUT_FILENO); 
        close(pipefd[1]); 
  
        if (execvp(comm1[0], comm1) < 0) { 
            printf("\nCould not execute command 1.."); 
            exit(0); 
        } 
    } else { 
        // Parent executing 
        p2 = fork(); 
  
        if (p2 < 0) { 
            printf("\nCould not fork"); 
            return 1; 
        } 
  
        // Child 2 executing.. 
        // It only needs to read at the read end 
        if (p2 == 0) { 
            
            //printf(" fd %d",fd);
            close(pipefd[1]); 
            dup2(pipefd[0], STDIN_FILENO); 
            close(pipefd[0]); 
            if(o==1){
                int fd = open(filename1, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); //for output
                dup2(fd,1);  //for output
            close(fd);
            }

        
            if (execvp(comm2[0], comm2) < 0) { 
                printf("\nCould not execute command 2.."); 
                exit(0); 
            } 
        } else { 
            // parent executing, waiting for two children 
            close(pipefd[0]); 
           close(pipefd[1]); 
		   if(background ==1){
               cpn++;
			  printf("[%d] %d\n",cpn,p1);
			 
		   }else{
			   wait(NULL); 
		   }

        
           
        } if(background ==0){
	     
            wait(NULL); 
		   }else{
			   de++;
					 pidww1[de] = p1;
		   }
         
    }
}

else{

	int bkg=0;
	if(strstr(c,"&")!=NULL){
		bkg =1;
}
   char d[300];
  strcpy(d,c);
		int c=0;
	const char filexec1 = '.';
	const char filexec2 = '/';
	
  char* token3 = strtok(d, " ");
  int exi=0;
 
 while(token3 != NULL){
 char *ptr = strchr(token3, '\n');
        if (ptr)
        {
            *ptr  = '\0';
        }
if(bkg==1){
	
	 if(strcmp(token3,"&")==0){
		 
		 break;
	 }   
}     

           commands[a] = token3;
		  
		if(a==0){
			  exet = malloc(strlen(commands[a])+1);
			 strcpy(exet,commands[a]);
		      if(strstr(exet,"./")!=NULL){
			   char *cc = strremove(exet, "./");
            if( access( cc, F_OK ) == 0 ) {   
				free(exet);    
     }else{	
		 printf("-myShell: %s: No such file or directory\n",token3);
		 exi =1;
		 free(exet); 
			break;
	 }		   
		   }
		     }

		
			a++;


	   token3= strtok(NULL, " ");
}if(exi==1){
	continue;
}

     pidwc=fork(); 
 
       if(pidwc ==0){
      f = getpid();
	  int status = execvp(commands[0],commands);
         if(status<0){
			 printf("bash: %s: command not found\n",commands[0]);
		 }
		 exit(1);
		 }
		 
		 else{

			 if(bkg==0){
				 norm = -1;
				 bgd=0;
				 wait(NULL);
			 }else{
				 cpn++;
				 bgd=1;
				 norm=0;
				    bgd=1;
					de++;
					 pidww1[de] = pidwc;
				 printf("[%d] %d\n",cpn,pidwc);
				 	
				 bkg=0;
				
			 }
			

			 
		 }

	

}

signal(SIGCHLD,child_exit); 
	 
}
  


    return 0;
}




