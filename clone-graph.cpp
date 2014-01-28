/*
Clone Graph Total Accepted: 4648 Total Submissions: 23165 My Submissions
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/

/*
JAN 27 2014
Cloning a graph represented by adjacent list.
stack<UndirectedGraphNode*> nodes;
-- stores nodes to visit in old graph

map<int, UndirectedGraphNode *> table;
-- keeps track of node address for new graph

map<int, bool> visit;
-- keeps track of nodes already pushed into stack, avoid push a node into stack 2nd time

note: self loop, input as 3,4,4
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        int val;
        UndirectedGraphNode *newgraph = NULL, *nptr, *optr, *tmp;
        stack<UndirectedGraphNode*> nodes;
        map<int, UndirectedGraphNode *> table;
        map<int, bool> visit;
        nodes.push(node);
        visit[node->label] = false;
        while(!nodes.empty())
        {
            optr = nodes.top();
            val = optr->label;
            if (!table.count(val))
            {
                nptr = new UndirectedGraphNode(val);
                table[val] = nptr;
                if (!newgraph) newgraph = nptr;
            }
            nptr = table[val];
            nodes.pop();
            for (int i = 0; i< optr->neighbors.size(); i++)
            {
                if (!visit.count(optr->neighbors[i]->label))
                {
                    // prevent e.g. 3,4,4, makes 4 pushed into stack twice
                    visit[optr->neighbors[i]->label] = false;
                    nodes.push(optr->neighbors[i]);
                }
                if (!table.count(optr->neighbors[i]->label))
                {
                    tmp = new UndirectedGraphNode(optr->neighbors[i]->label);
                    table[optr->neighbors[i]->label] = tmp;
                }
                nptr->neighbors.push_back(table[optr->neighbors[i]->label]);
            }
        }
        return newgraph;
    }
};
