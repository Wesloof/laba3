#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

struct node
{
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� ������� 
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;

// ������� ���������� ��������, ��������� ������
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������



struct node* get_struct(void)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // �������� ������ ��� ����� ������� ������
	{
		cout << "������ ��� ������������� ������\n";
		exit(1);
	}

	cout << "������� �������� �������: \n";   // ������ ������
	cin >> s;
	if (*s == 0)
	{
		cout << "������ �� ���� �����������\n";
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� �����)*/
void spstore(void)
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
	{
		last->next = p;
		last = p;
	}
	return;
}



/* �������� ����������� ������. */
void review(void)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "������ ����\n";
	}
	while (struc)
	{
		cout << "��� - " << struc->inf << endl;
		struc = struc->next;
	}
	return;
}




/* ����� �������� �� �����������. */
struct node* find(char* name)
{
	struct node* struc = head;
	if (head == NULL)
	{
		cout << "������ ����\n";
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			return struc;
		}
		struc = struc->next;
	}
	cout << "������� �� ������\n";
	return NULL;
}

/* �������� �������� �� �����������. */
void del()
{

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		cout << "������ ����\n";
		return;
	}

	struct node* ptr = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* ptrnext = head->next;// ��������� �� ���������


	if (ptrnext == NULL) {
		delete head;
		head = nullptr;
		return;
	}

	while (ptrnext->next != NULL)
	{
		ptrnext = ptrnext->next;
		ptr = ptr->next;
	}

	delete ptr->next;
	ptr->next = NULL;
	last = ptr;
}


int main() {
	setlocale(LC_ALL, "rus");
	spstore();
	spstore();
	spstore();
	review();
	del();
	cout << "-----------" << endl;
	review();
	cout << "-----------" << endl;
	spstore();
	getchar();
	review();

}
