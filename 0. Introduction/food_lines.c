#include "stdio.h"

#define MAX_LINES 100

int shortest_line(int lines[], int n) {
    int shortest = 0;
    for (int i=0; i<n; i++) 
        if (lines[i] < lines[shortest]) 
            shortest = i;
    return shortest;
}

void solution(int lines[], int n, int m) {
    int shortest;
    for (int i=0; i<m; i++) {
        shortest = shortest_line(lines, n);
        printf("%d\n", lines[shortest]);
        lines[shortest] += 1;
    }

}

int main() {
    int n, m;
    int lines[MAX_LINES];
    scanf("%d%d", &n, &m); 
    for (int i=0; i<n; i++)
        scanf("%d", &lines[i]);
    solution(lines, n, m);
    return 0;
}