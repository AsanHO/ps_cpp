#include <iostream>
#include <vector>

using namespace std;
class Vertex {
   public:
    int value = -1;
    bool isVisited = false;
    vector<Vertex*> out_neighbors;
    int hackingCount = 0;

    Vertex(int num) { value = num; }
};

class Graph {
   public:
    vector<Vertex*> vertices;
    int maxHackingCount = 0;
    Graph(int count) {
        for (int i = 1; i <= count; i++) {
            vertices.resize(count + 1);
            vertices[i] = new Vertex(i);
        }
    }
    void AddDiEdge(int v, int w)  // 단방향 간선
    {
        vertices[w]->out_neighbors.push_back(vertices[v]);
    }
    int DFS(int num) {
        int result = 0;
        Vertex* v = vertices[num];
        v->isVisited = true;
        // cout << v->value << "방문처리" << endl;
        for (Vertex* out : v->out_neighbors) {
            if (!out->isVisited) {
                result += DFS(out->value);
                result++;
            }
        }
        return result;
    }
    void clearVisted() {
        for (Vertex* v : vertices)
            if (v) v->isVisited = false;
    }
    void allDFS() {
        for (Vertex* v : vertices) {
            if (v) {
                v->hackingCount = DFS(v->value);
                if (v->hackingCount > maxHackingCount) maxHackingCount = v->hackingCount;
                clearVisted();
                // cout << v->value << " : " << v->hackingCount << endl;
            }
        }
        for (Vertex* v : vertices) {
            if (v) {
                if (v->hackingCount == maxHackingCount) {
                    cout << v->value << " ";
                }
            }
        }
    }
};
int N, M;
int main() {
    cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        graph.AddDiEdge(v, w);
    }
    // cout << graph.DFS(5) << endl;
    graph.allDFS();
    return 0;
}