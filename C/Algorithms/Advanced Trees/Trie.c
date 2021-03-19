#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    int doesItEnd;
    struct node *children[26];
}n;

n* getNode()
{
    n* p = (n*) malloc (sizeof(n));
    p->doesItEnd = 0;
    
    for(int i = 0; i < 26; i++)
        *(p->children + i) = NULL;
    
    return p;
}

typedef struct nodeStack
{
    n* data;
    struct nodeStack* next;
}ns;

typedef struct stack
{
    ns* top;
}ss;

void initStack(ss *s)
{
    s->top=NULL;
}

void push(ss *s,n* e)
{
    ns*p = (ns*) malloc(sizeof(ns));
    p->data = e;
    p->next = s->top;
    s->top = p;
}

n* pop(ss *s)
{
    ns* p;
    p = s->top;
    s->top = p->next;
    n* e = p->data;
    free(p);
    return e;
}

int isStackEmpty(ss* s)
{
    return s->top == NULL;
}

void emptyStack(ss* s)
{
    while(!isStackEmpty(s))
        pop(s);
}

n* peek(ss *s)
{
    return s->top->data;
}

int addWord(n** root, char *word)
{
    char ch;
    int index;
    if (! *root)
       *root = getNode();
    
    n* p = *root;
    
    for (int i = 0; *(word + i); i++)
    {
        ch = tolower(*(word + i));
        index = ch - 97;
        
        if (! *(p->children + index))
            *(p->children + index) = getNode();
        
        p = *(p->children + index);
    }
    if (p->doesItEnd)
        return 0;
    
    p->doesItEnd = 1;
    return 1;
}

int searchWord(n* root, char* word)
{
    char ch;
    int index;
    n* p = root;
    
    for(int i = 0; *(word + i); i++)
    {
        ch = tolower(*(word + i));
        index = ch - 97;
        
        if(! *(p->children + index))
            return 0;
        
        p = *(p->children + index);
    }
    return p->doesItEnd;
}

void _displayTrie(n* root, char* word, int level)
{
    if (! root)
        return;
    
    n* p = root;
    n* q = NULL;
    
    for (int i = 0; i < 26; i++)
    {
        q = *(p->children + i);
        
        if (q)
        {
            *(word + level) = i + 97;
            
            if (q->doesItEnd)
            {
                *(word + level + 1) = '\0';
                printf("%s\n", word);
            }
            _displayTrie(q, word, level + 1);
        }
    }
}

void displayTrie(n* root)
{
    if (! root)
    {
        printf("Trie is empty\n");
        return;
    }
    char word[100];
    _displayTrie(root, word, 0);
}

int doesItHaveChildren(n* p)
{
    for (int i = 0; i < 26; i++)
    {
        if (*(p->children + i))
            return 1;
    }
    return 0;
}

int deleteWord(n** root, char* word)
{
    if ( !*root)
        return 0;
    
    unsigned long int index, length = strlen(word) - 1;
    char ch;
    n* p = *root;
    ss s;
    initStack(&s);
    
    for (int i = 0; *(word + i); i++)
    {
        ch = tolower(*(word + i));
        index = ch - 97;
        
        if(! *(p->children + index))
        {
            emptyStack(&s);
            return 0;
        }
        push(&s, p);
        p = *(p->children + index);
    }
    
    if (! p->doesItEnd)
    {
        emptyStack(&s);
        return 0;
    }
    
    p->doesItEnd = 0;
    push(&s, p);
    
    while (!isStackEmpty(&s))
    {
        n* z = pop(&s);
        
        if (! doesItHaveChildren(z) && ! z->doesItEnd)
        {
            if (z == *root)
                *root = NULL;
            
            if (!isStackEmpty(&s))
            {
                ch = tolower(*(word + length));
                index = ch - 97;
                *(peek(&s)->children + index) = NULL;
                length-- ;
            }
            free(z);
        }
        
        else
            break;
    }
    emptyStack(&s);
    return 1;
}

void _deleteTrie(n* root)
{
    if(! root)
        return;
    
    for(int i = 0; i < 26; i++)
    {
        if (*(root->children + i))
            _deleteTrie(*(root->children + i));
    }
    free(root);
}

void deleteTrie(n** root)
{
    _deleteTrie(*root);
    *root = NULL;
}

int main()
{
    n* root = NULL;
    char word[100];
    int ch;
    
    while (1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 1:
                printf("Add word\n");
                printf("Enter word to be added:");
                scanf("%s",word);
                
                if (addWord(&root, word))
                    printf("Word added successfully!\n");
                
                else
                    printf("INVALID: Word could not be added\n");
                
                break;
            case 2:
                printf("Displaying entire Trie\n");
                displayTrie(root);
                break;
            case 3:
                printf("Search word\n");
                printf("Enter word to be searched:");
                scanf("%s",word);
                
                if (searchWord(root, word))
                    printf("Word was found!\n");
                
                else
                    printf("INVALID: Word not found\n");
                break;
            case 4:
                printf("Delete a word\n");
                printf("Enter word to be deleted:");
                scanf("%s", word);
                
                if(deleteWord(&root, word))
                    printf("Word was successfully deleted\n");
                
                else
                    printf("INVALID: Word was not found\n");
                break;
            case 5:
                printf("Deleted entire Trie\n");
                deleteTrie(&root);
                break;
        }
    }
}
