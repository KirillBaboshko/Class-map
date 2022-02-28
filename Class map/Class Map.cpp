#include <iostream>
#include <map>
#include <vector>
using namespace std;

//Библиотека map
// 
//Класс map поддерживает поддерживает ассоциативный
//контейнер, в котором уникальным ключам соответствуют определённые значения.Спецификация его шаблона
//имеет следующий вид :
// 
//template <class Key, class T, class Comp = less<key>,
//	class Allocator = Allocator<pair<const key, T>>>
//	class map
// 
//	Здесь key — тип данных ключей, T — тип сохраняемых
//	(отображаемых)значений, а Comp — функция, которая
//	сравнивает два ключа.Класс map имеет следующие
//	конструкторы :
// 
//explicit map(const Comp& cmpfn = Comp(),
//	Allocator& a = Allocator());
// 
//map(map<Key, T, Comp, Allocator>& ob);
// 
//template < class InIter> map(InIter start,
//	InIter end, const Comp& cmpfn = Comp(),
// 
//	const Allocator& a = Allocator());
// 
//Первая форма конструктора создает пустое отображение.
//Вторая создает отображение, которое содержит те же эле -
//менты, что и отображение ob.Третья создает отображение,
//которое содержит элементы в диапазоне, заданном пара -
//метрами start и end.Функция, заданная параметром cmpfn
//(и если она задана), определяет упорядочение отображения.
// 
//Для класса map определены следующие операторы
//сравнения :
//■■ ==
//■■ <
//	■■ <=
//	■■ !=
//	■■ >
//	■■ >=
//	Класс map содержит перечисленные ниже функции - члены.В приведенных описаниях элемент key_type
//	представляет тип ключа, а элемент value_type — пару
//	элементов pair<Key, T>.
//	iterator begin();
//const_iterator begin() const; Возвращает итератор для первого элемента в отображении.
// 
//void clear();Удаляет все элементы из отображения.
// 
//size_type count(const key_type& k) const;Возвращает число вхождений ключа k в отображении(1 или 0).
//size_type count(const key_type& k) const;
//Возвращает значение true, если данное отображение пустое, и false в противном случае.
// 
//const_iterator end() const;
//iterator end();
//Возвращает итератор, указывающий на конец ото -
//бражения.
// 
//pair<iterator, iterator> equal_range(const key_type & k);
//pair<const_iterator, const_iterator>
// 
//equal_range(const key_type& k) const;
//Возвращает пару итераторов, которые указывают
//на первый и последний элементы в отображении, содержащие заданный ключ.
// 
//void erase(iterator i);
//Удаляет элемент, адресуемый итератором i.
//void erase(iterator start, iterator end);
//Удаляет элементы в диапазоне, задаваемом параметрами start и end.
//size_type erase(const key_type& k);
//Удаляет из отображения элементы, ключи которых
//имеют значение k.
// 
//iterator find(const key_type& k);
//const_iterator find(const key_type& k) const;
//Возвращает итератор для заданного ключа.Если ключ
//не обнаружен, возвращает итератор до конца отображения.
// 
// 
//allocator_type get_allocator() const;
//Возвращает распределитель отображения.
// 
//iterator insert(iterator i, const value_type& val);
//Вставляет значение val после элемента, заданным ите -
//ратором i, возвращает итератор для этого элемента.
// 
//template <class InIter> void insert(InIter start,
//	InIter end);
// 
//Вставляет элементы заданного диапазона.
//pair<iterator, bool> insert(const value_type& val);
//Вставляет значение val в используемое отображение.
//Возвращает итератор для данного отображения.Элемент
//вставляет только в том случае, если его еще нет в отображении.Если элемент был вставлен возвращает пару
//pair<iterator, true>, в противном случае pair<iterator, false>.
//key_compare key_comp() const;
// 
//Возвращает объект - функцию, которая сравнивает
//ключи.
// 
//iterator lower_bound(const key_type& k);
//const_iterator lower_bound(const key_type& k) const;
//Возвращает итератор для первого элемента в отображении, ключ которого равен значению k или больше
//этого значения.
// 
//size_type max_size() const;
//Возвращает максимальное число элементов, которое
//может содержать отображение.
// 
//reference operator[](const key_type& i);
//Возвращает ссылку на элемент, заданный параметром i.Если этого элемента не существует, вставляет его
//в отображение.
// 
//reverse_iterator rbegin();
//const_reverse_iterator rbegin() const;
//Возвращает реверсивный итератор для конца отображения.
// 
//reverse_iterator rend();
//const_reverse_iterator rend() const;
//Возвращает реверсивный итератор для начала отображения.
// 
//size_type size() const;
//Возвращает текущее количество элементов в отображении.
// 
//void swap(map<Key, T, Comp, Allocator>& ob);
//Выполняет обмен элементами данного отображения
//и отображения ob.
// 
//iterator upper_bound(const key_type& k);
//const_iterator upper_bound(const key_type& k) const;
//Возвращает итератор для первого элемента в ото -
//бражении, ключ которого больше заданного значения k.
// 
//value_compare value_comp() const;
//Возвращает объект - функцию, которая сравнивает
//значения.
// 
//Этот класс предназначен для быстрого поиска значения
//по ключу.В качестве ключа может быть использовано все,
//что угодно, но при этом необходимо помнить, что главной
//особенностью ключа является возможность применить
//к нему операцию сравнения.Быстрый поиск значения
//по ключу осуществляется благодаря тому, что пары хранятся
//в отсортированном виде.Этот класс имеет недостаток —
//скорость вставки новой пары обратно пропорциональна
//количеству элементов, сохраненных в классе.Еще один
//важный момент — ключ должен быть уникальным.
void main() 
{
	map<int, int> our_map;
	vector<int> our_vector;
	cout << "\n\nmax size of vector-->" << our_vector.max_size() / sizeof(int);
	cout << "\n\nmax size of map-->" << our_map.max_size() / sizeof(int);
	cout << "\n\n --------------------------";
	int val;
	int key;
	cout << "\nInput value: ";
	cin >> val;
	cout<< "\nInput key: ";
	cin >> key;


	pair<int, int>element(key, val);
	our_map.insert(element);
	cout << "\nCurrent element of map-->" << our_map.size() << endl;
	cout << "\n\n --------------------------";
	cout << "\nInput value: ";
	cin >> val;
	cout << "\nInput key: ";
	cin >> key;
	pair<map<int, int>::iterator, bool> err = our_map.insert(make_pair(key, val));
	if (err.second == false)
	{
		cout << "\nERRORR\n";
	}
	cout << "\nCurrent element of map -->" << our_map.size() << endl;
	map<int, int>::iterator iter = our_map.begin();
	for (; iter != our_map.end(); iter++)
	{
		cout << "\nKey --> " << iter->first << "\tValue-->" << iter->second;
	}
	cout << "\n\n --------------------------";
}
