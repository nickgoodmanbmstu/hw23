#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
int main(void) {


	int N;

	int i, j;

	int c = 0;

	int d = 0;

	
	printf("Enter the size of your matrix: ");
	scanf("%d", &N);
	
	int** A = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
		A[i] = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	FILE* s;
	s = fopen("hw.gv", "w");
	fprintf(s, "graph G {\n");

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				while (A[i][j] >= 1) {
					fprintf(s, "%d--%d\n", i + 1, j + 1);
					if (A[i][j] > 1)
					{
						c++;
					}
					if (A[i][i]>0)
						c++;
					

					A[i][j]--;
					d++;
					A[j][i] = 0;
					

				}
			

			}
		}
	fprintf(s, "}");

	fclose(s);
	for (int i = 0; i < N; i++) {

		free(A[i]);
	}
	free(A);
	system("dot -Tpng hw.gv -o graph.png");
	system("graph.png");
	/*printf("%d", c);
	printf("%d", d);
	printf("%d", N);*/
	if ((c == 0) && (d == N))

		printf("The graph is a simple cycle");

	else

		printf("The graph is not a simple cycle");
	

	return 0;
}
