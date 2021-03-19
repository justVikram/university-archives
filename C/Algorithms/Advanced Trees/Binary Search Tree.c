#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}n;

void initTree (n ** root)
{
    *root=NULL;
}

n* getNode (int e)
{
    n* p=(n*)malloc(sizeof(n));
    p->data=e;
    p->left=p->right=NULL;
    return p;
}

typedef struct nodeQueue
{
    struct node *data;
    struct nodeQueue *next;
}nq;


typedef struct Queue
{
    nq *front;
    nq *rear;
}sq;

n* getFront(sq *q)
{
    return q->front->data;
}

void EnQueue(sq *q, n *e)
{
    nq *p;
    p=(nq*)malloc(sizeof(nq));
    
    if(!p)
    {
        printf("Memory Full \n");
        return;
    }

    p->data = e;
    p->next = NULL;

    if(!q->rear)
        q->front = q->rear = p;

    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

n* DeQueue(sq *q)
{
    nq *p = q->front;
    q->front = p->next;
    
    if(q->front == NULL)
        q->rear = NULL;

    struct node *e = p->data;
    free(p);
    return e;
}

int isQueueEmpty(const struct Queue *q)
{
    return q->rear==NULL;
}


void initQueue(sq *q)
{
    q->front = q->rear = NULL;
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

int isStackEmpty(ss* s)
{
    return s->top == NULL;
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

n* peek(ss *s)
{
    return s->top->data;
}

typedef struct HD
{
    n* nodeData;
    int hd;
}hd;

typedef struct nodeView
{
    hd data;
    struct nodeView* next;
}nv;

typedef struct ViewQueue
{
    nv* front;
    nv* rear;
}vq;

void view_initQueue(vq *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int view_isQueueEmpty(vq *q)
{
    return q->front == NULL;
}

void view_EnQueue(vq* q, hd e)
{
    nv *p;
    p=(nv*)malloc(sizeof(nv));
    
    if(!p)
    {
        printf("Memory Full \n");
        return;
    }

    p->data = e;
    p->next = NULL;

    if(!q->rear)
        q->front = q->rear = p;

    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

hd view_DeQueue(vq *q)
{
    nv *p = q->front;
    q->front = p->next;
    
    if(q->front == NULL)
        q->rear = NULL;

    hd e = p->data;
    free(p);
    return e;
}

typedef struct nodeList
{
    hd data;
    struct nodeList* next;
}nl;

void addFront(nl** head, hd e)
{
    nl*p = (nl*)malloc(sizeof(nl));
    p->data = e;
    p->next = *head;
    *head = p;
}

int list_search(nl* head, int key)
{
    nl*p = head;
    while(p)
    {
        if(p->data.hd == key)
            return 1;
        
        p = p->next;
    }
    return 0;
}

void replaceInList(nl** head, hd e)
{
    nl* cur = *head;
    
    while(cur->data.hd != e.hd)
        cur = cur->next;
    
    cur->data.nodeData = e.nodeData;
}

void displaySLL(nl* head)
{
    nl* cur = head;
    
    while(cur)
    {
        printf("%d\n",cur->data.nodeData->data);
        cur = cur->next;
    }
}

void displayDLL(n* head)
{
    n* cur = head;
    
    while(cur)
    {
        printf("%d\n", cur->data);
        cur = cur->right;
    }
}

void addBST(n** root, int e)
{
    n * p =  getNode (e);
    
    if (! * root)
    {
        *root = p;
        printf("%d initialized as root of the tree.\n",(*root)->data);
    }
    
    else
    {
        n * cur = *root;
        n * par = NULL;
        
        while (cur)
        {
            par = cur;
            
            if(e > cur->data)
                cur = cur->right;
            
            else if(e < cur->data)
                cur = cur->left;
            
            else
            {
                free(p);
                printf("ERROR - Duplicate data\n");
                return;
            }
        }
        
        if(e > par->data)
               par->right = p;
        
        else if(e < par->data)
               par->left = p;
    }
}

//                                                                      addBST using Recursion
n* rec_addBST(n* root, int e)
{
    n * p = NULL;
    
    if (! root)
    {
        p = getNode(e);
        return p;
    }
    
    if(e > root->data)
        root->right = rec_addBST (root->right, e);
    
    else if(e < root->data)
        root->left = rec_addBST (root->left, e);
    
    else
        free(p);
    
    return root;
}


void preOrder(n* root)
{
    if (! root)
        return;
    
    printf ("%d\n", root->data);
    preOrder (root->left);
    preOrder (root->right);
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


void levelOrder(n* root)
{
    sq q;
    n * e;
    initQueue(&q);
    EnQueue(&q, root);
    
    while (! isQueueEmpty (&q))
    {
        e = DeQueue(&q);
        printf("%d\n",e->data);
        
        if(e->left)
            EnQueue(&q, e->left);
        
        if(e->right)
            EnQueue(&q, e->right);
    }
}


void itr_preOrder(n* root)
{
    ss s;
    initStack(&s);
    push(&s, root);
    
    while(!isStackEmpty(&s))
    {
        n*p = pop(&s);
        printf("%d\n",p->data);
        
        if( p->right)
            push (&s, p->right);
        
        if (p->left)
            push (&s, p->left);
    }
}

void itr_inOrder(n* root)
{
    ss s;
    initStack(&s);
    n*cur = root;
    
    while(!isStackEmpty(&s) || cur)
    {
        while(cur)
        {
            push(&s,cur);
            cur = cur->left;
        }
        
        cur = pop(&s);
        printf("%d\n",cur->data);
        cur = cur->right;
    }
}

void itr_postOrder(n* root)
{
    n*cur = root;
    ss s;
    initStack(&s);
    
    while(!isStackEmpty(&s) || cur)
    {
        while(cur)
        {
        if(cur->right)
            push(&s, cur->right);
        
        push(&s,cur);
        cur = cur->left;
        }
        
        cur = pop(&s);
    
        if(!isStackEmpty(&s) && cur->right && cur->right == peek(&s))
        {
            pop(&s);
            push(&s,cur);
            cur = cur->right;
        }
    
        else
        {
            printf("%d\n",cur->data);
            cur = NULL;
        }
    }
}

int height(n * root)
{
    if(!root)
        return 0;
    
    int L = height(root->left);
    int R = height(root->right);
    int max = L > R? L : R;
    return max + 1;
}

int _diameter(n* root, int* p)
{
    if(!root)
        return 0;
    
    int L = _diameter(root->left, p);
    int R = _diameter(root->right, p);
    int sum = L + R + 1;
    
    if(*p < sum)
        *p = sum;
    
    int c;
    c = L > R? 1+L : 1+R;
    return c;
    
}

int diameter(n* root)
{
    int max = INT_MIN;
    _diameter(root, &max);
    return max;
}

void sumOfEachLevel(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q,root);
    EnQueue(&q, NULL);
    int sum = 0;
    
    while(!isQueueEmpty(&q))
    {
        n* u = DeQueue(&q);
        
        if(u)
        {
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
            
            sum += u->data;
        }
        
        else
        {
            printf("%d\n",sum);
            sum = 0;
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
}

int countNodes(n* root)
{
    if(root)
    {
        int L = countNodes(root->left);
        int R = countNodes(root->right);
        return L + R + 1;
    }
    return 0;
}

int levelOrder_countNodes(n* root)
{
    int c = 0;
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        c++;
        
        if(u->left)
            EnQueue(&q, u->left);
        
        if(u->right)
            EnQueue(&q, u->right);
    }
    return c;
}

int usingQueue_countLeafNodes(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    int c = 0;
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(!u->left && !u->right)
            c++;
        
        if(u->left)
            EnQueue(&q,u->left);
        
        if(u->right)
            EnQueue(&q,u->right);
    }
    return c;
}

//                                                                 Counting Leaf Nodes using Iterative Pre-order
int usingStack_countLeafNodes(n* root)
{
    ss s;
    initStack(&s);
    push(&s, root);
    int c = 0;
    
    while(!isStackEmpty(&s))
    {
        n* u = pop(&s);
        
        if(!u->left && !u->right)
            c++;
        
        if(u->left)
            push(&s,u->left);
        
        if(u->right)
            push(&s,u->right);
    }
    return c;
}

int _rec_countLeafNodes(n* root,int* p)
{
    if(!root)
        return 0;
    
    int L = _rec_countLeafNodes(root->left, p);
    int R = _rec_countLeafNodes(root->right, p);
    
    if (!(L + R))
        (*p)++;
    
    return 1;
}

int rec_countLeafNodes(n* root)
{
    int max = 0;
    int* p = &max;
    _rec_countLeafNodes(root, p);
    return max;
}

int countHalfNodes(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    int c = 0;
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if((!u->left && u->right) || (!u->right && u->left))
            c++;
        
        if(u->left)
            EnQueue(&q,u->left);
        
        if(u->right)
            EnQueue(&q,u->right);
    }
    return c;
}

int countLevels(n* root)
{
    sq q;
    int c = 0;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
        }
        
        else
        {
            c++;
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
    return c;
}

void highestSumOfLevels(n* root)
{
    int sum = 0, maxsum = 0;
    int index = 0, maxindex = -1;
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            sum += u->data;
            
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
        }
        
        else
        {
            if(maxsum < sum)
            {
                maxsum = sum;
                maxindex = index;
            }
            sum = 0;
            index++;
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
    printf("Index of level with the highest sum = %d\n",maxindex);
    printf("Highest sum = %d\n",maxsum);
}

static void locateKey (n ** cur, int key, n ** par)
{
    while(* cur && (* cur)->data != key)
    {
        * par = * cur;
        
        if(key < (*cur)->data)
            *cur = (*cur)->left;
        
        else
            *cur = (*cur)->right;
    }
}

static void deleteLeafNode(n * cur, n ** par, n ** root)
{
    if(cur == *root)
        *root = NULL;
    
    else if((*par)->right == cur)
        (*par)->right = NULL;
    
    else if((*par)->left == cur)
        (*par)->left = NULL;
    
    free(cur);
}

static void deleteHalfNode (n * cur, n ** par, n ** root)
{
    if(cur == *root)
    {
        if(cur->left)
            *root = cur->left;
        
        else if(cur->right)
            *root = cur->right;
    }
    
    else if(cur->right)
    {
        if((*par)->left == cur)
            (*par)->left = cur->right;
        
        else
            (*par)->right = cur->right;
    }
    
    else if (cur->left)
    {
        if((*par)->left == cur)
            (*par)->left = cur->left;
        
        else
            (*par)->right = cur->left;
    }
    free(cur);
}

static void deleteFullNode (n *cur, n **par, n **root)
{
    n*ssr = cur->right;
    n*par_ssr = NULL;
    
    while(ssr->left)
    {
        par_ssr = ssr;
        ssr = ssr->left;
    }
    
    if(par_ssr)
        par_ssr->left = ssr->right;
    
    ssr->left = cur->left;
    
    if(ssr != cur->right)
        ssr->right = cur->right;
    
    if(cur == *root)
        *root = ssr;
    
    else if((*par)->left == cur)
        (*par)->left = ssr;
    
    else if((*par)->right == cur)
        (*par)->right = ssr;
    
    free(cur);
}

int deleteKey (n** root, int key)
{
    n*cur = *root;
    n*par = NULL;
    
    locateKey (&cur, key, &par);
    
    if(!cur)
        return 0;
    
    int IsThereNoChild = !cur->left && !cur->right;
    int IsThereOneChild = (cur->left && !cur->right) || (cur->right && !cur->left);
    int AreThereTwoChildren = cur->left && cur->right;
    
    if(IsThereNoChild)
        deleteLeafNode (cur, &par, root);
    
    else if(IsThereOneChild)
        deleteHalfNode (cur, &par, root);
    
    else if(AreThereTwoChildren)
        deleteFullNode (cur, &par, root);
    
    return 1;
}

void deleteTree(n** root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, *root);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u->left)
            EnQueue(&q, u->left);
        
        if(u->right)
            EnQueue(&q, u->right);
        
        free(u);
    }
    *root = NULL;
}

int search (n* root, int key)
{
    n*cur = root;
    
    while(cur && cur->data != key)
    {
        if(key > cur->data)
            cur = cur->right;
        
        else if(key < cur->data)
            cur = cur->left;
    }
    
    if(cur)
        return 1;
    
    else
        return 0;
}

int max(n* root)
{
   while(root->right)
       root = root->right;
    
    return root->data;
}

int min(n* root)
{
   while(root->left)
       root = root->left;
    
    return root->data;
}

void _verticalOrder (n* root, int* max, int* min, int hd)
{
    if(!root)
        return;
    
    if(*max < hd)
        *max = hd;
    
    if(*min > hd)
        *min = hd;
    
    _verticalOrder(root->left, max, min, hd-1);
    _verticalOrder(root->right, max, min, hd+1);
    
}

void printVertical (n*root, int i, int hd)         //This function prints all the nodes at horizontal distance 'i'.
{
    if(!root)
        return;
    
    if(i == hd)
        printf("%d\n",root->data);
    
    printVertical(root->left, i, hd-1);
    printVertical(root->right, i, hd+1);
}

void verticalOrder (n* root)
{
    int max = INT_MIN;
    int min = INT_MAX;
    _verticalOrder(root, &max, &min, 0);
    
    for(int i = min; i <= max; i++)
        printVertical(root,i, 0);
}

void zigzag(n* root)
{
    sq q;
    ss s;
    int flag = 1;
    initQueue(&q);
    initStack(&s);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
                
            if(flag)
                printf("%d\n",u->data);
            
            else
                push(&s, u);
        }
        
        else
        {
            flag = !flag;
            
            while(!isStackEmpty(&s))
                printf("%d\n",pop(&s)->data);
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
}

void mirror(n* root)
{
    if(!root)
        return;
    
    mirror(root->left);
    mirror(root->right);
    
    n*temp = root->left;
    root->left = root-> right;
    root->right = temp;
}

int sumOfAllNodes(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    int sum = 0;
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u->left)
            EnQueue(&q, u->left);
        
        if(u->right)
            EnQueue(&q, u->right);
        
        sum += u->data;
    }
    return sum;
}

void morrisTraversal(n* root)
{
    n*cur = root;
    n* predssr;
    
    while(cur)
    {
        if(!cur->left)
        {
            printf("%d\n",cur->data);
            cur = cur->right;
        }
        
        else
        {
            predssr = cur->left;
            
            while(predssr->right && predssr->right != cur)
                predssr = predssr->right;                       //Finding the in-order predecessor
            
            if(!predssr->right)
            {
                predssr->right = cur;           //Create thread
                cur = cur->left;
            }
            
            else
            {
                predssr->right = NULL;          //Revoke thread
                printf("%d\n",cur->data);
                cur = cur->right;
            }
        }
    }
}

void inputArray(int *a, int N)
{
    for(int i = 0; i < N; i++)
        scanf("%d",a+i);
}

void outputArray(int *a, int N)
{
    int i = 0;
    
    while(i < N)
        printf("%d\n",*(a + (i++)));
}

int getIndex(int e, int* in, int N)
{
    for(int i = 0; i < N; i++)
    {
        if(*(in + i) == e)
            return i;
    }
    return 0;
}

n* _constructTree(int* in, int* pre, int L, int R, int* i)
{
    if(L > R)
        return NULL;
    
    n*temp = getNode(*(pre + *i));
    int index = getIndex(*(pre + *i), in, R+1);
    (*i)++;
    temp->left = _constructTree(in, pre, L, index-1, i);
    temp->right = _constructTree(in, pre, index+1, R, i);
    return temp;
    
}

n* constructTree(int *in, int* pre, int N)
{
    int i = 0;
    n*tempRoot = _constructTree(in, pre, 0, N-1, &i);
    return tempRoot;
}

int identicalTree(n* r1, n*r2)
{
    int L = 0, R = 0;
    
    if(!r1 && !r2)
        return 1;
    
    if((!r1 && r2) || (r1 && !r2) || r1->data != r2->data)
        return 0;
    
    L = identicalTree(r1->left, r2->left);
    
    if(L)
        R = identicalTree(r1->right, r2->right);
    
    return L && R;
}

void top_view(n* root)
{
    vq q;
    view_initQueue(&q);
    nl* head = NULL;
    hd e, aux;
    e.nodeData = root;
    e.hd = 0;
    view_EnQueue(&q, e);
    
    while(!view_isQueueEmpty(&q))
    {
        e = view_DeQueue(&q);
        
        if(!list_search(head, e.hd))
        {
            printf("%d\n",e.nodeData->data);
            addFront(&head, e);
        }
        
        if(e.nodeData->left)
        {
            aux.nodeData = e.nodeData->left;
            aux.hd = e.hd - 1;
            view_EnQueue(&q, aux);
        }
        
        if(e.nodeData->right)
        {
            aux.nodeData = e.nodeData->right;
            aux.hd = e.hd + 1;
            view_EnQueue(&q, aux);
        }
    }
}

void bottom_view(n* root)
{
    nl* head = NULL;
    vq q;
    hd e, aux;
    e.nodeData = root;
    e.hd = 0;
    view_initQueue(&q);
    view_EnQueue(&q, e);
    
    while(!view_isQueueEmpty(&q))
    {
        e = view_DeQueue(&q);
        
        if(e.nodeData->left)
        {
            aux.nodeData = e.nodeData->left;
            aux.hd = e.hd - 1;
            view_EnQueue(&q, aux);
        }
        
        if(e.nodeData->right)
        {
            aux.nodeData = e.nodeData->right;
            aux.hd = e.hd + 1;
            view_EnQueue(&q, aux);
        }
        
        if(!list_search(head,e.hd))
            addFront(&head, e);
        
        else
            replaceInList(&head, e);
    }
    
    displaySLL(head);
}

void leftSide_view(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
            
            if(u == root)
                printf("%d\n",root->data);
        }
        
        else
        {
            if(!isQueueEmpty(&q))
            {
                EnQueue(&q, NULL);
                printf("%d\n",getFront(&q)->data);
            }
        }
    }
}

void RightSide_view(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
            
            if(!getFront(&q))
            printf("%d\n",u->data);
        }
        
        else
        {
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
}


void _pathsFromRootToLeaf(n* root, int* a, int i)
{
    if(!root)
        return;
    
    *(a + i++) = root->data;
    
    if(!root->left && !root->right)
    {
        outputArray(a, i);
        return;
    }
    
    _pathsFromRootToLeaf(root->left, a, i);
    _pathsFromRootToLeaf(root->right, a, i);
}

void pathsFromRootToLeaf(n* root)
{
    int a[100];
    _pathsFromRootToLeaf(root, a, 0);
}

void _getKthPathFromRootToLeaf(n* root, int* a, int i, int* aux)
{
    if(!root)
        return;
    
    *(a + i++) = root->data;
    
    if(!root->left && !root->right)
    {
        (*aux)--;
        
        if(*aux == 0)
            outputArray(a, i);
        
        return;
    }
    
    if(*aux != 0)
    {
        _getKthPathFromRootToLeaf(root->left, a, i, aux);
        _getKthPathFromRootToLeaf(root->right, a, i, aux);
    }
}

void getKthPathFromRootToLeaf(n* root, int k)
{
    int a[100];
    int* aux = &k;
    _getKthPathFromRootToLeaf(root, a, 0, aux);
}

int LCA(n* root, int x, int y)
{
    n*cur = root;
    
    while(cur)
    {
        if (x == cur->data || y == cur->data)
            return cur->data;
        
        else if((x > cur->data && y < cur->data) || (x < cur->data && y > cur->data))
            return cur->data;
        
        else if(x > cur->data && y > cur->data)
            cur = cur->right;
        
        else if(x < cur->data && y < cur->data)
            cur = cur->left;
    }
    
    return 0;
}

n* _arrayToBST(int* a, int L, int U)
{
    if(L > U)
        return NULL;
    
    int mid = (L + U) / 2;
    n* tempRoot = getNode(*(a + mid));
    tempRoot->left = _arrayToBST(a, L, mid-1);
    tempRoot->right = _arrayToBST(a, mid+1, U);
    return tempRoot;
}

n* arrayToBST(int* a, int N)
{
    n* tempRoot = _arrayToBST(a, 0, N-1);
    return tempRoot;
}

void diagonalOfTree(n* root)
{
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            while(u)
            {
                if(u->left)
                    EnQueue(&q, u->left);
            
                printf("%d\n",u->data);
                u = u->right;
            }
        }
        
        else
        {
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
            
    }
}

void sumOfDiagonals(n* root)
{
    int sum = 0, i = 1;
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            while(u)
            {
                if(u->left)
                    EnQueue(&q, u->left);
                
                sum += u->data;
                u = u->right;
            }
        }
        
        else
        {
            printf("Diagonal %d's sum = %d\n", i++, sum);
            sum = 0;
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
}


int _tilt(n* root, int* sum)
{
    if(!root)
        return 0;
    
    int L = _tilt(root->left, sum);
    int R = _tilt(root->right, sum);
    
    *sum += abs(L - R);
    return L + R + root->data;
}

int tilt(n* root)
{
    int sum = 0;
    _tilt(root, &sum);
    return sum;
}

int getAncestor(n* root, int e)
{
    int L = 0, R = 0;
    if(!root)
        return 0;
    
    if(root->data == e)
    {
        printf("%d\n", root->data);
        return 1;
    }
    
    L = getAncestor(root->left, e);
    
    if(L == 0)
         R = getAncestor(root->right, e);
    
    if ( L == 1 || R == 1)
    {
        printf("%d\n",root->data);
        return 1;
    }
    return 0;
}

void BST_getAncestor(n* root, int e)
{
    n*cur = root;
    if(search(root, e))
    {
        while(cur && cur->data != e)
        {
            printf("%d\n", cur->data);
        
            if(e < cur->data)
                cur = cur->left;
        
            else if(e > cur->data)
                cur = cur->right;
        }
    
        printf("%d\n", cur->data);
    }
    
    else
        printf("ERROR - Data not found\n");
}

int getMaxFromArray(int* max, int size)
{
    int t = *max;
    int index = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(t < *(max + i))
        {
            t = *(max + i);
            index = i;
        }
    }
    return index + 1;
}

int getLevelWithMaxNodes(n* root)
{
    int* max = (int*) calloc(countLevels(root), sizeof(int));
    memset(max, 0, countLevels(root) * sizeof(int));
    int i = 0;
    sq q;
    initQueue(&q);
    EnQueue(&q, root);
    EnQueue(&q, NULL);
    
    while(!isQueueEmpty(&q))
    {
        n*u = DeQueue(&q);
        
        if(u)
        {
            (*(max + i))++;
            
            if(u->left)
                EnQueue(&q, u->left);
            
            if(u->right)
                EnQueue(&q, u->right);
        }
        
        else
        {
            i++;
            
            if(!isQueueEmpty(&q))
                EnQueue(&q, NULL);
        }
    }
    
    return getMaxFromArray(max, countLevels(root));
}

void _convertToDLL(n* root, n** head, n** prev)
{
    if(!root)
        return;
    
    _convertToDLL(root->left, head, prev);
    
    if(! *prev)
        *head = root;
    
    else
    {
        root->left = *prev;
        (*prev)->right = root;
    }
    
    *prev = root;
    _convertToDLL(root->right, head, prev);
}

void convertToDLL(n* root, n** head)
{
    n* prev = NULL;
    _convertToDLL(root, head, &prev);
}

int isMinHeap(int* a, int size)
{
    int L, R;
    
    for(int i = 0; i < (size / 2); i++)
    {
        L = 2 * i + 1;
        R = 2 * i + 2;
        
        if(*(a + i) > *(a + L))
            return 0;
        
        if((*(a + i) > *(a + R)) && R < size)
            return 0;
    }
    return 1;
}

int main()
{
    n* root, *head;
    int e,ch,key,N,x,y;
    int pre[100], in[100];
    initTree(&root);
    while(1)
    {
        printf("Enter choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
                printf("Add BST\n");
                printf("Enter data:");
                scanf("%d",&e);
                addBST(&root,e);
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
                printf("Display mode: Level-order\n");
                levelOrder(root);
                break;
            case 6:
                printf("Display mode: Iterative Pre-order\n");
                itr_preOrder(root);
                break;
            case 7:
                printf("Display mode: Iterative In-order\n");
                itr_inOrder(root);
                break;
            case 8:
                printf("Display mode: Iterative Post-order\n");
                itr_postOrder(root);
                break;
            case 9:
                printf("Height of Tree = %d\n",height(root));
                break;
            case 10:
                printf("Diameter of Tree = %d\n",diameter(root));
                break;
            case 11:
                printf("Printing sum of each level:\n");
                sumOfEachLevel(root);
                break;
            case 12:
                printf("Total number of nodes = %d\n",countNodes(root));
                break;
            case 13:
                printf("Total number of leaf nodes = %d\n",rec_countLeafNodes(root));
                break;
            case 14:
                printf("Total number of half nodes = %d\n",countHalfNodes(root));
                break;
            case 15:
                printf("Total number of levels = %d\n",countLevels(root));
                break;
            case 16:
                printf("Level with the highest sum and its index\n");
                highestSumOfLevels(root);
                break;
            case 17:
                printf("Enter key to be deleted:");
                scanf("%d",&key);
                
                if(deleteKey(&root,key))
                    printf("Key successfully deleted\n");
                
                else
                    printf("ERROR - Key could not be deleted\n");
                
                break;
            case 18:
                printf("Tree has been deleted\n");
                deleteTree(&root);
                break;
            case 19:
                printf("Enter element to be searched:");
                scanf("%d",&key);
                
                if(search(root,key))
                    printf("Element found\n");
                
                else
                    printf("ERROR - Element not found\n");
                
                break;
            case 20:
                printf("The max element is = %d\n",max(root));
                printf("The min element is = %d\n",min(root));
                break;
            case 21:
                printf("Display mode: Vertical order\n");
                verticalOrder(root);
                break;
            case 22:
                printf("Display mode Zigzag\n");
                zigzag(root);
                break;
            case 23:
                printf("Tree has been mirrored\n");
                mirror(root);
                break;
            case 24:
                printf("The sum of all nodes = %d\n",sumOfAllNodes(root));
                break;
            case 25:
                printf("Display mode: Morris Traversal\n");
                morrisTraversal(root);
                break;
            case 26:
                printf("Constructing tree using pre-order and in-order values\n");
                printf("Enter number of elements\n");
                scanf("%d",&N);
                printf("Enter elements for in-order array\n");
                inputArray(in, N);
                printf("Enter elements for pre-order array\n");
                inputArray(pre, N);
                n* tempRoot = constructTree(in, pre, N);
                printf("Display mode: Level-order\n");
                levelOrder(tempRoot);
                printf("Display mode: Post-order\n");
                postOrder(tempRoot);
                deleteTree(&tempRoot);
                break;
            case 27:
                printf("Display mode: Top view\n");
                top_view(root);
                break;
            case 28:
                printf("Display mode: Bottom view\n");
                bottom_view(root);
                break;
            case 29:
                printf("Display mode: Left-side view\n");
                leftSide_view(root);
                break;
            case 30:
                printf("Display modeL Right-side view\n");
                RightSide_view(root);
                break;
            case 31:
                printf("Displaying  paths from root node to all leaf nodes\n");
                pathsFromRootToLeaf(root);
                break;
            case 32:
                printf("Enter the number of path to be obtained from root to node\n");
                scanf("%d",&N);
                getKthPathFromRootToLeaf(root, N);
                break;
            case 33:
                printf("Least Common Ancestor\n");
                printf("Node 1 = ");
                scanf("%d",&x);
                printf("Node 2 = ");
                scanf("%d",&y);
                printf("The LCA is %d\n", LCA(root, x, y));
                break;
            case 34:
                printf("Convert sorted array to BST\n");
                printf("Enter size of array\n");
                scanf("%d",&N);
                inputArray(in, N);
                tempRoot = arrayToBST(in, N);
                inOrder(root);
                deleteTree(&tempRoot);
                break;
            case 35:
                printf("Display mode: Diagonal of Tree\n");
                diagonalOfTree(root);
                break;
             case 36:
                printf("Sum of diagonals of tree\n");
                sumOfDiagonals(root);
                break;
            case 37:
                printf("Tilt of tree = %d\n",tilt(root));
                break;
            case 38:
                printf("Ancestor of a node\n");
                printf("Enter node data:");
                scanf("%d",&e);
                BST_getAncestor(root, e);
                break;
            case 39:
                printf("Level number of level with highest number of nodes = %d\n",getLevelWithMaxNodes(root));
                break;
            case 40:
                printf("Converting Tree to DLL\n");
                initTree(&head);
                convertToDLL(root, &head);
                displayDLL(head);
                initTree(&root);
                break;
            case 41:
                printf("Check if given level-order input of a tree is a min-heap\n");
                printf("Enter size of array\n");
                scanf("%d", &N);
                printf("Enter array elements\n");
                inputArray(in, N);
                
                if (isMinHeap(in, N))
                    printf("Given tree is a min heap\n");
                
                else
                    printf("Given tree is not a min heap\n");
                break;
        }
    }
}
