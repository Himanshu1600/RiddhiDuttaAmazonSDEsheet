void hashAndRemove(Node * head) {
  unordered_map < Node * , int > node_map;
  Node * last = NULL;
  while (head != NULL) {
    if (node_map.find(head) == node_map.end()) {
      node_map[head]++;
      last = head;
      head = head -> next;
    } else {
      last -> next = NULL;
      break;
    }
  }
}
