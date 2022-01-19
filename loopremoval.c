#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct Node
struct Node {
    int ele;
    struct Node *next;
};

//Globals
struct Node *head_list = NULL;

void insertNode(struct Node **list, int val)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL){
        return;
    }
    temp->ele = val;
    temp->next = NULL;

    // empty list
    if (*list == NULL) {
        *list = temp;
    } else {
        struct Node *cur = *list;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }
    return;
}

void printList(struct Node **list) {
    struct Node *temp = *list;
    int cnt = 0;

    printf("\n Printing List");
    while (temp != NULL) {
        printf("\t ele :: %d ", temp->ele);
        temp = temp->next;
        cnt++;

        if (cnt > 6)
            break;
    }
    printf("\n");
}

struct Node *lst_node = NULL;

int findLoop(struct Node **list) {
    struct Node *s_ptr = *list;
    struct Node *f_ptr = *list;
    int count = 0;

    if (s_ptr == NULL)
        return 0;

    while ( s_ptr != NULL && f_ptr != NULL && f_ptr->next != NULL ){
        printf("\n sptr ele :: %d  fptr ele :: %d", s_ptr->ele, f_ptr->ele);
        f_ptr = f_ptr->next->next;
        s_ptr = s_ptr->next;
        count++;
        if (s_ptr == f_ptr) {
            lst_node = s_ptr;
            printf("\n ele: %d ", s_ptr->ele);
            return 1;
        }
    }

    printf("\n no of nodes : %d ", count);
    //no loop
    return 0;
}

void removeLoop(struct Node **list) {
    struct Node *trvsl = *list;

    struct Node *p1 = lst_node;
    struct Node *p2 = lst_node;

    int cnt = 1;
    while (p1->next != p2){
        p1 = p1->next;
        cnt++;
    }
    printf("\n cnt : %d", cnt);
#if 0
    p1 = *list;
    p2 = *list;
    int i = 0;
    while( i < cnt){
        p2 = p2->next;
        i++;
    }
    printf("\n ele : %d %d", p1->ele, p2->ele);
#endif

    p1 = *list;
    p2 = lst_node;

    //meet at the starting point
    while(p1 != p2){
       printf("\n meeting pt ele : %d %d", p1->ele, p2->ele);

        p1 = p1->next;
        p2 = p2->next;
    }

    printf("\n meeting pt done ele : %d %d", p1->ele, p2->ele);

    while(p2->next != p1){
        p2 = p2->next;
    }

    printf("\n found last element ele : %d %d", p1->ele, p2->ele);

    p2->next = NULL;

}

int main()
{
    printf("\n In Main ");
    printList(&head_list);
    insertNode(&head_list, 12);
    insertNode(&head_list, 10);
    insertNode(&head_list, 13);
    insertNode(&head_list, 14);
    insertNode(&head_list, 15);
    printList(&head_list);

    #if 0
    printf("\n loop detected : %d", findLoop(&head_list));

    printf("\n curr ele is %d", head_list->next->next->next->next->ele);
    head_list->next->next->next->next->next = head_list;
    printf("\n loop detected : %d", findLoop(&head_list));

    printList(&head_list);

    removeLoop(&head_list);

    printList(&head_list);

      printf("\n curr ele is %d", head_list->next->next->next->next->ele);
      head_list->next->next->next->next->next = head_list->next;
      printf("\n loop detected : %d", findLoop(&head_list));

      printList(&head_list);
      removeLoop(&head_list);
      printList(&head_list);
#endif
      printf("\n curr ele is %d", head_list->next->next->next->next->ele);
      head_list->next->next->next->next->next = head_list->next->next->next;
      printf("\n loop detected : %d", findLoop(&head_list));

      printList(&head_list);
      removeLoop(&head_list);
      printList(&head_list);


      printf("\n curr ele is %d", head_list->next->next->next->next->ele);
      head_list->next->next->next->next->next = head_list->next->next;
      printf("\n loop detected : %d", findLoop(&head_list));

      printList(&head_list);
      removeLoop(&head_list);
      printList(&head_list);





}
