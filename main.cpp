// Roberto Herrera
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

class Node {
 public:
  Node(std::string name) : name(name) {}
  std::string name;
  // a vector of all the outgoing connections to other nodes.
  std::vector<Node*> children;

  bool operator<(const Node& node) const noexcept {
    return this->name < node.name;
  }
};

int main() {
  // TODO: implement!
  // a map holding all the nodes by their name.
  std::map<std::string, Node> graph;

  int n;
  std::cin >> n;
  std::string name;

  // O(n)
  for (int i = 0; i < n; i++) {
    std::cin >> name;
    Node node(name);
    graph.insert({name, node});
  }

  int m;
  std::cin >> m;

  // O(n)
  for (int i = 0; i < m; i++) {
    std::string from, to;
    std::cin >> from >> to;
    Node* to_node;
    to_node = &graph.find(to)->second;
    graph.find(from)->second.children.push_back(to_node);
  }

  std::string start;
  std::cin >> start;
  std::queue<Node> queue;
  std::set<Node> visited;
  Node node = graph.find(start)->second;
  queue.push(node);

  // O(N+E) N are nodes and E are edges
  while (true) {
    // insert all of the children of queue.front in queue
    for (int i = 0; i < queue.front().children.size(); i++) {
      if (visited.find(*queue.front().children[i]) == visited.end()) {
        queue.push(*queue.front().children[i]);
      }
    }
    // print if not visited
    if (visited.find(queue.front()) == visited.end()) {
      std::cout << queue.front().name << std::endl;
    }
    // insert visited node into set
    visited.insert(queue.front());
    queue.pop();

    if (queue.empty()) {
      break;
    }
  }
}