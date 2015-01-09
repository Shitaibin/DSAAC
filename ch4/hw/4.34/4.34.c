
/**
 * It use in order traversal, and the thinking of exercise 4.33.
 * when I filled x and y, it will draw a line here. and then
 * draw a line with the former point.
 *
 * *This function has not been tested*, the key reason is Circle and
 * DrawLine has not been implemeted.
 *
 * T(N) = O(N).
 */ 


void FillxyAndDrawGraph(BSTree tr, int parenty) {
	static int cursor = 0;
	if (!tr)
		return;

	tr->y = parenty - 1;
	if (tr->left)
		Fillxy(tr->left, tr->y);

	tr->x = cursor;
	Cicle(tr->x, tr->y);
	if (cursor != 0)
		DrawLine(cursor-1, cursor);
	cursor++;

	if (tr->right)
		Fillxy(tr->right, tr->y);
}

