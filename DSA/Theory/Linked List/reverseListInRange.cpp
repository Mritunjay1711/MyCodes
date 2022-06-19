#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};



class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node *list = head, *prev;
        n = (n-m+1);
        int x = m;
        while(m - 1){
            prev = list;
            list = list->next;
            m--;
        }
        // cout << prev->data << endl;
        Node *revList = NULL, *tmp = list;
        // cout << n << endl;
        while(n){
            if(revList == NULL){
                revList = new Node(tmp->data);
                tmp = tmp->next;
                n--;
            }
            else{
                Node *newNode = new Node(tmp->data);
                newNode->next = revList;
                revList = newNode;
                tmp = tmp->next;
                n--;
            }
            
        }
        if(x == 1){
            head = revList;
        }
        else
            prev->next = revList;
            
            
        while(revList->next){
            revList = revList->next;
        }
        revList->next = tmp;
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
    cout << "Enter no. of testcases: ";
	cin >> T;

	while (T--)
	{
		int N, m, n;
        cout << "Enter size, start and end index: ";
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;
        cout << "Enter data for list: ";
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends