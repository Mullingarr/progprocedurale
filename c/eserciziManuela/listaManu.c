lista seleziona(lista l){

	lista ris;
	ri.next = NULL;
	list *old = lalloc();
	lista *ptrris = lalloc();
	lista *ptrl = lalloc();

	int acc = 0;
	while(ptrl->next != NULL){
		acc+= ptrl->el;
		ptrl = ptrl->next;
	}
	if(ptrl->next == NULL)
		acc+= 0;
	while(ptrl->next != NULL){
		if(ptrl->el > acc){
			ris.el = ptrl->el;
			old + ptrl;
		}
		ptrl = ptrl->next;
	}

}