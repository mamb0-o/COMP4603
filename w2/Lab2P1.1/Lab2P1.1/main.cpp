template<typename T>
void LinkedList<T>::add(int index, T element)
{
if (index == 0)
addFirst(element);
else if (index >= size)
addLast(element);
else
{
Node<T>* current = head;
for (int i = 1; i < index; i++)
current = current->next;
Node<T>* temp = current->next;
current->next = new Node<T>(element);
(current->next)->next = temp;
size++;
}
}
