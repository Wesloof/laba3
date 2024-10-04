#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct node
{
	char inf[256];  // полезная информация
	struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний элементы списка
int dlinna = 0;

// Функции добавления элемента, просмотра списка
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // функция нахождения элемента
struct node* get_struct(void); // функция создания элемента



struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		cout << "Ошибка при распределении памяти\n";
		exit(1);
	}

	cout << "Введите название объекта: \n";   // вводим данные
	cin >> s;
	if (*s == 0)
	{
		cout << "Запись не была произведена\n";
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

/* Последовательное добавление в список элемента (в конец)*/
void spstore(void)
{
	struct node* p = NULL;
	//struct node* save;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		p->next = head;
		head = p;
	}

	
	return;
}


/* Просмотр содержимого списка. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "Список пуст\n";
	}
	while (struc)
	{
		cout << "Имя - "<< struc->inf << endl;
		struc = struc->next;
	}
	return;
}




/* Поиск элемента по содержимому. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "Список пуст\n";
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	cout << "Элемент не найден\n";
	return NULL;
}

/* Удаление элемента по содержимому. */
void del()
{
	struct node* struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node* prev;// указатель на предшествующий удаляемому элемент
	//int flag = 0;       индикатор отсутствия удаляемого элемента в списке

	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		cout << "Список пуст\n";
		return;
	}
	while (struc->next->next != NULL)
	{
		struc = struc->next;
	}
	prev = struc;
	struc = struc->next;
	prev->next = struc->next; // меняем указатели
	free(struc);		    // удаляем  элемент
	struc = prev->next;
	return;
}


int main() {
	setlocale(LC_ALL, "rus");
	spstore();
	spstore();
	spstore();
	review();
	del();
	review();

}
