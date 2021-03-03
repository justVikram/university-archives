#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* left;
    int data;
    int height;
    struct node* right;
}n;

void initTree(n** root)
{
    *root=NULL;
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

int getHeight(n* z)
{
    if (z)
        return z->height;
    
    else
        return 0;
}

int updateHeight(n* z)
{
    int L = getHeight(z->left);
    int R = getHeight(z->right);
    
    if (L > R)
       return z->height = L + 1;
    
    else
        return z->height = R + 1;
}

int getBalanceFactor (n* z)
{
    int L = getHeight(z->left);
    int R = getHeight(z->right);
    return L - R;
}

n* rotateLeft (n* z)
{
    n* y = z->right;
    n* T3 = y->left;
    y->left = z;
    z->right = T3;
    return y;
}

n* rotateRight (n* z)
{
    n* y = z->left;
    n* T3 = y->right;
    y->right = z;
    z->left = T3;
    return y;
}



int addAVL (n** root, int e)
{
    n*p = (n*) malloc(sizeof(n));
    p->data = e;
    p->left = p->right = NULL;
    p->height = 1;
    
    if (!*root)
    {
        *root = p;
        return 1;
    }
    
    ss s;
    initStack(&s);
    n* cur = *root;
    n* par = NULL;
    
    while (cur)
    {
        par = cur;
        push(&s, cur);
        
        if (e < cur->data)
            cur = cur->left;
        
        else if (e > cur->data)
            cur = cur->right;
        
        else
        {
            free (p);
            emptyStack(&s);
            return 0;
        }
    }
    
    if (e < par->data)
        par->left = p;
    
    else
        par->right = p;
    
    while (!isStackEmpty(&s))
    {
        n* z = pop(&s);
        n* y = NULL;
        updateHeight(z);
        int b = getBalanceFactor(z);
        
        if (b < -1 && getBalanceFactor(z->right) <= 0)  //n-n, left rotate
        {
            y = rotateLeft(z);
            updateHeight(z);
            
            if(!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
            
            break;
        }
        
        else if (b > 1 && getBalanceFactor(z->left) >= 0)  //p-p, right rotate
        {
            y = rotateRight(z);
            updateHeight(z);
            
            if(!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
            
            break;
        }
        
        else if (b < -1 && getBalanceFactor(z->left) > 0)  // n-p, right-left rotate
        {
            y = rotateRight(z->right);
            updateHeight(z->right);
            z->right = y;
            updateHeight(y);
            y = rotateLeft(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
            
            break;
        }
        
        else if (b > 1 && getBalanceFactor(z->left) < 0)  //p-n, left-right rotate
        {
            y = rotateLeft(z->left);
            updateHeight(z->left);
            z->left = y;
            updateHeight(y);
            y = rotateRight(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
            
            break;
        }
    }
    emptyStack(&s);
    return 1;
}

int deleteKey(n** root, int e)
{
    ss s;
    initStack(&s);
    n* cur = *root;
    n* par = NULL;
    n* ssr = cur->right;
    n* par_ssr = NULL;
    
    while (cur && cur->data != e)
    {
        par = cur;
        push(&s, cur);
        
        if(e < cur->data)
            cur = cur->left;
        
        else if (e > cur->data)
            cur = cur->right;
    }
    
    if (!cur)
    {
        emptyStack(&s);
        return 0;
    }
    
    if (!cur->left && !cur->right)  //Leaf node deletion
    {
        if (cur == *root)
            *root = NULL;
        
        else if (par->left == cur )
                   par->left = NULL;
        
        else if (par->right == cur)
            par->right = NULL;
    }
    
    else if ((cur->left && !cur->right) || (!cur->left && cur->right))  //single child deletion
    {
        if (cur == *root)
        {
            if (cur->right)
                *root = cur->right;
            
            else
                *root = cur->left;
        }
        
        else if (par->left == cur)
        {
            if (cur->left)
                par->left = cur->left;
            
            else if (cur->right)
                par->left = cur->right;
        }
        
        else if (par->right == cur)
        {
            if (cur->left)
                par->right = cur->left;
            
            else if (cur->right)
                par->right = cur->right;
        }
    }
    
    else if (cur->left && cur->right)  //Full node deletion
    {
        while (ssr->left)
        {
            par_ssr = ssr;
            push(&s, ssr);
            ssr = ssr->left;
        }
        
        if (par_ssr)
            par_ssr->left = ssr->right;
        
        ssr->left = cur->left;
        
        if(cur->right != ssr)
            ssr->right = cur->right;
        
        if (cur == *root)
            *root = ssr;
    }
    
    while(!isStackEmpty(&s))
    {
        n* z = pop(&s);
        
        if (z == cur)
            z = ssr;
        
        updateHeight(z);
        int b = getBalanceFactor(z);
        
        if (b < -1 && getBalanceFactor(z->right) <= 0) // n-n, left rotate
        {
            n* y = rotateLeft(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if (peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
        }
        
        else if (b > 1 && getBalanceFactor(z->left) >= 0)  //p-p, right rotate
        {
            n* y = rotateRight(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if (peek(&s)->right == z)
                    peek(&s)->right= y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
        }
        
        else if (b > 1 && getBalanceFactor(z->left) < 0)  //p-n, left-right rotate
        {
            n* y = rotateLeft(z->left);
            updateHeight(z->left);
            z->left = y;
            updateHeight(y);
            y = rotateRight(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
        }
        
        else if (b < -1 && getBalanceFactor(z->left) > 0)  //n-p, right-left rotate
        {
            n* y = rotateRight(z->right);
            updateHeight(z->right);
            z->right = y;
            updateHeight(y);
            y = rotateLeft(z);
            updateHeight(z);
            
            if (!isStackEmpty(&s))
            {
                if(peek(&s)->right == z)
                    peek(&s)->right = y;
                
                else
                    peek(&s)->left = y;
            }
            
            else
                *root = y;
        }
    }
    free (cur);
    return 1;
}

void preOrder(n* root)
{
    if(!root)
        return;
    
    printf("%d\n",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(n* root)
{
    if(root)
    {
    inOrder(root->left);
    printf("%d\n",root->data);
    inOrder(root->right);
    }
}

void postOrder(n* root)
{
    if(root)
    {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n",root->data);
    }
}


int main()
{
    n* root;
    initTree(&root);
    int e, ch;
    
    while (1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("Enter element to be added:");
                scanf("%d",&e);
                
                if (addAVL(&root, e))
                    printf("Element successfully added\n");
                
                else
                    printf("INVALID: Element is a duplicate\n");
                    
                break;
            case 2:
                printf("Display mode: Pre-order\n");
                preOrder(root);
                break;
            case 3:
                printf("Display mode: In-order\n");
                inOrder(root);
                break;
            case 4:
                printf("Display mode: Post-order\n");
                postOrder(root);
                break;
            case 5:
                printf("Enter element to be deleted");
                scanf("%d", &e);
                
                if(deleteKey(&root,e))
                    printf("Element deleted\n");
                else
                    printf("INVALID: Element not deleted\n");
                
                break;
        }
    }
}
