#include <stdio.h>
#include <stdlib.h>
#define RANGE 7

/* LINEAR DATA STRUCTURE */
// function for insertion in array
void insertion_arr(int *arr, int *n)
{
    // Input the position and number to insert
    int pos, num;
    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos);
    printf("Enter the number to insert: ");
    scanf("%d", &num);

    // Check if position is valid
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right to make space for the new number
    for (int i = *n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert the number at the specified position
    arr[pos] = num;

    // Increment the size of the array
    (*n)++;
}

// function for deletion in array
void deletion_arr(int *arr, int *n)
{
    // Input the position and number to insert
    int pos, num;
    printf("Enter the position where you want to delete element : ");
    scanf("%d", &pos);

    // Check if position is valid
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    else
    {
        for (int i = pos; i < *n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        // Reduce the size of the array
        (*n)--;
    }
}

// function for copy array
void copy_arr(int *arr, int *brr, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        brr[i] = arr[i];
    }
}

// function for reverse array
void reverse_arr(int *arr, int *n)
{
    printf("** Reversed Array **: ");
    for (int i = *n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// structure of a linked list
struct node
{
    int data;
    struct node *next;
};

// traversal of linked list
void traversal(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// insertion of node
struct node *insertion_LL(struct node *head, int choice_insertion, int value)
{
    // new node to insert
    struct node *bt = (struct node *)malloc(sizeof(struct node));

    // insertion at beginning
    if (choice_insertion == 1)
    {
        bt->data = value;
        bt->next = head;
        return bt; // return new node as head
    }

    // insertion in between
    else if (choice_insertion == 2)
    {
        int index;
        printf("Enter the index where you want to insert data : ");
        scanf("%d", &index);

        if (index < 0)
        {
            printf("Invalid index\n");
            return head;
        }

        struct node *p = head;
        struct node *q = head->next;

        int i = 0;

        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }

        bt->data = value;
        p->next = bt;
        bt->next = q;

        return head;
    }

    // insertion at end
    else if (choice_insertion == 3)
    {
        struct node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        bt->data = value;
        bt->next = NULL;
        temp->next = bt;

        return head;
    }

    else
    {
        printf("Invalid choice !");
    }
}

// deletion of node
struct node *deletion_LL(struct node *head, int choice_deletion)
{
    // at beginning
    if (choice_deletion == 1)
    {
        head = head->next;
        return head;
    }

    // in between
    else if (choice_deletion == 2)
    {
        int index;
        printf("Enter the index which you want to delete : ");
        scanf("%d", &index);

        struct node *p = head;
        struct node *q = head->next;

        int i = 0;

        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }

        p->next = q->next;
        free(q);
        return head;
    }

    // in end
    else if (choice_deletion == 3)
    {
        struct node *p = head;
        struct node *q = head->next;

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        p->next = NULL;
        free(q);

        return head;
    }

    else
    {
        printf("Invalid choice!");
    }
}

// count no of nodes
int count_LL(struct node *head)
{
    struct node *bt = head;

    int c = 0;

    while (bt != NULL)
    {
        bt = bt->next;
        c++;
    }

    return c;
}

// struct of stack (array)
struct stack
{
    int size;
    int top;
    int *stack_arr;
};

// function to display AtoS
void display_AtoS(struct stack *s)
{
    printf("Elements in stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->stack_arr[i]);
    }
    printf("\n");
}

// function to create AtoS
struct stack *create_stack(int capacity)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    if (s == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    s->top = -1;
    s->size = capacity;
    s->stack_arr = (int *)malloc(s->size * sizeof(int));
    if (s->stack_arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return s;
}

// function to check if stack is empty in AtoS
int isEmpty_AtoS(struct stack *ptr)
{
    return (ptr->top == -1);
}

// function to check if stack is full in AtoS
int isFull_AtoS(struct stack *ptr)
{
    return (ptr->top == RANGE - 1);
}

// function to push value in AtoS
void push_AtoS(struct stack *ptr, int value)
{
    ptr->top++;
    ptr->stack_arr[ptr->top] = value;

    printf("Pushed %d in stack \n", value);
}

// function to pop value in AtoS
int pop_AtoS(struct stack *ptr)
{
    int pop_value = ptr->stack_arr[ptr->top];
    ptr->top--;
    return pop_value;
}

// function for peek in AtoS
void peek_AtoS(struct stack *ptr, int index)
{
    if (index <= ptr->size - 1)
    {
        printf("Value at index %d is %d \n", index, ptr->stack_arr[index]);
    }
    else
    {
        printf("Incorrect Index \n");
    }
}

// function to create LLtoS
struct node_LLtoS
{
    int data;
    struct node_LLtoS *next;
};

// function for traversal of LL in LLtoS
void traversal_LLtoS(struct node_LLtoS *TOP)
{
    struct node_LLtoS *ptr = TOP;

    printf("Stack elements : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// function to check if stack is empty in LLtoS
int isEmpty_LLtoS(struct node_LLtoS *TOP)
{

    return (TOP == NULL);
}

// function to check if stack is full in LLtoS
int isFull_LLtoS(struct node_LLtoS *TOP)
{
    struct node_LLtoS *n = (struct node_LLtoS *)malloc(sizeof(struct node_LLtoS));
    return (n == NULL);
}

// function for push in LLtoS
struct node_LLtoS *push_LLtoS(struct node_LLtoS *TOP, int value)
{
    struct node_LLtoS *new = (struct node_LLtoS *)malloc(sizeof(struct node_LLtoS));

    new->data = value;
    new->next = TOP;
    TOP = new;

    return TOP;
}

// function for pop in LLtoS
int pop_LLtoS(struct node_LLtoS **TOP)
{
    struct node_LLtoS *temp = *TOP;

    *TOP = temp->next;
    int p = temp->data;
    free(temp);

    return p;
}

// Function to peek at the top element of the stack
int peek(struct node_LLtoS *TOP)
{
    return TOP->data;
}

// structure of array to queue
struct queue
{
    int size;
    int front;
    int rear;
    int *queue_arr;
};

// create AtoQ
struct queue *create_queue(int capacity)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));

    q->size = capacity;
    q->front = q->rear = -1;
    q->queue_arr = (int *)malloc(q->size * sizeof(int));

    return q;
}

// isEmpty AtoQ
int isEmpty_AtoQ(struct queue *q)
{
    return (q->rear == -1 && q->front == -1);
}

// isFull AtoQ
int isFull_AtoQ(struct queue *q)
{
    return (q->rear == RANGE - 1);
}

// enqueue AtoQ
void enqueue_AtoQ(struct queue *q, int value)
{
    // If the queue is empty, set front and rear to 0
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }

    // Otherwise, increment the rear pointer
    else
    {
        q->rear++;
    }

    printf("Enqueueing %d in queue \n", value);
    q->queue_arr[q->rear] = value;
}

// dequeue AtoQ
void dequeue_AtoQ(struct queue *q)
{
    if (q->front == q->rear)
    {
        printf("Dequeue %d\n", q->queue_arr[q->front]);
        q->front = q->rear = -1; // Reset front and rear pointers
    }

    else
    {
        printf("Dequeue %d\n", q->queue_arr[q->front]);
        q->front++;
    }
}

// display AtoQ
void display_AtoQ(struct queue *q)
{
    if (isEmpty_AtoQ(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->queue_arr[i]);
    }
    printf("\n");
}

// LLtoQ
struct LLtoQ_node
{
    int data;
    struct LLtoQ_node *next;
};

struct LLtoQ_node *front = NULL;
struct LLtoQ_node *rear = NULL;

// isFull LLtoQ
int isFull_LLtoQ()
{
    struct LLtoQ_node *x = (struct LLtoQ_node *)malloc(sizeof(struct LLtoQ_node));
    return (x == NULL);
}

// isEmpty LLtoQ
int isEmpty_LLtoQ()
{
    return (front == NULL);
}

// enqueue LLtoQ
void LLtoQ_enqueue()
{
    struct LLtoQ_node *new = (struct LLtoQ_node *)malloc(sizeof(struct LLtoQ_node));

    int value;
    printf("Enter the value to enqueue : ");
    scanf("%d", &value);

    if (front == NULL && rear == NULL)
    {
        printf("%d is enqueued \n", value);
        new->data = value;
        front = new;
        rear = new;
    }

    else
    {
        printf("%d is enqueued \n", value);
        new->data = value;
        new->next = NULL;
        rear->next = new;
        rear = new;
    }
}

// dequeue LLtoQ
void LLtoQ_dequeue()
{
    struct LLtoQ_node *temp = front;

    printf("%d is dequeued \n", temp->data);
    front = temp->next;
    free(temp);
}

// displat LLtoQ
void LLtoQ_display()
{
    struct LLtoQ_node *temp = front;

    if (front == NULL && rear == NULL)
        printf("Queue Underflow \n");

    printf("Queue is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* NON-LINEAR DATA STRUCTURE */

// Structure for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode *insertNode(struct TreeNode *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

// Pre-order traversal function
void preOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal function
void inOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Post-order traversal function
void postOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// linear search function
int linearsearch(int size, int LS_element, int LS_arr[])
{
    for (int i = 0; i < size; i++)
    {
        if (LS_arr[i] == LS_element)
        {
            printf("Element found at index : %d \n", i);
            return 1;
        }
    }
    printf("Element not found in array\n");
    return 0;
}

// binary search function
int binarysearch(int BS_element, int no_of_elem_BS, int BS_arr[])
{
    int low, high, mid;
    low = 0;
    high = no_of_elem_BS - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2; // Calculate mid inside the loop

        if (BS_arr[mid] == BS_element)
            return mid;

        if (BS_element < BS_arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// sorting algos

// print array
void print_sort_Array(int sort_arr[], int n_sort_algo)
{
    for (int i = 0; i < n_sort_algo; i++)
    {
        printf("%d ", sort_arr[i]);
    }
    printf("\n");
}

// selection sort function
void selectionSort(int sort_algo_arr[], int n_sort_algo)
{
    int i, j, min_idx;
    for (i = 0; i < n_sort_algo - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n_sort_algo; j++)
        {
            if (sort_algo_arr[j] < sort_algo_arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = sort_algo_arr[min_idx];
        sort_algo_arr[min_idx] = sort_algo_arr[i];
        sort_algo_arr[i] = temp;
    }
}

// bubble sort function
void bubbleSort(int sort_algo_arr[], int n_sort_algo)
{
    int i, j;
    for (i = 0; i < n_sort_algo - 1; i++)
    {
        for (j = 0; j < n_sort_algo - i - 1; j++)
        {
            if (sort_algo_arr[j] > sort_algo_arr[j + 1])
            {
                int temp = sort_algo_arr[j];
                sort_algo_arr[j] = sort_algo_arr[j + 1];
                sort_algo_arr[j + 1] = temp;
            }
        }
    }
}

// Insertion sort function
void insertionSort(int sort_algo_arr[], int n_sort_algo)
{
    int i, key, j;
    for (i = 1; i < n_sort_algo; i++)
    {
        key = sort_algo_arr[i];
        j = i - 1;

        while (j >= 0 && sort_algo_arr[j] > key)
        {
            sort_algo_arr[j + 1] = sort_algo_arr[j];
            j = j - 1;
        }
        sort_algo_arr[j + 1] = key;
    }
}

// quick sort function
int partition(int sort_algo_arr[], int low, int high)
{
    int pivot = sort_algo_arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (sort_algo_arr[j] < pivot)
        {
            i++;
            int temp = sort_algo_arr[i];
            sort_algo_arr[i] = sort_algo_arr[j];
            sort_algo_arr[j] = temp;
        }
    }
    int temp = sort_algo_arr[i + 1];
    sort_algo_arr[i + 1] = sort_algo_arr[high];
    sort_algo_arr[high] = temp;
    return (i + 1);
}
void quickSort(int sort_algo_arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(sort_algo_arr, low, high);

        quickSort(sort_algo_arr, low, pi - 1);
        quickSort(sort_algo_arr, pi + 1, high);
    }
}

int main()
{
    int first_choice, lds_choice, nlds_choice;

    while (1)
    {
        // greetings
        printf("*** WELCOME *** \n");

        printf("1) Linear Data Structure \n 2) Non-Linear Data Structure \n 3) Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &first_choice);

        // first switch case
        switch (first_choice)
        {
        // linear data structure
        case 1:
            do
            {
                printf("1) Array \n 2) Linked List \n 3) Stack \n 4) Queue \n 5) Exit to main menu \n");
                printf("Enter your choice : ");
                scanf("%d", &lds_choice);

                // second switch case
                switch (lds_choice)
                {
                    // array variables
                    int n, arr_choice;
                    int *arr, *brr;

                    // LL variables
                    int LL_choice, choice_insertion, choice_deletion, data, result_count;

                    // stack variables
                    // arr
                    int stack_choice, AtoS_n, AtoSchoice, AtoS_push_times, AtoS_push_value, AtoS_pop_times, poped_value_AtoS, peek_index_Atos;
                    int stack_arr[RANGE];
                    // LL
                    int LLtoS_choice, LLtoS_push_time, LLtoS_push_value, LLtoS_pop_time, poped_value_LLtoS, peek_value_LLtoS;
                    struct node_LLtoS *TOP = NULL;

                    // queue variables
                    // arr
                    int queue_choice, n_AtoQ, AtoQ_choice, AtoQ_push_times, AtoQ_push_value, AtoQ_pop_times;
                    int queue_arr[RANGE];
                    // LL
                    int LLtoQ_choice, enq_times, dq_times;

                // array
                case 1:
                    do
                    {
                        printf("Enter the size of array (MAX 7) : ");
                        scanf("%d", &n);

                        arr = (int *)malloc(RANGE * sizeof(int));
                    } while (n > 7);

                    // input array
                    printf("Enter array elements \n");
                    for (int i = 0; i < n; i++)
                    {
                        scanf("%d", &arr[i]);
                    }

                    // print array elements
                    printf("Array elements are : ");
                    for (int i = 0; i < n; i++)
                    {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");

                    // array operations
                    do
                    {
                        printf("1) Insertion \n 2) Deletion \n 3) Copy array elements\n 4) Reverse the array elements\n 5) Exit to previous menu \n");
                        printf("Enter your choice : ");
                        scanf("%d", &arr_choice);

                        switch (arr_choice)
                        {
                        // insertion array
                        case 1:
                            // function call
                            insertion_arr(arr, &n);

                            // Print the updated array
                            printf("Array after insertion : ");
                            for (int i = 0; i < n; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        // deletion array
                        case 2:
                            // function call
                            deletion_arr(arr, &n);

                            // Print the updated array
                            printf("Array after deletion : ");
                            for (int i = 0; i < n; i++)
                            {
                                printf("%d ", arr[i]);
                            }
                            printf("\n");
                            break;

                        // copy array
                        case 3:
                            brr = (int *)malloc(RANGE * sizeof(int));

                            // function call
                            copy_arr(arr, brr, &n);

                            // print the updated array
                            printf("** Copied array from arr to brr **: ");
                            for (int i = 0; i < n; i++)
                            {
                                printf("%d ", brr[i]);
                            }
                            printf("\n");

                            free(brr);
                            break;

                        // reverse array
                        case 4:
                            // function call
                            reverse_arr(arr, &n);
                            break;

                        // exit to pm
                        case 5:
                            break;

                        default:
                            printf("Wrong choice \n try again ! \n");
                            break;
                        }
                    } while (arr_choice != 5);

                    break;

                // linked list
                case 2:
                    printf("Enter the number of elements in the linked list: ");
                    int num_elements;
                    scanf("%d", &num_elements);

                    // Initialize the head of the linked list
                    struct node *head = NULL;

                    // Take input for the linked list elements
                    for (int i = 0; i < num_elements; i++)
                    {
                        int data;
                        printf("Enter element %d: ", i + 1);
                        scanf("%d", &data);

                        if (head == NULL)
                        {
                            head = insertion_LL(head, 1, data); // Insert at beginning if list is empty
                        }
                        else
                        {
                            head = insertion_LL(head, 3, data); // Insert at end otherwise
                        }
                    }

                    do
                    {
                        printf("1) Insertion of node \n 2) Deletion of node \n 3) Count number of nodes \n 4) Exit to previous menu \n");
                        printf("Enter your choice here : ");
                        scanf("%d", &LL_choice);

                        switch (LL_choice)
                        {
                            // LL insertion operations
                        case 1:
                            printf("1) Insertion at the beginning \n 2) Insertion in between \n 3) Insertion at the end \n");
                            printf("Enter your choice here : ");
                            scanf("%d", &choice_insertion);

                            printf("Enter the value you want to insert : ");
                            scanf("%d", &data);

                            // calling insertion function
                            head = insertion_LL(head, choice_insertion, data);

                            // displaying new LL after insertion
                            traversal(head);
                            printf("\n");
                            break;

                        // LL deletion operations
                        case 2:
                            printf("1) Deletion at the beginning \n 2) Deletion in between \n 3) Deletion at the end \n");
                            printf("Enter your choice here : ");
                            scanf("%d", &choice_deletion);

                            // calling deletion function
                            head = deletion_LL(head, choice_deletion);

                            // displaying new LL after insertion
                            traversal(head);
                            printf("\n");
                            break;

                        // count LL
                        case 3:

                            // calling count function
                            result_count = count_LL(head);

                            printf("No. of nodes are %d \n", result_count);
                            break;

                        // exit to pm
                        case 4:
                            break;

                        default:
                            printf("Invalid choice \n try again! \n");
                            break;
                        }
                    } while (LL_choice != 4);
                    break;

                // stack
                case 3:
                    do
                    {
                        printf("How do you want to implement stack ? \n");
                        printf("1) Using Arrays \n 2) Using Linked List \n 3) Exit to previous menu \n");
                        printf("Enter your choice here : ");
                        scanf("%d", &stack_choice);

                        switch (stack_choice)
                        {
                        // stack using array
                        case 1:
                            do
                            {
                                printf("Enter the size of the array [MAX 7] : ");
                                scanf("%d", &AtoS_n);
                            } while (AtoS_n > 7);

                            printf("Enter the elements of the array : \n");
                            for (int i = 0; i < AtoS_n; i++)
                            {
                                scanf("%d", &stack_arr[i]);
                            }

                            struct stack *s = create_stack(AtoS_n);

                            printf("Converting array to stack...\n");

                            for (int i = 0; i < AtoS_n; i++)
                            {
                                push_AtoS(s, stack_arr[i]);
                            }

                            display_AtoS(s);

                            // array to stack operations
                            do
                            {
                                printf("1) Push \n 2)Pop \n 3) Peek \n 4) isEmpty \n 5) isFull \n 6) Exit to previous menu \n");
                                printf("Enter your choice :");
                                scanf("%d", &AtoSchoice);

                                switch (AtoSchoice)
                                {
                                // push in AtoS
                                case 1:
                                    // condition for stack overflow
                                    if (isFull_AtoS(s))
                                    {
                                        printf("Stack Overflow !\n");
                                    }

                                    else
                                    {
                                        printf("Enter the no. of times you want to push : ");
                                        scanf("%d", &AtoS_push_times);

                                        for (int i = 0; i < AtoS_push_times; i++)
                                        {
                                            printf("Enter the element to push :");
                                            scanf("%d", &AtoS_push_value);

                                            // calling push function
                                            push_AtoS(s, AtoS_push_value);
                                        }

                                        // display after push
                                        display_AtoS(s);
                                    }
                                    break;

                                // pop in Atos
                                case 2:
                                    if (isEmpty_AtoS(s))
                                    {
                                        printf("Stack Underflow !\n");
                                    }

                                    else
                                    {
                                        printf("Enter the no. of times you want to pop : ");
                                        scanf("%d", &AtoS_pop_times);

                                        for (int i = 0; i < AtoS_pop_times; i++)
                                        {
                                            // calling pop function
                                            poped_value_AtoS = pop_AtoS(s);
                                            printf("Poped value is %d \n", poped_value_AtoS);
                                        }

                                        // display after pop
                                        display_AtoS(s);
                                    }
                                    break;

                                case 3:
                                    printf("Enter the index : ");
                                    scanf("%d", &peek_index_Atos);

                                    // calling peek function
                                    peek_AtoS(s, peek_index_Atos);
                                    break;

                                // isempty AtoS
                                case 4:
                                    if (isEmpty_AtoS(s))
                                        printf("Stack is empty \n");

                                    else
                                        printf("Stack is not empty \n");

                                    break;

                                // isfull AtoS
                                case 5:
                                    if (isFull_AtoS(s))
                                        printf("Stack is full \n");

                                    else
                                        printf("Stack is not full \n");

                                    break;

                                // exit to pm
                                case 6:
                                    break;

                                default:
                                    printf("Wrong choice ! \n try again \n");
                                    break;
                                }

                            } while (AtoSchoice != 6);

                            free(s->stack_arr);
                            free(s);

                            break;

                        // stack using LL
                        case 2:
                            TOP = NULL;

                            do
                            {
                                printf("1) Push \n 2) Pop \n 3) Peek \n 4) isEmpty \n 5) isFull \n 6) Exit to previous menu \n ");
                                printf("Enter choice : ");
                                scanf("%d", &LLtoS_choice);

                                switch (LLtoS_choice)
                                {
                                // push in LLtoS
                                case 1:
                                    if (isFull_LLtoS(TOP))
                                    {
                                        printf("Stack Overflow \n");
                                    }

                                    else
                                    {
                                        printf("How many times you want to push: ");
                                        scanf("%d", &LLtoS_push_time);

                                        for (int i = 0; i < LLtoS_push_time; i++)
                                        {
                                            printf("Enter the value to push: ");
                                            scanf("%d", &LLtoS_push_value);

                                            TOP = push_LLtoS(TOP, LLtoS_push_value);
                                        }

                                        traversal_LLtoS(TOP);
                                    }
                                    break;

                                // pop in LLtoS
                                case 2:

                                    if (isEmpty_LLtoS(TOP))
                                    {
                                        printf("Stack Underflow ! \n");
                                    }

                                    else
                                    {
                                        printf("How many times you want to pop: ");
                                        scanf("%d", &LLtoS_pop_time);

                                        for (int i = 0; i < LLtoS_pop_time; i++)
                                        {
                                            poped_value_LLtoS = pop_LLtoS(&TOP);
                                            printf("Poped value is %d \n", poped_value_LLtoS);
                                        }

                                        traversal_LLtoS(TOP);
                                    }
                                    break;

                                // peek in LLtoS
                                case 3:
                                    if (TOP == NULL)
                                    {
                                        printf("Stack is empty\n");
                                    }

                                    // Peek at the top element
                                    printf("Top element of the stack: %d\n", peek(TOP));

                                    break;

                                // isEmpty LltoS
                                case 4:
                                    if (isEmpty_LLtoS(TOP))
                                        printf("Stack is empty \n");

                                    else
                                        printf("Stack is not empty \n");

                                    break;

                                // isFull LltoS
                                case 5:
                                    if (isFull_LLtoS(TOP))
                                        printf("Stack is full \n");

                                    else
                                        printf("Stack is not full \n");

                                    break;

                                // exit to pm
                                case 6:
                                    break;

                                default:
                                    printf("Wrong Choice ! Try Again ! \n");
                                    break;
                                }
                            } while (LLtoS_choice != 6);
                            break;
                        // exit to pm
                        case 3:
                            break;

                        default:
                            printf("Wrong choice ! \n try again \n");
                            break;
                        }
                    } while (stack_choice != 3);

                    break;

                // queue
                case 4:
                    do
                    {
                        printf("How do you want to implement queue ? \n");
                        printf("1) Using Arrays \n 2) Using Linked List \n 3) Exit to previous menu \n");
                        printf("Enter your choice here : ");
                        scanf("%d", &queue_choice);

                        switch (queue_choice)
                        {
                        // AtoQ
                        case 1:
                            printf("Enter the size of the array [MAX 7] : ");
                            scanf("%d", &n_AtoQ);

                            printf("Enter array elements : \n");
                            for (int i = 0; i < n_AtoQ; i++)
                            {
                                scanf("%d", &queue_arr[i]);
                            }

                            struct queue *q = create_queue(n_AtoQ);

                            for (int i = 0; i < n_AtoQ; i++)
                            {
                                enqueue_AtoQ(q, queue_arr[i]);
                            }

                            display_AtoQ(q);

                            // array to queue operations
                            do
                            {
                                printf("1) Enqueue \n 2)Dequeue \n 3) isEmpty \n 4) isFull \n 5) Exit to previous menu \n");
                                printf("Enter your choice :");
                                scanf("%d", &AtoQ_choice);

                                switch (AtoQ_choice)
                                {
                                // enqueue AtoQ
                                case 1:
                                    // condition for queue overflow
                                    if (isFull_AtoQ(q))
                                    {
                                        printf("Queue Overflow !\n");
                                    }

                                    else
                                    {
                                        printf("Enter the no. of times you want to enqueue : ");
                                        scanf("%d", &AtoQ_push_times);

                                        for (int i = 0; i < AtoQ_push_times; i++)
                                        {
                                            printf("Enter the element to enqueue :");
                                            scanf("%d", &AtoQ_push_value);

                                            // calling enqueue function
                                            enqueue_AtoQ(q, AtoQ_push_value);
                                        }

                                        // display after enqueue
                                        display_AtoQ(q);
                                    }
                                    break;

                                // dequeue AtoQ
                                case 2:
                                    // condition for queue underflow
                                    if (isEmpty_AtoQ(q))
                                    {
                                        printf("Queue Underflow !\n");
                                    }

                                    else
                                    {
                                        printf("Enter the no. of times you want to dequeue : ");
                                        scanf("%d", &AtoQ_pop_times);

                                        for (int i = 0; i < AtoQ_pop_times; i++)
                                        {
                                            // calling dequeue function
                                            dequeue_AtoQ(q);
                                        }

                                        // display after dequeue
                                        display_AtoQ(q);
                                    }
                                    break;

                                // isEmpty AtoQ
                                case 3:
                                    if (isEmpty_AtoQ(q))
                                        printf("Queue is empty \n");

                                    else
                                        printf("Queue is not empty \n");
                                    break;

                                // isFull AtoQ
                                case 4:
                                    if (isFull_AtoQ(q))
                                        printf("Queue is full \n");

                                    else
                                        printf("Queue is not full \n");
                                    break;

                                case 5:
                                    /* code */
                                    break;

                                default:
                                    printf("Wrong input \n try again \n");
                                    break;
                                }

                            } while (AtoQ_choice != 5);
                            break;

                        // LLtoQ
                        case 2:
                            do
                            {
                                printf("1) Enqueue \n 2) Dequeue \n 3) isFull \n 4) isEmpty \n 5) Exit to previous menu \n");
                                printf("enter your choice : ");
                                scanf("%d", &LLtoQ_choice);

                                switch (LLtoQ_choice)
                                {
                                    // LLtoQ enqueue
                                case 1:
                                    if (isFull_LLtoQ())
                                        printf("Queue Overflow ! \n");
                                    else
                                    {
                                        printf("How many times you want to enqueue : ");
                                        scanf("%d", &enq_times);

                                        for (int i = 0; i < enq_times; i++)
                                        {
                                            LLtoQ_enqueue();
                                        }
                                        LLtoQ_display();
                                    }
                                    break;

                                    // LLtoQ dequeue
                                case 2:
                                    if (isEmpty_LLtoQ())
                                        printf("Queue Underflow \n");

                                    else
                                    {
                                        printf("How many times you want to dequeue : ");
                                        scanf("%d", &dq_times);

                                        for (int i = 0; i < dq_times; i++)
                                        {
                                            LLtoQ_dequeue();
                                        }
                                        LLtoQ_display();
                                    }
                                    break;

                                    // LLtoQ isFull
                                case 3:
                                    if (isFull_LLtoQ())
                                        printf("Queue is full \n");

                                    else
                                        printf("Queue is not full \n");
                                    break;

                                    // LLtoQ isEmpty
                                case 4:
                                    if (isEmpty_LLtoQ())
                                        printf("Queue is empty \n");

                                    else
                                        printf("Queue is not empty \n");
                                    break;

                                // exit to pm
                                case 5:
                                    break;

                                default:
                                    printf("Wrong Choice ! \n Try again \n");

                                    break;
                                }
                            } while (LLtoQ_choice != 5);
                            break;

                        // exit to pm
                        case 3:
                            break;

                        default:
                            printf("Wrong Choice \n Try Again \n");
                            break;
                        }
                    } while (queue_choice != 3);

                // exit to mm
                case 5:
                    break;

                default:
                    printf("Wrong input \n try again \n");
                    break;
                }
            } while (lds_choice != 5);
            break;

            // non-linear data structure
        case 2:
        {
            do
            {
                printf("1) Tree Traversal Algorithm \n 2) Searching Algorithm \n 3) Sorting Algorithm \n 4) Exit to main menu \n");
                printf("Enter your choice: ");
                scanf("%d", &nlds_choice);

                switch (nlds_choice)
                {
                // tree algo
                case 1:
                {
                    int n_tree_algo, data_tree_algo, choice_tree_algo;
                    struct TreeNode *root = NULL;

                    printf("Enter the number of nodes: ");
                    scanf("%d", &n_tree_algo);

                    printf("Enter the node values:\n");
                    for (int i = 0; i < n_tree_algo; i++)
                    {
                        scanf("%d", &data_tree_algo);
                        root = insertNode(root, data_tree_algo);
                    }

                    printf("Tree created successfully.\n");

                    do
                    {
                        printf("1) Pre-Order Traversal\n2) In-Order traversal\n3) Post-Order Traversal\n4) Exit to previous menu\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice_tree_algo);

                        switch (choice_tree_algo)
                        {
                            // pre-order traversal
                        case 1:
                            printf("Pre-order traversal: ");
                            preOrder(root);
                            printf("\n");
                            break;

                            // in-order traversal
                        case 2:
                            printf("In-order traversal: ");
                            inOrder(root);
                            printf("\n");
                            break;

                            // post-order traversal
                        case 3:
                            printf("Post-order traversal: ");
                            postOrder(root);
                            printf("\n");
                            break;

                        // exit to pm
                        case 4:
                            break;

                        default:
                            printf("Wrong input.\n Please try again.\n");
                        }
                    } while (choice_tree_algo != 4);
                    break;
                } // End of case 1 (tree algo)

                // searching algo
                case 2:
                {
                    // LS
                    int choice_search_algo, LS_element, no_of_elem_LS, n_LS;
                    int LS_arr[RANGE];
                    // BS
                    int BS_element, no_of_elem_BS, n_BS, index_BS;
                    int BS_arr[RANGE];

                    do
                    {
                        printf("1) Linear Search \n 2) Binary Search \n 3) Exit to previous menu \n");
                        printf("Enter your choice : ");
                        scanf("%d", &choice_search_algo);

                        switch (choice_search_algo)
                        {
                        // linear search
                        case 1:
                            do
                            {
                                printf("Enter the size of array [MAX 7] : ");
                                scanf("%d", &n_LS);
                            } while (n_LS > 7);

                            printf("Enter the array elements : ");
                            for (int i = 0; i < n_LS; i++)
                            {
                                scanf("%d", &LS_arr[i]);
                            }

                            printf("Which element do you want to find? : ");
                            scanf("%d", &LS_element);

                            // find no of element in array
                            no_of_elem_LS = sizeof(LS_arr) / sizeof(LS_arr[0]);

                            // calling function
                            linearsearch(no_of_elem_LS, LS_element, LS_arr);
                            break;

                            // binary search
                        case 2:
                            do
                            {
                                printf("Enter the size of array [MAX 7] : ");
                                scanf("%d", &n_BS);
                            } while (n_BS > 7);

                            printf("Enter the array elements [sorted !]: ");
                            for (int i = 0; i < n_BS; i++)
                            {
                                scanf("%d", &BS_arr[i]);
                            }

                            printf("Which element do you want to find? : ");
                            scanf("%d", &BS_element);

                            // calling function
                            index_BS = binarysearch(BS_element, n_BS, BS_arr);
                            if (index_BS != -1)
                                printf("Value found at index %d\n", index_BS);
                            else
                                printf("Value not found in the array.\n");
                            break;

                        // exit to pm
                        case 3:
                            break;

                        default:
                            printf("Worng input \n try again \n");
                            break;
                        }
                    } while (choice_search_algo != 3);
                    break;
                } // end of case 2 (searching)

                // sorting algo
                case 3:
                {
                    int sort_algo_arr[RANGE];
                    int n_sort_algo, choice_sort_algo;

                    printf("Enter the size of the array [MAX 7] : ");
                    scanf("%d", &n_sort_algo);

                    printf("Enter %d elements:\n", n_sort_algo);
                    for (int i = 0; i < n_sort_algo; i++)
                    {
                        scanf("%d", &sort_algo_arr[i]);
                    }

                    do
                    {
                        printf("1) Selection Sort \n 2) Bubble Sort \n 3) Insertion Sort \n 4) Quick Sort \n 5) Exit to main menu \n");
                        printf("Enter your choice : ");
                        scanf("%d", &choice_sort_algo);

                        switch (choice_sort_algo)
                        {
                            // selection sort
                        case 1:
                            selectionSort(sort_algo_arr, n_sort_algo);
                            printf("Sorted array using Selection Sort: ");
                            print_sort_Array(sort_algo_arr, n_sort_algo);
                            break;

                        // bubble sort
                        case 2:
                            bubbleSort(sort_algo_arr, n_sort_algo);
                            printf("Sorted array using Bubble Sort: ");
                            print_sort_Array(sort_algo_arr, n_sort_algo);
                            break;

                            // insertion sort
                        case 3:
                            insertionSort(sort_algo_arr, n_sort_algo);
                            printf("Sorted array using Insertion Sort: ");
                            print_sort_Array(sort_algo_arr, n_sort_algo);
                            break;

                            // quick sort
                        case 4:
                            quickSort(sort_algo_arr, 0, n_sort_algo - 1);
                            printf("Sorted array using Quick Sort: ");
                            print_sort_Array(sort_algo_arr, n_sort_algo);
                            break;

                            // exit to pm
                        case 5:
                            break;

                        default:
                            printf("Wrong input \n try again \n");
                            break;
                        }

                    } while (choice_sort_algo != 5);

                    break;
                } // end of case 3 (sorting)

                // exit to pm
                case 4:
                    break;

                default:
                    printf("wrong choice \n try again ! \n");
                    break;
                }
            } while (nlds_choice != 4);
            break;
        }

        // exit program
        case 3:
            printf("exiting...");
            exit(1);

        default:
            printf("wrong input \n try again \n");
            break;
        }
    }
    return 0;
}