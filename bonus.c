/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:36:58 by msariasl          #+#    #+#             */
/*   Updated: 2022/11/26 06:12:53 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int test_tlist(int *s) // LSTNEW
{
    int i = 0;
    t_list *head = NULL;
    head = (t_list *)malloc(sizeof(t_list));
    if (head == NULL)
        printf("Bellek hatası!\t");
    char *str = "Bu bellek ataması tamamen test amaçlıdır.";
    head->content = str;
    head->next = NULL;
    if (strcmp(head->content, "Bu bellek ataması tamamen test amaçlıdır.") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstnew(int *s) // LSTNEW
{
    int i = 0;
    t_list *mylist = ft_lstnew("Haha. Bu liste bir harika.");
    if (strcmp(mylist->content, "Haha. Bu liste bir harika.") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstaddfront(int *s) // LSTADDFRONT
{
    int i = 0;
    t_list *head = ft_lstnew("Haha. Bu liste bir harika.");
    t_list *l1 = ft_lstnew("Haha. Şimdi en başa veri ekledim.");
    ft_lstadd_front(&head, l1);
    if (strcmp(head->content, "Haha. Şimdi en başa veri ekledim.") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstsize(int *s) // LSTSIZE
{
    int i = 0;
    t_list *l1 = ft_lstnew("Haha. Bu liste bir harika.");
    l1->next = ft_lstnew("Haha. Bu liste bir mükemmel.");
    ft_lstadd_back(&l1, ft_lstnew("Haha. Bu liste bir efsane."));
    int lst_len = ft_lstsize(l1);
    if (lst_len == 3)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstaddback(int *s) // LASTADDBACK
{
    int i = 0;
    t_list *head = ft_lstnew("Haha. Bu liste bir harika.");
    t_list *l1 = ft_lstnew("Haha. Şimdi en başa veri ekledim.");
    ft_lstadd_back(&head, l1);
    if (strcmp(head->next->content, "Haha. Şimdi en başa veri ekledim.") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

int test_lstlast(int *s) // LSTLAST
{
    int i = 0;
    t_list *head = ft_lstnew("Haha. Bu liste bir harika.");
    ft_lstadd_back(&head, ft_lstnew("AAAAA"));
    ft_lstadd_back(&head, ft_lstnew("BBBBB"));
    ft_lstadd_back(&head, ft_lstnew("CCCCC"));
    t_list *last = ft_lstlast(head);
    if (strcmp(last->content, "CCCCC") == 0)
        i++;
    if (i == 1)
        (*s)++;
    return i;
}

ft_del(void *delete)
{
    t_list *node = delete;
    free(node->content);
    free(node);
}


int test_lstdelone(int *s) // DELONE
{
    int i = 0;
   t_list *head = ft_lstnew("Haha. Bu liste bir harika.");
    ft_lstadd_back(&head, ft_lstnew("AAAAA"));
    ft_lstadd_back(&head, ft_lstnew("BBBBB"));
    ft_lstadd_back(&head, ft_lstnew("CCCCC"));

     ft_lstdelone((head), ft_del(head->next));
    
    if (strcmp(head->next->content, "CCCCC") == 0)
        i++;
        
    printf("%s",head->next->content);
        
    if (i == 1)
        (*s)++;
    return i;
}

void TESTAREA() // CASUAL AREA
{
}

void HR()
{
    printf("\n\n#################################\n\n");
}

int main(void)
{
    int s = 0;
    printf("\n\n\n----> B O N U S ___ $ ___ P A R T <-----\n\n");
    HR();
    printf("0.  typdef t_list kontrolü: %d/1", test_tlist(&s));
    HR();
    printf("1.  lstNew başarılı test sayısı: %d/1", test_lstnew(&s));
    HR();
    printf("2.  lstAdd_front başarılı test sayısı: %d/1", test_lstaddfront(&s));
    HR();
    printf("3.  lstSize başarılı test sayısı: %d/1", test_lstsize(&s));
    HR();
    printf("4.  lstAdd_back başarılı test sayısı: %d/1", test_lstaddback(&s));
    HR();
    printf("5.  lstLast başarılı test sayısı: %d/1", test_lstlast(&s));
    HR();
     printf("6.  lstDelone başarılı test sayısı: %d/1", test_lstdelone(&s));
    HR();

    printf("TOPLAM BAŞARILI FONKSIYON SAYISI: %d/6", s);
    HR();
    TESTAREA();
    return 0;
}