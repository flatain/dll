#include <stdio.h>
#include <stdlib.h>

struct dll{
    int value;
    struct dll *prev;
    struct dll *next;
};

void print_dll(struct dll *head){
    if(head->next == NULL){
        printf("nothing is stored\n");
    }else{
        struct dll *idx = head->next;
        while(1){
            printf("%d ,", idx->value);
            if(idx->next == NULL){
                break;
            }else{
                idx = idx->next;
            }
        }
    }
    printf("\n");
}

void add_elem(struct dll **tail, int value){
    struct dll *p_elem = (struct dll *)malloc(sizeof(struct dll));
    if(p_elem == NULL){
        printf("nothing was added\n");
    }else{
        (*tail)->next = p_elem;
        p_elem->prev = *tail;
        p_elem->next = NULL;
        p_elem->value = value;
        *tail = p_elem;
    }
}

void free_dll(struct dll *head){
    if(head->next == NULL){
        printf("nothing is stored\n");
    }else{
        struct dll *idx = head->next;
        while(1){
            if(idx->next == NULL){
                break;
            }else{
                idx = idx->next;
                free(idx->prev);
            }
        }
    }
}

void del_elem(struct dll *head, struct dll **pptail, int value){
    if(head->next == NULL){
        printf("nothing is stored\n");
    }else{
        struct dll *idx = head->next;
        while(1){
            if(idx->value == value){
                if(idx->next != NULL){
                    idx->prev->next = idx->next;
                    idx->next->prev = idx->prev;
                }else{
                    idx->prev->next = NULL;
                    *pptail = idx->prev;
                }
                free(idx);
                break;
            }else{

            }
            if(idx->next == NULL){
                printf("nothing was deleted\n");
                break;
            }else{
                idx = idx->next;
            }
        }
        printf("\n");
    }
}

int main(void){
    // initialize
    struct dll *vacant_head = (struct dll *)malloc(sizeof(struct dll));
    
    if (vacant_head == NULL){
        return 0;
    }
    vacant_head->value = 0;
    vacant_head->prev  = NULL;
    vacant_head->next  = NULL;

    struct dll *head   = vacant_head;
    struct dll *ptail  = vacant_head;
    struct dll **pptail = &ptail;

    int is_continue = 1;
    int value = 0;

    while(is_continue){
        int operate = 0;
        printf("0 end, 1 add, 2 del, 3 disp\n> ");
        scanf("%d", &operate);

        switch(operate){
            case 0:
                is_continue = 0;
                break;
            case 1:
                printf("add value > ");
                scanf("%d", &value);
                add_elem(pptail, value);
                break;
            case 2:
                printf("del value > ");
                scanf("%d", &value);
                del_elem(head, pptail, value);
                break;
            case 3:
                print_dll(head);
                break;
            default:
                break;
        }
    }

    free_dll(head);

}
