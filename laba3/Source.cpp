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
void del(char* name)
{
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev;// ��������� �� �������������� ���������� �������
	int flag = 0;      // ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		cout << "������ ����\n";
		return;
	}

	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1;         // ���������� ���������
			if (struc->next)  // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc);		    // �������  �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else			// ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc);	// �������  �������
				return;
			}
		}
		else 
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0)				// ���� ���� = 0, ������ ������ ������� �� ������
	{
		cout << "������� �� ������\n";
		return;
	}


}
