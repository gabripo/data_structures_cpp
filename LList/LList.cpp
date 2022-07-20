#include "LList.h"

template<typename T>
LList<T>::LList(int size)
{
    init();
}

template<typename T>
LList<T>::~LList()
{
    removeall();
}

template<typename T>
void LList<T>::init()
{
    curr = new Link<T>;
    tail = new Link<T>;
    head = new Link<T>;
    cnt = 0;
}

// Theta(n) time
template<typename T>
void LList<T>::removeall()
{
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

// Theta(n) time
template<typename T>
void LList<T>::print() const
{
    std::cout << "Printing list: { ";
    Link<T>* linkTempNode = head->next;
    int i = 0;
    while ((linkTempNode != tail->next) && (i < cnt))
    {
        std::cout << linkTempNode->element << " ";
        linkTempNode = linkTempNode->next;
    }
    std::cout << " }" << std::endl;
}

template<typename T>
void LList<T>::clear()
{
    removeall();
    init();
}

// Theta(1) time
template<typename T>
void LList<T>::insert(const T& elementToInsert)
{
    curr->next = new Link<T>(elementToInsert, curr->next);
    if (tail == curr)
    {
        tail = curr->next;
    }
    cnt++;
}

// Theta(1) time
template<typename T>
void LList<T>::append(const T& elementToAppend)
{
    tail->next = new Link<T>(elementToAppend, NULL);
    tail = tail->next;
    cnt++;
}

// Theta(1) time
template<typename T>
T LList<T>::remove()
{
    if (curr->next != NULL)
    {
        T elementToReturn = curr->next->element;
        Link<T>* linkTempNode = curr->next;
        if (tail == curr->next)
        {
            tail = curr;
        }
        curr->next = curr->next->next;
        delete linkTempNode;
        cnt--;
        return elementToReturn;
    }
    else
    {
        return (T)0;
    }
}

// Theta(1) time
template<typename T>
void LList<T>::moveToStart()
{
    curr = head;
}

// Theta(1) time
template<typename T>
void LList<T>::moveToEnd()
{
    curr = tail;
}

// Theta(n) time
template<typename T>
void LList<T>::prev()
{
    if (curr == head)
    {
        return;
    }
    Link<T>* tempLink = head;
    while (tempLink->next != curr)
    {
        tempLink = tempLink->next;
    }
    curr = tempLink;
}

// Theta(1) time
template<typename T>
void LList<T>::next()
{
    if (curr != tail)
    {
        curr = curr->next;
    }
}

// Theta(1) time
template<typename T>
int LList<T>::length() const
{
    return cnt;
}

// Theta(n) time
template<typename T>
int LList<T>::currentPos() const
{
    Link<T>* tempLink = head;
    int position;
    while (curr != tempLink)
    {
        tempLink = tempLink->next;
    }
    return position;
}

// Theta(i) time, with i positions from the head of the list
template<typename T>
void LList<T>::moveToPos(int pos)
{
    if ((pos >= 0) && (pos <= cnt))
    {
        curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->next;
        }
    }   
}

// Theta(1) time
template<typename T>
const T& LList<T>::getValue() const
{
    if (curr->next != NULL)
    {
        return curr->next->element;
    }
    else
    {
        return (T)0;
    }
}