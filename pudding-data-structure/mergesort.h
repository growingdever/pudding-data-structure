
void swap( int& a, int& b )
{
	int tmp = a;
	a = b;
	b = tmp;
}

void merge( int arr[], int start, int end )
{
	int* tmp = new int[end - start + 1];
	int i, cnt = 0;

	for( i=start; i<=end; i++ )
		tmp[cnt++] = arr[i];

}

void mergesort( int arr[], int start, int end )
{
	if( start >= end )
		return ;

	int mid = (start + end) / 2; // floor

	mergesort( arr, start, mid );
	mergesort( arr, mid+1, end );
	merge( arr, start, end );
}