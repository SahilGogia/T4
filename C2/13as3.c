#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 20

struct popNames {
  int year;
  int rank[200];
  char maleName[200][MAXLENGTH];
  int maleNumber[200];
  char femaleName[200][MAXLENGTH];
  int femaleNumber[200];

};

struct popNames popular;

char *removeCommas(char *str)
{
    char *p, *q;
    for (p = q = str; *p; p++)
    if (*p != ',') *q++ = *p;
    *q = 0;
    return str;
}


int main (int argc, char *argv[]){

int d=0;
int x=0;
int be=0;
char v[30];
char gg[30];
char o[30];
char q[30];
char z[30];
char r[30];
char s[30];
char h[30];
char k[30];
char g[30];
int index = 0;
char a[30];
char b[30];
int i,j,l,m,n,t;
char e[30];
char c[30];
char string[300];
char filename[64];
char maleSNumber[100];
char femaleSNumber[100];
FILE *fp;

while(1){
printf ("What decade do you wnat to look at?\n");
fgets (c, 10, stdin);
sscanf (c, "%d", &d);

if (d!=1880 && d!=1890 && d!=1900 && d!=1910 && d!=1920 && d!=1930 && d!=1940 && d!=1950 && d!=1960 && d!=1970 && d!=1980 && d!=1990 && d!=2000 && d!=2010){

  printf ("No reocrds for this year\n");
  exit(1);
}




sprintf (filename, "%dNames.txt", d);

fp = fopen (filename,"r");
if (fp == NULL){

  printf ("ERROR - File cannot be opened\n");
  exit(1);
}
while(1){
while(1){
  printf ("Would you like to see a rank,search for a name, or see the top 10?[rank,search,top]\n");
  fgets (a, 10, stdin);
  sscanf (a, "%s", b);
if ((strcmp(b, "rank") == 0))
{
break;
}




else if ((strcmp(b, "search") == 0))
{
break;
}



 else if ((strcmp(b, "top") == 0))
{
break;
}

else {
printf ("ERROR - Please choose correct option\n");

}
}


if ((strcmp(b, "rank") == 0)){
while(1){
  printf ("What rank do you wish to see?[1-200]\n");
  fgets (k, 10, stdin);
  sscanf (k, "%d", &j);

  if ( j<1 || j>200 ){

    printf ("Rank out of range\n");
  }

  else {

    break;
  }
}
while(1){
  printf ("Would you like to see male(0), female(1), or both(2)name(s)?[0-2]:\n");
  fgets (g, 10, stdin);
  sscanf (g, "%d", &l);

  if (l!=0 && l!=1 && l!=2)
{
printf ("choose correct option\n");

}
else {
break;

}
}


if (l == 0){
while (fgets(string, 100, fp) != NULL ){


  sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

  removeCommas(maleSNumber);
  popular.maleNumber[index] = atoi(maleSNumber);

  removeCommas(femaleSNumber);
  popular.femaleNumber[index] = atoi(femaleSNumber);

 index++;

}

for (i=(j-1); i==(j-1) ; i++){

  printf ("Rank %d:",j);
  printf ("Male: ");
  printf ("%s %d\n", popular.maleName[i], popular.maleNumber[i]);

}

}




else if (l == 1){
while (fgets(string, 100, fp) != NULL ){


  sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

  removeCommas(maleSNumber);
  popular.maleNumber[index] = atoi(maleSNumber);

  removeCommas(femaleSNumber);
  popular.femaleNumber[index] = atoi(femaleSNumber);

 index++;

}

for (i=(j-1); i==(j-1) ; i++){

  printf ("Rank %d:",j);
  printf ("Female: ");
  printf ("%s %d\n", popular.femaleName[i], popular.femaleNumber[i]);

}

}






else if (l == 2){
while (fgets(string, 100, fp) != NULL ){


  sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

  removeCommas(maleSNumber);
  popular.maleNumber[index] = atoi(maleSNumber);

  removeCommas(femaleSNumber);
  popular.femaleNumber[index] = atoi(femaleSNumber);

 index++;

}

for (i=(j-1); i==(j-1) ; i++){

  printf ("Rank %d:",j);

  printf ("Male: %s %d and Female: %s %d\n", popular.maleName[i], popular.maleNumber[i], popular.femaleName[i], popular.femaleNumber[i]);

}

}
}

if ((strcmp(b, "search") == 0)){


    printf ("What name do you want to search for?[case sensitive]:\n");
    fgets (h, 10, stdin);
    sscanf (h, "%s", s);


    while(1){
      printf ("Would you like to see male(0), female(1), or both(2)name(s)?[0-2]:\n");
      fgets (r, 10, stdin);
      sscanf (r, "%d", &t);

      if (t!=0 && t!=1 && t!=2)
    {
    printf ("choose correct option\n");

    }
    else {
    break;

    }
    }

    if ( t == 0){
    while (fgets(string, 100, fp) != NULL ){


      sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

      removeCommas(maleSNumber);
      popular.maleNumber[index] = atoi(maleSNumber);

      removeCommas(femaleSNumber);
      popular.femaleNumber[index] = atoi(femaleSNumber);

     index++;

    }

    for (i=0; i<200 ; i++){
    popular.rank[i];
    popular.maleNumber[i];
    if (strcmp(popular.maleName[i],s)==0){

      printf ("In %d,the male name %s is ranked %d with a count of %d\n", d, s, popular.rank[i], popular.maleNumber[i] );
       break;
    }

}
for (i=0; i<200 ; i++){
popular.rank[i];
popular.maleNumber[i];
if (strcmp(popular.maleName[i],s)==0){
++x;

}
}
if (x == 0)
{
printf ("In the year %d the male name %s is not ranked\n",d, s);

}

}


   if ( t == 1){
    while (fgets(string, 200, fp) != NULL ){


      sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

      removeCommas(maleSNumber);
      popular.maleNumber[index] = atoi(maleSNumber);

     removeCommas(femaleSNumber);
      popular.femaleNumber[index] = atoi(femaleSNumber);

     index++;

    }

    for (i=0; i<200 ; i++){
    popular.rank[i];
    popular.femaleNumber[i];
    if (strcmp(popular.femaleName[i],s)==0){

      printf ("In %d,the female name %s is ranked %d with a count of %d\n", d, s, popular.rank[i], popular.femaleNumber[i] );
       break;
    }



  }

  for (i=0; i<200 ; i++){
  popular.rank[i];
  popular.femaleNumber[i];
  if (strcmp(popular.femaleName[i],s)==0){
  ++x;

  }
  }
  if (x == 0)
  {
  printf ("In the year %d the female name %s is not ranked\n",d, s);

  }
}
  if ( t == 2){
  while (fgets(string, 200, fp) != NULL ){


    sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

    removeCommas(maleSNumber);
    popular.maleNumber[index] = atoi(maleSNumber);

    removeCommas(femaleSNumber);
    popular.femaleNumber[index] = atoi(femaleSNumber);

   index++;

  }


  for (i=0; i<200 ; i++){
  popular.rank[i];
  popular.femaleNumber[i];

  if (strcmp(popular.femaleName[i],s)==0){
        ++be;
        if (be > 0){
        printf ("In %d the female name %s is ranked %d with a count of %d ",d, s, popular.rank[i], popular.femaleNumber[i]);

        }
}
}if (be == 0){
printf ("In %d the female name %s is not ranked ",d, s);

}

for (i=0; i<200 ; i++){
popular.rank[i];
popular.maleNumber[i];

if (strcmp(popular.maleName[i],s)==0){
      ++x;
      if (x > 0 && be == 0){
    printf ("and the male name %s is ranked %d with a count of %d\n", s, popular.rank[i], popular.maleNumber[i]);

      }
}else if (x > 0 && be > 0){
printf ("and the male name %s is ranked %d with a count of %d\n", s, popular.rank[i], popular.maleNumber[i]);

}else if (x == 0 && be > 0){
printf ("and the male name %s is not ranked \n", s);

}
}
}



}


         if ((strcmp(b, "top") == 0)){


while (fgets(string, 100, fp) != NULL ){


  sscanf ( string, "%d %s %s %s %s\n", &popular.rank[index], popular.maleName[index], maleSNumber, popular.femaleName[index], femaleSNumber);

  removeCommas(maleSNumber);
  popular.maleNumber[index] = atoi(maleSNumber);

  removeCommas(femaleSNumber);
  popular.femaleNumber[index] = atoi(femaleSNumber);

 index++;

}

for (i=0; i<10 ; i++){

printf ("%d %s %d %s %d\n", popular.rank[i], popular.maleName[i], popular.maleNumber[i], popular.femaleName[i], popular.femaleNumber[i]);

}
}



while (1){
printf ("Do you want to ask another question about %d?\n", d);
fgets (o, 10, stdin);
sscanf (o, "%s", q);


if (strcmp(q,"Y")==0 || strcmp(q,"y")==0 || strcmp(q,"N")==0 || strcmp(q,"n")==0){
break;


}else{

  printf ("Only single character Y or N are accpetable\n");
}
}


if (strcmp(q,"N")==0 || strcmp(q,"n")==0){

break;

}
else {}
}

printf ("Would you like to select another Year?[Y or N]\n");
fgets (v, 10, stdin);
sscanf (v, "%s", gg);





if (strcmp(gg,"N")==0 || strcmp(gg,"n")==0){
  break;

printf ("Thank you for using babyQuery.\n");


}
}
























fclose(fp);


return 0;
}
