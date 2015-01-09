
void Filly(BSTree tr, int parenty) {
	if (!tr)
		return;
	tr->y = parenty-1;
	if (tr->left)
		Filly(tr->left, tr->y);
	if (tr->right)	
		Filly(tr->right, tr->y);
}

	
