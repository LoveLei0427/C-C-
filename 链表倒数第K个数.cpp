//15�����������еĵ�����K�����
//
Node* Print_reciprocal_Kth_Node(Node* head, int k)
{
	if(head==nullptr){
		return nullptr;
	}
	int count = k;
	Node* fast = head;
	Node* slow = head;
	while(fast){
		count++;
		if(count <= k){
			fast = fast->next;
		}else{
			slow = slow->next;
			fast = fast->next;
		}
	}
	if(slow==nullptr){
		printf("No such Node!");
		return;
	}
}