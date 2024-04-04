#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct graph
{
    int numVertices;
    int **vertices;
} Graph;

Graph *initializeGraph(Graph *graph, int numVertices)
{
    graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = (int **)malloc(numVertices * sizeof(int *));
    graph->numVertices = numVertices;
    int i, j;
    for (int i = 0; i < numVertices; i++)
    {
        graph->vertices[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
        {
            graph->vertices[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight)
{
    graph->vertices[src][dest] = weight;
    graph->vertices[dest][src] = weight;
}

void displayGraph(Graph *graph)
{
    int i, j;
    for (i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->vertices[i][j]);
        }
        printf("\n");
    }
}

int isAdjacent(Graph *graph, int vertex1, int vertex2)
{
    if (graph->vertices[vertex1][vertex2 != 0])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getDegree(Graph *graph, int vertex)
{
    int deg = 0;
    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        if (graph->vertices[vertex][i] != 0)
        {
            deg++;
        }
    }
    return deg;
}

void dfs(Graph *graph, int vertex, int *visited)
{
    visited[vertex] = 1;
    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        if (graph->vertices[vertex][i] != 0 && !visited[i])
        {
            dfs(graph, i, visited);
        }
    }
}

int isConnected(Graph *graph)
{
    int visited[MAX_VERTICES];
    int i;
    for (i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0;
    }
    dfs(graph, 0, visited);
    for (i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            return 0;
        }
    }

    return 1;
}

void countComponents(Graph *graph)
{
    int *visited = (int *)malloc(graph->numVertices * sizeof(int));
    if (visited == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int components = 0;
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = 0; // Initialize visited array
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (!visited[i])
        {
            components++;
            printf("Component %d: ", components);
            dfs(graph, i, visited);
            printf("\n");
        }
    }

    printf("Number of connected components: %d\n", components);

    free(visited);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    int numVertices, numEdges;
    fscanf(file, "%d %d", &numVertices, &numEdges);

    Graph *graph = initializeGraph(graph, numVertices);

    int src, dest, weight;
    for (int i = 0; i < numEdges; i++)
    {
        fscanf(file, "%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    fclose(file);
    int x;
    int v1, v2;
    do
    {
        printf("Press 1 to display the graph\n");
        printf("Press 2 to display degree of each vertex\n");
        printf("Press 3 to verify whether graph is connected or not\n");
        printf("Press 4 to display number of components in the Graph and vertices in each component.\n");
        printf("Press 5 to check if one vertex is adjacent to another.\n");
        printf("Press 6 to exit the program.\n");

        scanf("%d", &x);

        switch (x)
        {
        case 1:
            displayGraph(graph);
            break;
        case 2:
            printf("\nDegree of each vertex:\n");
            for (int i = 0; i < graph->numVertices; i++)
            {
                printf("Vertex %d: %d\n", i, getDegree(graph, i));
            }
            break;
        case 3:
            if (isConnected(graph))
            {
                printf("\nThe graph is connected.\n");
            }
            else
            {
                printf("\nThe graph is not connected.\n");
            }
            break;
        case 4:
            countComponents(graph);
            break;
        case 5:
            
            printf("\nEnter two vertices to check if they are adjacent: ");
            scanf("%d %d", &v1, &v2);
            if (isAdjacent(graph, v1, v2))
            {
                printf("%d and %d are adjacent.\n", v1, v2);
            }
            else
            {
                printf("%d and %d are not adjacent.\n", v1, v2);
            }
            break;

        default:
            break;
        }

    } while (x != 6);

    return EXIT_SUCCESS;
}