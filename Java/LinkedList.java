public class LinkedList<T> {

    private Node<T> head;
    private Node<T> last;
    int size = 0;

    public LinkedList() {

    }

    public void add(T data) {
        Node<T> node = new Node<>(data);
        if (size == 0) {
            this.head = node;
            this.last = node;
        } else {
            last.next = node;
            last = last.next;
        }
        size++;
    }


}
