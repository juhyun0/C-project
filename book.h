#ifndef _BOOK_H_
#define _BOOK_H_

void regbook();//���� ����ü �����͹迭�� ����
void borbook(); //�뿩���� ����ü �����͹迭�� ����
BOOK *regBook();//���� ������ ���� 
BORROW *borBook();//�뿩���� ������ ����
void booklist(); //���� ��� 
void bookdel();//������ �������� 
void bookserrch(); //������ �����˻� 
int srchmenu();//�˻��޴� 
void clist();//ȸ�� ��� 
int listmenu();//ȸ�� ��� �޴� 
void bookrent();//�����뿩 
void bookret();//�����ݳ� 
int reBookisbn();//���� �ߺ� �˻� 
#endif
