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
	//struct node* save;
	p = get_struct();
	if (head == NULL && p != NULL)	// ���� ������ ���, �� ������������� ������ ������
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
	{
		p->next = head;
		head = p;
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
		cout << "��� - "<< struc->inf << endl;
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
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev;// ��������� �� �������������� ���������� �������
	//int flag = 0;       ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		cout << "������ ����\n";
		return;
	}
	while (struc->next->next != NULL)
	{
		struc = struc->next;
	}
	prev = struc;
	struc = struc->next;
	prev->next = struc->next; // ������ ���������
	free(struc);		    // �������  �������
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
