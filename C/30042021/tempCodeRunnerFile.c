void print(struct node *p)
{
    while(p)
    {
        printf("%d ---->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return;
}