#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 50

typedef struct graphnode {
    int vertex;
    struct graphnode* link;
} graphnode;

typedef struct graphtype {
    int n;
    graphnode* adj_list[MAX_VER];
} graphtype;

void init(graphtype* g) {
    int v = 0;
    g->n = 0;
    for (v = 0; v < MAX_VER; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(graphtype* g, int v) {
    if (((g->n) + 1) > MAX_VER) {
        fprintf(stderr, "�׷���: ������ ���� �ʰ� ");
        return;
    }
    g->n++;
}

void insert_edge(graphtype* g, int u, int v) {
    graphnode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, " �׷���: ���� ��ȣ ���� ");
        return;
    }
    node = (graphnode*)malloc(sizeof(graphnode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int count_edges(graphtype* g) {
    int edgeCount = 0;
    for (int i = 0; i < g->n; i++) {
        graphnode* p = g->adj_list[i];
        while (p != NULL) {
            edgeCount++;
            p = p->link;
        }
    }
    printf("������ ����: %d\n", edgeCount / 2);
    return edgeCount / 2;
}

int find_degree(graphtype* g, int n) {
    
    int degree = 0;
    graphnode* p = g->adj_list[n];
    while (p != NULL) {
        degree++;
        p = p->link;
    }
    printf("%d�� ����: %d\n", n, degree);
    return degree;
}

int edge_exist(graphtype* g, int m, int n) {
    
    graphnode* p = g->adj_list[m];
    int checked = 0;
    while (p != NULL) {
        if (p->vertex == n) {
            checked = 1;
        }
        p = p->link;
    }
    if (checked)
        printf("%d �� %d ���̿� ���� ����\n", m, n);
    else
        printf("%d �� %d ���̿� ���� �������� ����\n", m, n);
    return 0;
}

void list_conn_vertex(graphtype* g, int n) {
    
    graphnode* p = g->adj_list[n];
    printf("���� %d�� ����� ��������: ", n);
    while (p != NULL) {
        printf("%d ", p->vertex);
        p = p->link;
    }
    printf("\n");
    
}

void print_adj_list(graphtype* g) {
    for (int i = 0; i < g->n; i++) {
        graphnode* p = g->adj_list[i];
        printf("���� %d�� ��������Ʈ ", i);
        while (p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
} 

int main() {
    graphtype* g;
    g = (graphtype*)malloc(sizeof(graphtype));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 3, 1);
    insert_edge(g, 1, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    print_adj_list(g);
    printf("\n");
    count_edges(g);
    find_degree(g, 1);
    edge_exist(g, 0, 1);
    list_conn_vertex(g, 0);
    free(g);
    return 0;
}