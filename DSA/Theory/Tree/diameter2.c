//time complexity O(n)

#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree*left;
    struct tree*right;
}*root=NULL; 


//creation of new node
struct tree *create(int v,struct tree*l,struct tree*r){
    struct tree *node;
    node=(struct tree*)malloc(sizeof(struct tree));
    node->data=v;
    node->left=l;
    node->right=r;
    return node;
}

int max(int a,int b){
    return a>b?a:b;   
}



int caldiameter(struct tree*root,int *height){

    int lh=0,rh=0;

    int ldiameter=0,rdiametr=0;

    if(root==NULL)
    {
        *height=0;
        return 0;
    }
        
    ldiameter=caldiameter(root->left,&lh);
    rdiametr=caldiameter(root->right,&rh);
    *height=max(lh,rh)+1;
    return max(lh+rh+1,max(ldiameter,rdiametr));


}


int main()
{   /*
          1
         /   
        2  
       / \
      4   5     
     /         
    8             
*/
    //left subtree
    struct tree *ei=create(8,NULL,NULL);
    struct tree*d=create(4,ei,NULL);

    struct tree*e=create(5,NULL,NULL);
    struct tree*b=create(2,d,e);

    //right subtree



    


    //root node
    struct tree*a=create(1,b,NULL);
    root=a;
    int h=0;
    int i=caldiameter(root,&h);
    printf("%d",i);
    return 0;
}