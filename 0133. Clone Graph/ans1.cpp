/* time cost: 27ms (99.75%) */
/* time complexity: O(n)    */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        queue<UndirectedGraphNode*> node_queue;
        UndirectedGraphNode* clone_node = new UndirectedGraphNode(node->label);
        node_map[node] = clone_node;
        node_queue.push(node);
        while(!node_queue.empty()) {
            UndirectedGraphNode* tmp_node = node_queue.front();
            node_queue.pop();
            for (UndirectedGraphNode* nbr_node : tmp_node->neighbors) {
                if (node_map.find(nbr_node) == node_map.end()) {
                    node_map[nbr_node] = new UndirectedGraphNode(nbr_node->label);
                    node_queue.push(nbr_node);
                }
                node_map[tmp_node]->neighbors.push_back(node_map[nbr_node]);
            }
        }
        return clone_node;
    }
};

//// DFS
// class Solution {
// public:
//     UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//         if (!node) return NULL;
//         if (mp.find(node) == mp.end()) {
//             mp[node] = new UndirectedGraphNode(node -> label);
//             for (UndirectedGraphNode* neigh : node -> neighbors)
//                 mp[node] -> neighbors.push_back(cloneGraph(neigh));
//         }
//         return mp[node];
//     } 
// private:
//     unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
// };
