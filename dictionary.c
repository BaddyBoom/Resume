#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define _GNU_SOURCE

struct node{
  char ch[100];
  char h[1000];
  struct node *next;
};
void insert_tail(struct node**,char*,char*);
void search(struct node*,char*);
void display(struct node*);
void insert_at(struct node**,char*,char*);

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void main()
{
  struct node *dict;
  dict=NULL;
  char *a,*b,w[100],str[1000],x[100],y[1000];
  int nbytes = 1000;
  char s[2]=",";
  FILE *fp=fopen("dict.csv","r");
  // if (fp == NULL)
  //       exit(EXIT_FAILURE);
  //
  // printf("COOL");
  //
  // while (!feof(fp)) {
  //   if(feof(fp))
  //   {
  //     printf("Breaking\n" );
  //     break;
  //   }
    for(int i=0;i<617;i++)
    {
      fgets(str,1000,fp);
    a=strtok(str,",");
    b=strtok(NULL,",");
    a = trimwhitespace(a);
    b = trimwhitespace(b);
    printf("%s %s\n",a,b);
    insert_tail(&dict,a,b);
}


    fclose(fp);

  // while(!feof(fp))
  // {
  //     fgets(str,1000,fp);
  //
  // }
  display(dict);
  printf("Enter a word");
  scanf("%s",w);
  search(dict,w);
  // printf("Enter a word and defintion");
  // scanf("%s %[^\n]s",x,y);
  // insert_at(&dict,x,y);
  // display(dict);
  // search(dict,x);
  display(dict);
}
void insert_tail(struct node** t,char *ch,char* h)
{
  struct node *temp,*q;
  temp=(struct node*)malloc(sizeof(struct node));
  strcpy(temp->ch,ch);
  strcpy(temp->h,h);
  temp->next=NULL;
  q=*t;
  if(*t==NULL)
   *t=temp;
  else
  {
    while(q->next!=NULL)
    {
      q=q->next;
    }
    q->next=temp;
  }
}


void display(struct node *t){
  while(t->next!=NULL){
    printf("%s , %s\n",t->ch , t->h );
    t = t->next;
  }
  printf("%s , %s\n",t->ch , t->h );


}

void search(struct node *t,char *ch)
{
  // printf("%s\n",ch);
  char ans[2],def[100];
  struct node *q=NULL;
  q=t;
  int i = 0;
  // printf("%d", strcmp(ch,"'absence'"));

  while( q->next != NULL)
  {
      i = strcmp(ch,q->ch);
      if(i == 0)
        break;
    // printf("%s\n",q->ch );
      q=q->next;
  }
 if(strcmp(ch,q->ch)==0)
  printf("%s %s",q->ch,q->h);
else
{
  printf("Do you want to enter definition");
  scanf("%s",ans);
  if(ans[0]=='Y')
  {
    printf("Enter definiton");
    fflush(stdin);
    gets(def);
    insert_at(&t,ch,def);
    FILE *f=fopen("dict.csv","w");
    fseek(f,0,SEEK_END);
    fprintf(f,"%s",ch);
    fprintf(f,"%c",",");
    fputs(def,f);
    fclose(f);
  } 


}
}
void insert_at(struct node **t,char *h,char *g)
{
  struct node *curr,*prev,*temp;
  temp=(struct node*)malloc(sizeof(struct node));
  strcpy(temp->ch,h);
  strcpy(temp->h,g);
  temp->next=NULL;
  curr=*t;
  prev=NULL;
  while(strcmp(curr->ch,h)<0)
  {
    prev=curr;
    curr=curr->next;
  }
  prev->next=temp;
  temp->next=curr;
  FILE *f=fopen("dict.csv","a");
  fprintf(f,"%s",h);
  fputs(g,f);
  fclose(f);

}
