class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def create_node(self, data):
        return Node(data)

    def add_front(self, data):
        new_node = self.create_node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    def add_back(self, data):
        new_node = self.create_node(data)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node

    def delete_node(self, data):
        current = self.head
        previous = None

        while current is not None and current.data != data:
            previous = current
            current = current.next

        if current is None:
            print(f"Node with data {data} not found.")
            return

        if previous is None:
            self.head = current.next
        else:
            previous.next = current.next

        if current == self.tail:
            self.tail = previous

        del current

    def print_list(self):
        current = self.head
        while current is not None:
            print(f"{current.data} -> ", end="")
            current = current.next
        print("NULL")


if __name__ == "__main__":
    ll = LinkedList()

    ll.add_back(10)
    ll.add_back(20)
    ll.add_front(5)
    ll.add_front(1)
    ll.print_list()  # 1 -> 5 -> 10 -> 20 -> NULL

    ll.delete_node(10)
    ll.print_list()  # 1 -> 5 -> 20 -> NULL

    ll.delete_node(1)
    ll.print_list()  # 5 -> 20 -> NULL
