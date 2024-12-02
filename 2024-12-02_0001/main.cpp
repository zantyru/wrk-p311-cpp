#include <iostream>


template <class T>
struct ListItem
{
    T data;
    ListItem* p_prev;
    ListItem* p_next;
};


template <class T>
class List
{
public:
    List()
        : _elementCount{ 0 }
        , _p_head{ nullptr }
        , _p_tail{ nullptr }    
    {}

    ~List()
    {
        ListItem<T>* p_current = _p_tail;
        ListItem<T>* p_toDelete = nullptr;

        while (p_current != nullptr)
        {
            p_toDelete = p_current;
            p_current = p_current->p_prev;

            p_toDelete->p_next = nullptr;
            p_toDelete->p_prev = nullptr;

            if (p_current != nullptr)
            {
                p_current->p_next = nullptr;
            }

            delete p_toDelete;
        }

        _p_head = nullptr;
    }

    List(const List& other) = delete;  // ������ ����������� ����� ����������� �����

    List& operator=(const List& other) = delete;  // ������ ����������� ����� ������������

    size_t GetSize() const
    {
        return _elementCount;
    }

    bool PushBack(const T& data)
    {
        ListItem<T>* p_newItem = new ListItem<T>;
        p_newItem->p_prev = _p_tail;
        p_newItem->p_next = nullptr;
        p_newItem->data = data;

        if (_elementCount > 0)
        {
            p_newItem->p_prev->p_next = p_newItem;
        }
        else
        {
            _p_head = p_newItem;
        }

        _p_tail = p_newItem;
        ++_elementCount;

        return true;
    }

    T& operator[](size_t index)
    {
        if (_elementCount == 0) throw std::out_of_range("Index is out of range.");

        if (index > _elementCount - 1) throw std::out_of_range("Index is out of range.");

        ListItem<T>* p_current = _p_head;  // � ����� ������� _p_head �� nullptr
        size_t currentIndex = 0;

        while (currentIndex < index)
        {
            p_current = p_current->p_next;
            ++currentIndex;
        }

        return p_current->data;
    }

    const T& operator[](size_t index) const
    {
        if (_elementCount == 0) throw std::out_of_range("Index is out of range.");

        if (index > _elementCount - 1) throw std::out_of_range("Index is out of range.");

        ListItem<T>* p_current = _p_head;  // � ����� ������� _p_head �� nullptr
        size_t currentIndex = 0;

        while (currentIndex < index)
        {
            p_current = p_current->p_next;
            ++currentIndex;
        }

        return p_current->data;
    }

private:
    size_t _elementCount; // ��� ����� ������
    ListItem<T>* _p_head;  // ������ - ������ ������
    ListItem<T>* _p_tail;  // ����� - ����� ������
};


template <class T>
void PrintList(const List<T>& list)
{
    for (size_t i = 0; i < list.GetSize(); ++i)
    {
        std::cout << list[i] << "  ";
    }

    std::cout << '\n';
}


int main()
{
    List<int> list;

    std::cout << "\n[1] ---------\n";
    PrintList(list);


    std::cout << "\n[2] ---------\n";
    list.PushBack(12);
    PrintList(list);

    std::cout << "\n[3] ---------\n";
    list.PushBack(-6);
    list.PushBack(101);
    PrintList(list);

    return 0;
}