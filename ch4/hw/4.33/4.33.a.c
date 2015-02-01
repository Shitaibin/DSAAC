

void FillX(BSTree tr) {
	static int cursor = 0;	
	if (!tr)
			return;
	if (tr->left)
		FillX(tr->left);
	tr->x = cursor++;
	if (tr->right)
		FillX(tr->right);
}





	
